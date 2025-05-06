#include "mainwindow.h"
#include <QApplication>
#include "linetest.h"
#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    // freopen("testing.log", "w", stdout);
    // QApplication a(argc, argv);
    // QTest::qExec(new LineEditTest, argc, argv);
    // return 0;
}
