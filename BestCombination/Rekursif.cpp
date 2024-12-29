#include <iostream>
#include "ItemData.h"
#include "Functional.h"

using namespace std;

// Helper function to find the index of a weapon in weaponList
int findWeaponIndex(const weapon &W) {
    for (int i = 0; i < weaponCount; ++i) {
        if (weaponList[i].itemName == W.itemName) {
            return i;
        }
    }
    return -1;  // Return -1 if not found
}

// Helper function to find the index of an armor in armorList
int findArmorIndex(const armor &A) {
    for (int i = 0; i < armorCount; ++i) {
        if (armorList[i].itemName == A.itemName) {
            return i;
        }
    }
    return -1;  // Return -1 if not found
}

// Helper function to find the index of an accessory in accessoryList
int findAccessoryIndex(const accessory &A) {
    for (int i = 0; i < accessoryCount; ++i) {
        if (accessoryList[i].itemName == A.itemName) {
            return i;
        }
    }
    return -1;  // Return -1 if not found
}

float hitungKekuatanCharacter(int indexWeapon, int indexArmor, int indexAccessory, character &baseStats){
    if (indexWeapon < 0 || indexAccessory < 0 || indexArmor < 0){
        return 0;
    }

    character modifiedStats = baseStats;

    if (indexWeapon >= 0){
        modifiedStats.baseATK += weaponList[indexWeapon].baseATK;
    }

    if (indexArmor >= 0){
        modifiedStats.baseDEF += armorList[indexArmor].baseDEF;
        modifiedStats.baseHP += armorList[indexArmor].baseHP;
    }

    if (indexAccessory >= 0){
        modifiedStats.baseATK += accessoryList[indexAccessory].ATK;
        modifiedStats.baseDEF += accessoryList[indexAccessory].DEF;
        modifiedStats.baseHP += accessoryList[indexAccessory].HP;
    }

    return modifiedStats.baseATK + modifiedStats.baseDEF + modifiedStats.baseHP;
}

pack kombinasiTerbaikRekursif(int WEA, int ARM, int ACC, character &baseStat) {
    float bestPower = 0;
    pack bestCombinationPack;

    if (WEA < 0 && ARM < 0 && ACC < 0) {
        return bestCombinationPack;
    }

    float currentPower = 0;
    weapon currentWeapon;
    armor currentArmor;
    accessory currentAccessory;

    if (WEA >= 0) {
        currentPower += weaponList[WEA].baseATK;
        currentWeapon = weaponList[WEA];
    }

    if (ARM >= 0) {
        currentPower += armorList[ARM].baseDEF + armorList[ARM].baseHP;
        currentArmor = armorList[ARM];
    }

    if (ACC >= 0) {
        currentPower += accessoryList[ACC].ATK + accessoryList[ACC].DEF + accessoryList[ACC].HP;
        currentAccessory = accessoryList[ACC];
    }

    if (currentPower > bestPower) {
        bestPower = currentPower;
        bestCombinationPack.WEA = currentWeapon;
        bestCombinationPack.ARM = currentArmor;
        bestCombinationPack.ACC = currentAccessory;
    }

    if (WEA >= 0) {
        pack bestWeaponCombination = kombinasiTerbaikRekursif(WEA - 1, ARM, ACC, baseStat);
        int weaponIndex = findWeaponIndex(bestWeaponCombination.WEA);
        int armorIndex = findArmorIndex(bestWeaponCombination.ARM);
        int accessoryIndex = findAccessoryIndex(bestWeaponCombination.ACC);

        float weaponPower = hitungKekuatanCharacter(weaponIndex, armorIndex, accessoryIndex, baseStat);
        if (weaponPower > bestPower) {
            bestCombinationPack = bestWeaponCombination;
            bestPower = weaponPower;
        }
    }

    if (ARM >= 0) {
        pack bestArmorCombination = kombinasiTerbaikRekursif(WEA, ARM - 1, ACC, baseStat);
        int weaponIndex = findWeaponIndex(bestArmorCombination.WEA);
        int armorIndex = findArmorIndex(bestArmorCombination.ARM);
        int accessoryIndex = findAccessoryIndex(bestArmorCombination.ACC);

        float armorPower = hitungKekuatanCharacter(weaponIndex, armorIndex, accessoryIndex, baseStat);
        if (armorPower > bestPower) {
            bestCombinationPack = bestArmorCombination;
            bestPower = armorPower;
        }
    }

    if (ACC >= 0) {
        pack bestAccessoryCombination = kombinasiTerbaikRekursif(WEA, ARM, ACC - 1, baseStat);
        int weaponIndex = findWeaponIndex(bestAccessoryCombination.WEA);
        int armorIndex = findArmorIndex(bestAccessoryCombination.ARM);
        int accessoryIndex = findAccessoryIndex(bestAccessoryCombination.ACC);

        float accessoryPower = hitungKekuatanCharacter(weaponIndex, armorIndex, accessoryIndex, baseStat);
        if (accessoryPower > bestPower) {
            bestCombinationPack = bestAccessoryCombination;
            bestPower = accessoryPower;
        }
    }


    return bestCombinationPack;
}
