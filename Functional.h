#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include "ItemData.h"

using namespace std;

int findAccessoryIndex(const accessory &A);
int findArmorIndex(const armor &A);
int findWeaponIndex(const weapon &W);

float hitungKekuatanCharacter(int indexWeapon, int indexArmor, int indexAccessory, character &baseStats);
pack kombinasiTerbaikRekursif(int WEA, int ARM, int ACC, character &baseStat);
pack findBestCombinationIterative(int weaponCount, int armorCount, int accessoryCount, character &baseChar);

#endif // FUNCTIONAL_H_INCLUDED


