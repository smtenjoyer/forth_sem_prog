#include "linetest.h"
#include "mainwindow.h"

void LineEditTest::testLineEditUILayout() {
    MainWindow w;
    w.show();
    QLineEdit* lineEdit = w.getLineEdit2(); // Use the getter

    QVERIFY(lineEdit != nullptr);

    QString longName = "VeryVeryVeryVeryVeryVeryVeryLongPlayerName";
    QTest::keyClicks(lineEdit, longName);
    QApplication::processEvents();


    QVERIFY( lineEdit->text().length() <= 20);
}



void LineEditTest::testInvalidCharacters() {
    MainWindow w;
    w.show();
    QLineEdit* lineEdit = w.getweaponName(); // Use the getter

    QVERIFY(lineEdit != nullptr);
    QRegularExpression regex("^[\\p{L}\\s]+$");

    lineEdit->setText("КрутойИгрок123");
    QApplication::processEvents();


    QVERIFY(regex.match(lineEdit->text()).hasMatch());
}
