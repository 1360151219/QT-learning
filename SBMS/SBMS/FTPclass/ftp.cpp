#include "ftp.h"
#include "ui_ftp.h"


#include <QMessageBox>

FTP::FTP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FTP)
{
    ui->setupUi(this);
    this -> ui -> label_status -> setText("Please enter the name of an FTP server.");

    this -> ui -> treeWidget_fileList -> setEnabled(false);
    this -> ui -> treeWidget_fileList -> setRootIsDecorated(false);
    this -> ui -> treeWidget_fileList -> setHeaderLabels(QStringList() << tr("Name") << tr("Size") << tr("Owner") << tr("Group") << tr("Time"));
    this -> ui -> treeWidget_fileList -> header() ->setStretchLastSection(false);

    this -> ui ->pushButton_cdToParent -> setIcon(QPixmap(":/images/images/cdtoparent.png"));
    this -> ui ->pushButton_cdToParent -> setEnabled(false);

    this -> ui ->pushButton_download -> setEnabled(false);

    connect(ui->treeWidget_fileList, &QTreeWidget::itemActivated,this, &FTP::processItem);
    connect(ui->treeWidget_fileList, &QTreeWidget::currentItemChanged,this, &FTP::enableDownloadButton);
    connect(ui->pushButton_connect, &QPushButton::clicked, this, &FTP::connectOrDisconnect);
    connect(ui->pushButton_cdToParent, &QPushButton::clicked, this, &FTP::cdToParent);
    connect(ui->pushButton_download, &QPushButton::clicked, this, &FTP::downloadFile);

    setWindowTitle("FTP");
}

FTP::~FTP()
{
    delete ui;
}

void FTP::connectOrDisconnect()
{
    if (ftp) {
        ftp -> abort();
        ftp -> deleteLater();
        ftp = nullptr;

        this -> ui -> treeWidget_fileList -> clear();
        this -> ui -> treeWidget_fileList -> setEnabled(false);
        this -> ui ->pushButton_cdToParent -> setEnabled(false);
        this -> ui ->pushButton_download -> setEnabled(false);
        this -> ui ->pushButton_connect -> setEnabled(true);
        this -> ui ->pushButton_connect -> setText(tr("Connect"));

        this -> ui -> label_status -> setText("Please enter the name of an FTP server.");
        return;
    }

    connectToFtp();
}


void FTP::connectToFtp()
{
    ftp = new QFtp(this);
    connect(ftp, &QFtp::commandFinished,this, &FTP::ftpCommandFinished);
    connect(ftp, &QFtp::listInfo,this, &FTP::addToList);
    connect(ftp, &QFtp::dataTransferProgress,this, &FTP::updateDataTransferProgress);

    this -> ui -> treeWidget_fileList ->clear();
    currentPath.clear();
    isDirectory.clear();

    QString ftpServer = this->ui->lineEdit_ftpServer->text();
    ftp -> connectToHost(ftpServer,21);
    ftp -> login("pi","raspberry");

    this -> ui -> label_status ->setText(tr("Connecting to FTP server %1...").arg(this->ui->lineEdit_ftpServer->text()));
}

void FTP::downloadFile()
{
    QString fileName = this -> ui -> treeWidget_fileList->currentItem()->text(0);

    if (QFile::exists(fileName)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("There already exists a file called %1 in "
                                    "the current directory.")
                                 .arg(fileName));
        return;
    }

    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("FTP"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(fileName).arg(file->errorString()));
        delete file;
        return;
    }

    ftp->get(this -> ui -> treeWidget_fileList->currentItem()->text(0), file);
}

void FTP::cancelDownload()
{
    ftp->abort();

    if (file->exists()) {
        file->close();
        file->remove();
    }
    delete file;
}


void FTP::ftpCommandFinished(int, bool error)
{

    if (ftp->currentCommand() == QFtp::ConnectToHost)
    {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to connect to the FTP server "
                                        "at %1. Please check that the host "
                                        "name is correct.")
                                     .arg(this->ui->lineEdit_ftpServer->text()));
            connectOrDisconnect();
            return;
        }
        else {
            this -> ui -> label_status -> setText(tr("Logged onto %1.").arg(this->ui->lineEdit_ftpServer->text()));
            this -> ui -> treeWidget_fileList-> setFocus();
            this -> ui -> pushButton_download->setDefault(true);
            this -> ui -> pushButton_connect-> setText("Disconnect");
            return;
        }
    }

    if (ftp->currentCommand() == QFtp::Login)
        ftp->list();

    if (ftp->currentCommand() == QFtp::Get) {
        if (error) {
            this->ui->label_status->setText(tr("Canceled download of %1.")
                                 .arg(file->fileName()));
            file->close();
            file->remove();
        } else {
            this->ui->label_status->setText(tr("Downloaded %1 to current directory.")
                                 .arg(file->fileName()));
            this -> ui -> progressBar -> setValue(100);
            file->close();
        }
        delete file;
        enableDownloadButton();

    } else if (ftp->currentCommand() == QFtp::List) {
        if (isDirectory.isEmpty()) {
            this -> ui -> treeWidget_fileList -> addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
            this -> ui -> treeWidget_fileList -> setEnabled(false);
        }
    }
}

void FTP::addToList(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.owner());
    item->setText(3, urlInfo.group());
    item->setText(4, urlInfo.lastModified().toString("MMM dd yyyy"));

    QPixmap pixmap(urlInfo.isDir() ? ":/images/images/dir.png" : ":/images/images/file.png");
    item->setIcon(0, pixmap);

    isDirectory[urlInfo.name()] = urlInfo.isDir();
    this -> ui -> treeWidget_fileList->addTopLevelItem(item);
    if (!this -> ui -> treeWidget_fileList->currentItem()) {
        this -> ui -> treeWidget_fileList->setCurrentItem(this -> ui -> treeWidget_fileList->topLevelItem(0));
        this -> ui -> treeWidget_fileList->setEnabled(true);
    }
}

void FTP::processItem(QTreeWidgetItem *item, int /*column*/)
{
    QString name = item->text(0);
    if (isDirectory.value(name)) {
        this -> ui -> treeWidget_fileList->clear();
        isDirectory.clear();
        currentPath += '/';
        currentPath += name;
        ftp->cd(name);
        ftp->list();
        this-> ui -> pushButton_cdToParent->setEnabled(true);

        return;
    }
}

void FTP::cdToParent()
{

    this -> ui -> treeWidget_fileList -> clear();
    isDirectory.clear();
    currentPath = currentPath.left(currentPath.lastIndexOf('/'));
    if (currentPath.isEmpty()) {
        this-> ui -> pushButton_cdToParent ->setEnabled(false);
        ftp->cd("/");
    } else {
        ftp->cd(currentPath);
    }
    ftp->list();
}


void FTP::updateDataTransferProgress(qint64 readBytes,qint64 totalBytes)
{
    this -> ui -> progressBar -> setValue(static_cast<int>(readBytes/totalBytes));
   if(this->ui->progressBar->value()==1)
   {
      QMessageBox::about(this,"下载情况","Download Completed");
       this->ui->progressBar->setValue(0);
   }
}

void FTP::enableDownloadButton()
{
    QTreeWidgetItem *current = this -> ui -> treeWidget_fileList->currentItem();
    if (current) {
        QString currentFile = current->text(0);
        this->ui->pushButton_download->setEnabled(!isDirectory.value(currentFile));
    } else {
        this->ui->pushButton_download->setEnabled(false);
    }
}



