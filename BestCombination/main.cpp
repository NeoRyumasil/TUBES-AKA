#include <iostream>
#include "ItemData.h"
#include "Functional.h"

using namespace std;

int main()
{
    pack kombinationPack;
    character charaStats;
    data1(charaStats);

    cout << "STATUS KARAKTER: " << endl;
    cout << "HP: " << charaStats.baseHP << endl;
    cout << "DEF: " << charaStats.baseDEF << endl;
    cout << "ATK: " << charaStats.baseATK << endl << endl;

    kombinationPack = kombinasiTerbaikRekursif(weaponCount-1, armorCount-1, accessoryCount-1, charaStats);

    cout << "Set Terbaik Adalah: " << endl;
    cout << "Weapon     : " << kombinationPack.WEA.itemName << endl;
    cout << "Armor      : " << kombinationPack.ARM.itemName << endl;
    cout << "Accessory  : " << kombinationPack.ACC.itemName << endl;

    charaStats.baseATK += kombinationPack.WEA.baseATK + kombinationPack.ACC.ATK;
    charaStats.baseDEF += kombinationPack.ARM.baseDEF + kombinationPack.ACC.DEF;
    charaStats.baseHP += kombinationPack.ARM.baseHP + kombinationPack.ACC.HP;

    cout << endl << "STATUS KARAKTER: " << endl;
    cout << "HP: " << charaStats.baseHP << endl;
    cout << "DEF: " << charaStats.baseDEF << endl;
    cout << "ATK: " << charaStats.baseATK << endl;

    return 0;
}
