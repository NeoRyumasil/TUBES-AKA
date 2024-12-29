#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <QTableWidget>

class Item_Combination_App : public QWidget{
    Q_OBJECT

public:
    explicit Item_Combination_App(QWidget *parent);
    ~Item_Combination_App();
    void setupUI();
    void isiTabel();
    int totalCombination(int totalWeapons, int totalArmors, int totalAcc);

private slots:
    void on_IterativeButton_clicked();
    void on_RecursiveButton_clicked();

private :
    QLabel *judul;
    QLabel *Maker1;
    QLabel *Maker2;

    QLabel *insertCharaStatLabel;
    QLabel *ATK;
    QLineEdit *insertATK;
    QLabel *DEF;
    QLineEdit *inserDEF;
    QLabel *HP;
    QLineEdit *insertHP;

    QLabel *InsertTotalDataLabel;
    QLabel *InsertTotalWeaponLabel;
    QLineEdit *InsertTotalWeapon;
    QLabel *InsertTotalArmorLabel;
    QLineEdit *InsertTotalArmor;
    QLabel *InsertTotalAccessoriesLabel;
    QLineEdit *InsertTotalAccessories;

    QLabel *WhichButton;
    QPushButton *IterativeButton;
    QPushButton *RecursiveButton;

    QLabel *bestCombinationLabel;
    QLabel *bestWeaponLabel;
    QLabel *bestArmorLabel;
    QLabel *bestAccessoryLabel;

    QLabel *showTotalData;
    QLabel *showRunningTime;

    QLabel *showCharStatsLabel;
    QLabel *showModifiedATK;
    QLabel *showModifiedDEF;
    QLabel *showModifiedHP;

    QTableWidget *showTable;

    QFrame *Frame;
};

#endif // GUI_H
