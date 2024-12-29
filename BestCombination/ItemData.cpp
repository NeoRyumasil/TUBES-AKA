#include "ItemData.h"
#include <iostream>

using namespace std;

int weaponCount, armorCount, accessoryCount = 0;

weapon weaponList[10];
armor armorList[10];
accessory accessoryList[10];

void insertWeapon(weapon WEA, int totalWeapon){
    if(weaponCount < totalWeapon){
        weaponList[weaponCount++] = WEA;
    } else {
        cout << "Weapon Penuh" << endl;
    }
}

void insertArmor(armor ARM, int totalArmor){
    if(armorCount < totalArmor){
        armorList[armorCount++] = ARM;
    } else {
        cout << "Armor Penuh" << endl;
    }
}

void insertAccessory(accessory ACC, int totalAccessory){
    if(accessoryCount < totalAccessory){
        accessoryList[accessoryCount++] = ACC;
    } else {
        cout << "Accessory Penuh" << endl;
    }
}

void data1(character &charaStats){
    int totalWeapon = 2;
    int totalArmor = 2;
    int totalAccessory = 2;

    charaStats.baseATK = 500;
    charaStats.baseDEF = 100;
    charaStats.baseHP = 1200;

    insertWeapon({"Laevatein", 631}, totalWeapon);
    insertWeapon({"Excalibur", 544}, totalWeapon);

    insertArmor({"Aquarius Imperial Armor", 250, 1606}, totalArmor);
    insertArmor({"Aries Bustier", 370, 1133}, totalArmor);

    insertAccessory({"Euclase Earth", 188, 857, 300}, totalAccessory);
    insertAccessory({"Neptune Malachite", 44, 441, 500}, totalAccessory);
}
