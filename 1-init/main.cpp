#include "one_beginer.h"

#include <QApplication> // 一个应用程序的类
#include <QLocale>
#include <QTranslator>

// argument count    argument values
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 应用程序对象：这个对象有且只有一个

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "1-init_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // 窗口对象
    One_beginer w;
    // 显示窗口
    w.show();
    // 让a进入消息循环机制
    return a.exec();
}
