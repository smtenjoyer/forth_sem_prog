#ifndef LINETEST_H
#define LINETEST_H

#include <QObject>
#include <QtTest>
#include <QtGui>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

class LineEditTest : public QObject
{
    Q_OBJECT
private slots:
    void testLineEditUILayout();
    void testInvalidCharacters();
};

#endif // LINETEST_H
