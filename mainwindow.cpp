#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "Versus.h"
#include <QEventLoop>
#include <QTimer>

QLineEdit* MainWindow::getLineEdit2() const {
    return ui->lineEdit_2;
}

QLineEdit* MainWindow::getweaponName() const {
    return ui->weaponName;
}


void MainWindow::checkAndConnect()
{
    // Проверяем, выбрано ли значение в комбобоксе (индекс больше 0) и введен ли текст
    if (ui->comboBox->currentIndex() > 0 && !ui->weaponName->text().isEmpty()) {
        // Подключаем сигнал returnPressed, если условия выполнены
        connect(ui->weaponName, &QLineEdit::returnPressed, this, [this](){
            // Получаем выбранное значение из комбобокса
            int selectedIndex = ui->comboBox->currentIndex();
            weaponName = ui->weaponName->text().toStdString();

            switch (selectedIndex) {
            case 1:
                weaponType = "one-handed sword";
                new_weapon = WeaponFactory::CreateWeapon("Sword", weaponName, 400, 100, 1.0f);

                break;
            case 2:
                weaponType = "hand-and-a-half sword";
                new_weapon = WeaponFactory::CreateWeapon("Sword", weaponName, 70, 120, 1.5f);
                break;
            case 3:
                weaponType = "two-handed sword";
                new_weapon = WeaponFactory::CreateWeapon("Sword", weaponName, 50, 160, 2.0f);
                break;
            case 4:
                weaponType = "fire magic wand";
                new_weapon = WeaponFactory::CreateWeapon("WisardWand", weaponName, 60, 50, 0.0f, "fire");
                break;
            case 5:
                weaponType = "water magic wand";
                new_weapon = WeaponFactory::CreateWeapon("WisardWand", weaponName, 60, 50, 0.0f, "water");
                break;
            case 6:
                weaponType = "air magic wand";
                new_weapon = WeaponFactory::CreateWeapon("WisardWand", weaponName, 60, 50, 0.0f, "air");
                break;
            case 7:
                weaponType = "terra magic sword";
                new_weapon = WeaponFactory::CreateWeapon("WisardWand", weaponName, 60, 50, 0.0f, "terra");
                break;
            default:
                // Обработка невалидного значения
                qDebug() << "Invalid combo box selection";
                break;
            }


            Hero->EquipWeapon(new_weapon);


            // Получаем путь к картинке оружия
            QString imagePath = weaponImages.value(QString::fromStdString(weaponType),
                                                   ":/images/default.png"); // default.png если тип не найден

            // Получаем QLabel для картинки (на странице 2)
            QLabel *imageLabel = ui->stackedWidget->widget(3)->findChild<QLabel *>("label_7"); // Получаем QLabel для картинки

            if (imageLabel) {
                // Создаем stylesheet с новой картинкой
                QString styleSheet = "background-image: url(" + imagePath + ");";
                imageLabel->setStyleSheet(styleSheet);
                imageLabel->setAlignment(Qt::AlignCenter);
            }


            // Переключаемся на страницу 3 (страница с надписью)
            ui->stackedWidget->setCurrentIndex(3);


            // Создаем сообщение для отображения на следующей странице
            std::string message = "Your name is " + playerName + " with " + weaponType + " " + weaponName + " in your hands and you are ready to fight.";


            QLabel *label = ui->stackedWidget->widget(3)->findChild<QLabel *>("labelOnPage3");
            if (label) {
                label->setText(QString::fromStdString(message));
            }

            if (weaponType == "one-handed sword")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("OneStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/oneStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("oneAttack"); // Получаем QLabel для картинки


                QString styleSheet2 = "background-image: url(:/images/oneAttack.png);";
                imageLabel2->setStyleSheet(styleSheet2);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "hand-and-a-half sword")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("fiveStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/5Stand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("fiveAttack"); // Получаем QLabel для картинки


                QString styleSheet2 = "background-image: url(:/images/5Attack.png);";
                imageLabel2->setStyleSheet(styleSheet2);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "two-handed sword")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("twoStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/twoStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("twoAttack"); // Получаем QLabel для картинки


                QString styleSheet2 = "background-image: url(:/images/twoAttack.png);";
                imageLabel2->setStyleSheet(styleSheet2);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "fire magic wand")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("WandStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/fireStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("WandAttack"); // Получаем QLabel для картинки


                imageLabel2->setStyleSheet(styleSheet1);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "water magic wand")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("WandStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/waterStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("WandAttack"); // Получаем QLabel для картинки


                imageLabel2->setStyleSheet(styleSheet1);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "air magic wand")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("WandStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/airStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("WandAttack"); // Получаем QLabel для картинки


                imageLabel2->setStyleSheet(styleSheet1);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }
            else if (weaponType == "terra magic wand")
            {
                QLabel *imageLabel1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("WandStand"); // Получаем QLabel для картинки

                QString styleSheet1 = "background-image: url(:/images/terraStand.png);";
                imageLabel1->setStyleSheet(styleSheet1);
                imageLabel1->setAlignment(Qt::AlignCenter);
                QLabel *imageLabel2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("WandAttack"); // Получаем QLabel для картинки


                imageLabel2->setStyleSheet(styleSheet1);
                imageLabel2->setAlignment(Qt::AlignCenter);
            }


        });
    } else {

        disconnect(ui->weaponName, &QLineEdit::returnPressed, this, nullptr);
    }
}


// Обновляем HP на экране 5
void MainWindow::updateHealthUI() {
    std::string Hero_health = "HP: " + std::to_string(Hero->GetHealth());
    std::string Enemy_health = "HP: " + std::to_string(Enemy->GetHealth());

    QLabel *label1 = ui->stackedWidget->widget(5)->findChild<QLabel *>("Hero_HP");
    if (label1) {
        label1->setText(QString::fromStdString(Hero_health));
    }
    QLabel *label2 = ui->stackedWidget->widget(5)->findChild<QLabel *>("Enemy_HP");
    if (label2) {
        label2->setText(QString::fromStdString(Enemy_health));
    }
}


void delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}


void MainWindow::showHeroAttack() {
    Hero->Attack(Enemy);

    std::string message = "- " + std::to_string(Hero->_equippedWeapon->GetDamage());
    QLabel *label2 = ui->stackedWidget->widget(6)->findChild<QLabel *>("Enemy_damaged");
    if (label2) {
        label2->setText(QString::fromStdString(message));
    }

    delay(1000);

    showEnemyAttack();
    if (Hero->GetHealth() <= 0) {
        ui->stackedWidget->setCurrentIndex(8);
        return;
    }
    if (Enemy->GetHealth() <= 0) {
        ui->stackedWidget->setCurrentIndex(9);
        return;
    }
}


void MainWindow::showEnemyAttack() {
    ui->stackedWidget->setCurrentIndex(7);
    Enemy->Attack(Hero);
    updateHealthUI();

    std::string message = "- " + std::to_string(Enemy->_equippedWeapon->GetDamage());
    QLabel *label3 = ui->stackedWidget->widget(7)->findChild<QLabel *>("Hero_damaged");
    if (label3) {
        label3->setText(QString::fromStdString(message));
    }

    delay(1000);  // 1000 milliseconds

    // Возвращаемся к экрану выбора действия и включаем кнопку атаки
    ui->stackedWidget->setCurrentIndex(5);
    if (Hero->GetHealth() <= 0) {
        ui->stackedWidget->setCurrentIndex(8);
        return;
    }
    if (Enemy->GetHealth() <= 0) {
        ui->stackedWidget->setCurrentIndex(9);
        return;
    }
}



void MainWindow::on_AttackButton_clicked() {

    ui->stackedWidget->setCurrentIndex(6);

    //Запускаем показ атаки героя
    showHeroAttack();

}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{


    weaponImages["one-handed sword"] = ":/images/Illustration2.jpg";
    weaponImages["hand-and-a-half sword"]   = ":/images/Illustration4.jpg";
    weaponImages["two-handed sword"] = ":/images/Illustration3.jpg";

    weaponImages["fire magic wand"] = ":/images/fire.jpg";
    weaponImages["water magic wand"]   = ":/images/water.jpg";
    weaponImages["air magic wand"] = ":/images/air.jpg";
    weaponImages["terra magic wand"] = ":/images/terrs.jpg";


    ui->setupUi(this);


    connect(ui->yesButton_2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->noButton_2, &QPushButton::clicked, this, [this]() {
        QApplication::quit();
    });


    QValidator *validator = new QRegularExpressionValidator(QRegularExpression(".+"), this);
    ui->lineEdit_2->setValidator(validator);
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, this, [this](){
        if (ui->lineEdit_2->hasAcceptableInput()) {

            playerName = ui->lineEdit_2->text().toStdString();
            Hero->SetName(playerName);
            ui->stackedWidget->setCurrentIndex(2);
        }else {

            disconnect(ui->lineEdit_2, &QLineEdit::returnPressed, this, nullptr);
        }
    });


    disconnect(ui->weaponName, &QLineEdit::returnPressed, this, nullptr);

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [this](int index){
        checkAndConnect();
    });
    connect(ui->weaponName, &QLineEdit::textChanged, this, [this](const QString &text){
        checkAndConnect();
    });

    connect(ui->coolButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->vol, &QPushButton::clicked, this, [this]() {
        Enemy->SetName("Voldemort");
        std::string weapon_name_choice = "Evil Wand";
        AbstractWeapon* Yew_Wand = WeaponFactory::CreateWeapon("WisardWand", weapon_name_choice, 302, 100, 0.0f, "Curse");
        Enemy->EquipWeapon(Yew_Wand);
        ui->stackedWidget->setCurrentIndex(10);
    });

    connect(ui->art, &QPushButton::clicked, this, [this]() {
        Enemy->SetName("Arthur");
        std::string weapon_name_choice = "Excalibur";
        AbstractWeapon* excalibur = WeaponFactory::CreateWeapon("Sword", weapon_name_choice, 100, 120, 1.5f);
        Enemy->EquipWeapon(excalibur);
        updateHealthUI();
        ui->stackedWidget->setCurrentIndex(5);
    });

    connect(ui->AttackButton, &QPushButton::clicked, this, &MainWindow::on_AttackButton_clicked);

    ui->stackedWidget->setCurrentIndex(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}
