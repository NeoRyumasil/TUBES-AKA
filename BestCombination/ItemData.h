#ifndef ITEMDATA_H_INCLUDED
#define ITEMDATA_H_INCLUDED
#include <string>

using namespace std;

extern int weaponCount, armorCount, accessoryCount;

struct weapon{
    string itemName;
    float baseATK;
};

struct armor{
    string itemName;
    float baseDEF;
    float baseHP;
};

struct accessory{
    string itemName;
    float ATK;
    float HP;
    float DEF;
};

struct character{
    float baseATK;
    float baseHP;
    float baseDEF;
};

struct pack{
    weapon WEA;
    armor ARM;
    accessory ACC;
};

extern weapon weaponList[10];
extern armor armorList[10];
extern accessory accessoryList[10];

void data1(character &charaStats); //data ada 9
void data2(character &charaStats); //data ada 12
void data3(character &charaStats); //data ada 27
void insertWeapon(weapon WEA, int totalWeapon);
void insertArmor(armor ARM, int totalWeapon);
void insertAccessory(accessory ACC, int totalWeapon);

#endif // ITEMDATA_H_INCLUDED
