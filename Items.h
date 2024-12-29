#ifndef ITEMS_H
#define ITEMS_H
#include <string>

using namespace std;

struct accessory{
    string itemName;
    int baseProtection;
    int baseHP;
    int baseAttack;
    float critDMG;
    float critChance;
};

struct armor{
    string itemName;
    int baseProtection;
    int baseHP;
};

struct weapon
{
    string itemName;
    int baseAttack;
    float critDMG;
    float critChance;
};

#endif // ITEMS_H
