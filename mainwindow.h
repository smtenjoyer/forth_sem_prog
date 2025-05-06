#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "Versus.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLineEdit* getLineEdit2() const; //для тестов
    QLineEdit* getweaponName() const;

private slots: // Обязательно укажите private slots, так как это слот
    void checkAndConnect();
    void on_AttackButton_clicked();
    void updateHealthUI();
    void showHeroAttack();
    void showEnemyAttack();

private:
    Ui::MainWindow *ui;
    AbstractWeapon* new_weapon;
    Fighter* Hero = new Fighter("none");
    Fighter* Enemy = new Fighter("none");
    std::string playerName;
    std::string weaponName;
    std::string weaponType;
    QMap<QString, QString> weaponImages;

    std::string enemyName;
};
#endif // MAINWINDOW_H
