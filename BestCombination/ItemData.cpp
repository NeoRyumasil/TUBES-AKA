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

void data1(character &charaStats) {
    charaStats.baseATK = 500;
    charaStats.baseDEF = 100;
    charaStats.baseHP = 1200;

    // Tambahkan data senjata
    insertWeapon({"Laevatein", 631});
    insertWeapon({"Excalibur", 544});
    insertWeapon({"Thunder Sword", 720});
    insertWeapon({"Flame Blade", 675});
    insertWeapon({"Shadow Dagger", 590});
    insertWeapon({"Ice Staff", 710});
    insertWeapon({"Phoenix Bow", 640});

    // Tambahkan data armor
    insertArmor({"Aquarius Imperial Armor", 250, 1606});
    insertArmor({"Aries Bustier", 370, 1133});
    insertArmor({"Knight Plate", 450, 1400});
    insertArmor({"Golden Shield", 320, 1230});
    insertArmor({"Steel Breastplate", 400, 1350});
    insertArmor({"Shadow Cloak", 290, 1100});
    insertArmor({"Mage Robe", 330, 1000});

    // Tambahkan data aksesori
    insertAccessory({"Euclase Earth", 188, 857, 300});
    insertAccessory({"Neptune Malachite", 44, 441, 500});
    insertAccessory({"Ring of Strength", 120, 400, 200});
    insertAccessory({"Amulet of Wisdom", 90, 600, 250});
    insertAccessory({"Bracelet of Speed", 140, 300, 300});
    insertAccessory({"Cloak of Shadows", 80, 700, 400});
    insertAccessory({"Necklace of Power", 200, 500, 350});
}
