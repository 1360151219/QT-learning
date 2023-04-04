#ifndef FTP_H
#define FTP_H

#include <QWidget>
#include <QUrl>
#include <QFtp>
#include <QTreeWidgetItem>
#include <QFile>
namespace Ui {
class FTP;
}

class FTP : public QWidget
{
    Q_OBJECT

public:
    explicit FTP(QWidget *parent = nullptr);
    ~FTP();

private:
    Ui::FTP *ui;

private slots:

    void downloadFile();
    void cancelDownload();
    void connectToFtp();

    void ftpCommandFinished(int commandId, bool error);
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem *item, int column);
    void cdToParent();
    void updateDataTransferProgress(qint64 readBytes, qint64 totalBytes);
    void enableDownloadButton();

    void connectOrDisconnect();



private:
    QHash<QString, bool> isDirectory;
    QString currentPath;
    QFtp *ftp = nullptr;
    QFile *file = nullptr;

};

#endif // FTP_H
