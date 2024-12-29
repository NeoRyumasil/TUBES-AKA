#ifndef FUNCTIONAL_H_INCLUDED
#define FUNCTIONAL_H_INCLUDED
#include "ItemData.h"
#include <string>

using namespace std;

int findAccessoryIndex(const accessory &A);
int findArmorIndex(const armor &A);
int findWeaponIndex(const weapon &W);

float hitungKekuatanCharacter(int indexWeapon, int indexArmor, int indexAccessory, character &baseStats);
pack kombinasiTerbaikRekursif(int WEA, int ARM, int ACC, character &baseStat);
#endif // FUNCTIONAL_H_INCLUDED
