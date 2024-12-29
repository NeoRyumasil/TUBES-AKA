#include "GUI.h"
#include "ItemData.h"
#include "Functional.h"
#include <chrono>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QElapsedTimer>

Item_Combination_App::Item_Combination_App(QWidget *parent):QWidget(parent){
    this->setupUI();
    this->showMaximized();
}

Item_Combination_App::~Item_Combination_App(){
    delete judul;
    delete Maker1;
    delete Maker2;


    delete insertCharaStatLabel;
    delete ATK;
    delete insertATK;
    delete DEF;
    delete inserDEF;
    delete HP;
    delete insertHP;

    delete InsertTotalDataLabel;
    delete InsertTotalWeaponLabel;
    delete InsertTotalWeapon;
    delete InsertTotalArmorLabel;
    delete InsertTotalArmor;
    delete InsertTotalAccessoriesLabel;
    delete InsertTotalAccessories;

    delete WhichButton;
    delete IterativeButton;
    delete RecursiveButton;

    delete bestCombinationLabel;
    delete bestWeaponLabel;
    delete bestArmorLabel;
    delete bestAccessoryLabel;

    delete showTotalData;
    delete showRunningTime;

    delete showCharStatsLabel;
    delete showModifiedATK;
    delete showModifiedDEF;
    delete showModifiedHP;

    delete showTable;

    delete Frame;
};

void Item_Combination_App::setupUI() {
    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Top Layout
    QVBoxLayout *topLayout = new QVBoxLayout();
    judul = new QLabel("Item Combination App", this);
    judul->setAlignment(Qt::AlignCenter);
    judul->setStyleSheet("font-size: 24px; font-weight: bold;");
    Maker1 = new QLabel("Ghanif Hadiyana Akbar - 103012300018", this);
    Maker2 = new QLabel("Muhammad Alvin Ababil - 103012330064", this);
    Maker1->setAlignment(Qt::AlignCenter);
    Maker2->setAlignment(Qt::AlignCenter);
    topLayout->addWidget(judul);
    topLayout->addWidget(Maker1);
    topLayout->addWidget(Maker2);

    // Input Layout
    QGridLayout *inputLayout = new QGridLayout();
    InsertTotalDataLabel = new QLabel("Masukkan Total Item yang ingin dicari:", this);
    InsertTotalWeaponLabel = new QLabel("Weapons:", this);
    InsertTotalWeapon = new QLineEdit(this);
    InsertTotalWeapon->setPlaceholderText("Max 100 Weapon");
    InsertTotalArmorLabel = new QLabel("Armor:", this);
    InsertTotalArmor = new QLineEdit(this);
    InsertTotalArmor->setPlaceholderText("Max 100 Armor");
    InsertTotalAccessoriesLabel = new QLabel("Accessories:", this);
    InsertTotalAccessories = new QLineEdit(this);
    InsertTotalAccessories->setPlaceholderText("Max 100 Accessories");

    inputLayout->addWidget(InsertTotalDataLabel, 0, 0, 1, 2);
    inputLayout->addWidget(InsertTotalWeaponLabel, 1, 0);
    inputLayout->addWidget(InsertTotalWeapon, 1, 1);
    inputLayout->addWidget(InsertTotalArmorLabel, 2, 0);
    inputLayout->addWidget(InsertTotalArmor, 2, 1);
    inputLayout->addWidget(InsertTotalAccessoriesLabel, 3, 0);
    inputLayout->addWidget(InsertTotalAccessories, 3, 1);

    // Input Char Stat Layout
    QGridLayout *charaStatsLayout = new QGridLayout();
    insertCharaStatLabel = new QLabel("Masukkan Character Stats:", this);
    ATK = new QLabel("ATK:", this);
    insertATK = new QLineEdit(this);
    DEF = new QLabel("DEF:", this);
    inserDEF = new QLineEdit(this);
    HP = new QLabel("HP:", this);
    insertHP = new QLineEdit(this);

    charaStatsLayout->addWidget(insertCharaStatLabel, 0, 0, 1, 2);
    charaStatsLayout->addWidget(ATK, 1, 0);
    charaStatsLayout->addWidget(insertATK, 1, 1);
    charaStatsLayout->addWidget(DEF, 2, 0);
    charaStatsLayout->addWidget(inserDEF, 2, 1);
    charaStatsLayout->addWidget(HP, 3, 0);
    charaStatsLayout->addWidget(insertHP, 3, 1);

    // Button
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    WhichButton = new QLabel("Pilih Metode Kombinasi:", this);
    IterativeButton = new QPushButton("Iterative", this);
    RecursiveButton = new QPushButton("Recursive", this);
    buttonLayout->addWidget(WhichButton);
    buttonLayout->addWidget(IterativeButton);
    buttonLayout->addWidget(RecursiveButton);

    // Output
    QGridLayout *outputLayout = new QGridLayout();
    bestCombinationLabel = new QLabel("Best Combination:", this);
    bestWeaponLabel = new QLabel("Weapon: ", this);
    bestArmorLabel = new QLabel("Armor: ", this);
    bestAccessoryLabel = new QLabel("Accessory: ", this);
    showTotalData = new QLabel("Total(n): ", this);
    showRunningTime = new QLabel("Running Time: ", this);
    showCharStatsLabel = new QLabel("Status Setelah Memakai Item: ");
    showModifiedATK = new QLabel("ATK: ");
    showModifiedDEF = new QLabel("DEF: ");
    showModifiedHP = new QLabel("HP: ");

    outputLayout->addWidget(bestCombinationLabel, 0, 0, 1, 2);
    outputLayout->addWidget(bestWeaponLabel, 1, 0);
    outputLayout->addWidget(bestArmorLabel, 2, 0);
    outputLayout->addWidget(bestAccessoryLabel, 3, 0);
    outputLayout->addWidget(showTotalData, 1, 1, 1, 2);
    outputLayout->addWidget(showRunningTime, 2, 1, 1, 2);
    outputLayout->addWidget(showCharStatsLabel,0,2,1,2);
    outputLayout->addWidget(showModifiedATK,1,2,1,2);
    outputLayout->addWidget(showModifiedDEF,2,2,1,2);
    outputLayout->addWidget(showModifiedHP,3,2,1,2);

    // Table
    showTable = new QTableWidget(this);
    showTable->setRowCount(0);
    showTable->setColumnCount(4); // Columns: ItemName, ATK, HP, DEF
    QStringList headers = {"ItemName", "ATK", "HP", "DEF"};
    showTable->setHorizontalHeaderLabels(headers);
    showTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    dataItem();
    isiTabel();

    // Frame
    Frame = new QFrame(this);
    Frame->setFrameShape(QFrame::StyledPanel);
    QVBoxLayout *frameLayout = new QVBoxLayout(Frame);
    frameLayout->addLayout(inputLayout);
    frameLayout->addLayout(charaStatsLayout); // Add Character Stats Section
    frameLayout->addLayout(buttonLayout);
    frameLayout->addLayout(outputLayout);
    frameLayout->addWidget(showTable);

    // Set Layout
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(Frame);

    setLayout(mainLayout);

    // Connect Button
    connect(IterativeButton, SIGNAL(clicked()), this, SLOT(on_IterativeButton_clicked()));
    connect(RecursiveButton, SIGNAL(clicked()), this, SLOT(on_RecursiveButton_clicked()));
}

void Item_Combination_App::on_IterativeButton_clicked(){
    int WEA = InsertTotalWeapon->text().toInt();
    int ARM = InsertTotalArmor->text().toInt();
    int ACC = InsertTotalAccessories->text().toInt();
    float charATK = insertATK->text().toFloat();
    float charDEF = inserDEF->text().toFloat();
    float charHP = insertHP->text().toFloat();
    character charaStats;
    pack bestCombinationPack;

    charaStats.baseATK = charATK;
    charaStats.baseDEF = charDEF;
    charaStats.baseHP = charHP;

    int totalCombinations = totalCombination(WEA, ARM, ACC);
    showTotalData->setText("Total(n): " + QString::number(totalCombinations));

    auto start = std::chrono::high_resolution_clock::now();

    bestCombinationPack = findBestCombinationIterative(WEA,ARM,ACC,charaStats);


    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double elapsedTime = duration.count() * 1e-6;
    showRunningTime->setText("Running Time: " + QString::number(elapsedTime, 'f', 5) + " ms");

    bestWeaponLabel->setText("Weapon: " + QString::fromStdString(bestCombinationPack.WEA.itemName));
    bestArmorLabel->setText("Armor: " + QString::fromStdString(bestCombinationPack.ARM.itemName));
    bestAccessoryLabel->setText("Accessory: " + QString::fromStdString(bestCombinationPack.ACC.itemName));

    float modifiedATK = charaStats.baseATK + bestCombinationPack.WEA.baseATK + bestCombinationPack.ACC.ATK;
    float modifiedDEF = charaStats.baseDEF + bestCombinationPack.ARM.baseDEF + bestCombinationPack.ACC.DEF;
    float modifiedHP = charaStats.baseHP + bestCombinationPack.ARM.baseHP + bestCombinationPack.ACC.HP;

    showModifiedATK->setText("ATK: " + QString::number(modifiedATK, 'f', 2));
    showModifiedDEF->setText("DEF: " + QString::number(modifiedDEF, 'f', 2));
    showModifiedHP->setText("HP: " + QString::number(modifiedHP, 'f', 2));
}

void Item_Combination_App::on_RecursiveButton_clicked(){
    int WEA = InsertTotalWeapon->text().toInt();
    int ARM = InsertTotalArmor->text().toInt();
    int ACC = InsertTotalAccessories->text().toInt();
    float charATK = insertATK->text().toFloat();
    float charDEF = inserDEF->text().toFloat();
    float charHP = insertHP->text().toFloat();
    character charaStats;
    pack bestCombinationPack;

    charaStats.baseATK = charATK;
    charaStats.baseDEF = charDEF;
    charaStats.baseHP = charHP;

    int totalCombinations = totalCombination(WEA, ARM, ACC);
    showTotalData->setText("Total(n): " + QString::number(totalCombinations));

    auto start = std::chrono::high_resolution_clock::now();
    bestCombinationPack = kombinasiTerbaikRekursif(WEA,ARM,ACC,charaStats);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double elapsedTime = duration.count() * 1e-6;
    showRunningTime->setText("Running Time: " + QString::number(elapsedTime) + " ms");

    bestWeaponLabel->setText("Weapon: " + QString::fromStdString(bestCombinationPack.WEA.itemName));
    bestArmorLabel->setText("Armor: " + QString::fromStdString(bestCombinationPack.ARM.itemName));
    bestAccessoryLabel->setText("Accessory: " + QString::fromStdString(bestCombinationPack.ACC.itemName));

    float modifiedATK = charaStats.baseATK + bestCombinationPack.WEA.baseATK + bestCombinationPack.ACC.ATK;
    float modifiedDEF = charaStats.baseDEF + bestCombinationPack.ARM.baseDEF + bestCombinationPack.ACC.DEF;
    float modifiedHP = charaStats.baseHP + bestCombinationPack.ARM.baseHP + bestCombinationPack.ACC.HP;

    showModifiedATK->setText("ATK: " + QString::number(modifiedATK, 'f', 2));
    showModifiedDEF->setText("DEF: " + QString::number(modifiedDEF, 'f', 2));
    showModifiedHP->setText("HP: " + QString::number(modifiedHP, 'f', 2));
}

void Item_Combination_App::isiTabel(){
    // Header
    showTable->setColumnCount(4);
    QStringList headers = {"ItemName", "ATK", "HP", "DEF"};
    showTable->setHorizontalHeaderLabels(headers);

    showTable->setRowCount(0);

    // Data Weapon
    for (int i = 0; i < weaponCount; i++) {
        int row = showTable->rowCount();
        showTable->insertRow(row);
        showTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(weaponList[i].itemName)));
        showTable->setItem(row, 1, new QTableWidgetItem(QString::number(weaponList[i].baseATK, 'f', 2)));
        showTable->setItem(row, 2, new QTableWidgetItem("0"));
        showTable->setItem(row, 3, new QTableWidgetItem("0"));
    }

    // Data Armor
    for (int i = 0; i < armorCount; i++) {
        int row = showTable->rowCount();
        showTable->insertRow(row);
        showTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(armorList[i].itemName)));
        showTable->setItem(row, 1, new QTableWidgetItem("0")); // No ATK for armor
        showTable->setItem(row, 2, new QTableWidgetItem(QString::number(armorList[i].baseHP, 'f', 2)));
        showTable->setItem(row, 3, new QTableWidgetItem(QString::number(armorList[i].baseDEF, 'f', 2)));
    }

    // Data Acc
    for (int i = 0; i < accessoryCount; i++) {
        int row = showTable->rowCount();
        showTable->insertRow(row);
        showTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(accessoryList[i].itemName)));
        showTable->setItem(row, 1, new QTableWidgetItem(QString::number(accessoryList[i].ATK, 'f', 2)));
        showTable->setItem(row, 2, new QTableWidgetItem(QString::number(accessoryList[i].HP, 'f', 2)));
        showTable->setItem(row, 3, new QTableWidgetItem(QString::number(accessoryList[i].DEF, 'f', 2)));
    }
}

int Item_Combination_App::totalCombination(int totalWeapons, int totalArmors, int totalAcc){
    return totalWeapons + totalArmors + totalAcc;
}
