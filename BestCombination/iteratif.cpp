#include "Functional.h"
#include "itemData.h"
#include <iostream>

void findBestCombinationIterative(int weaponCount, int armorCount, int accessoryCount, character &baseChar) {
    // Reset semua nilai global
    float bestCombination = 0.0f;
    string bestWeapon = "";
    string bestArmor = "";
    string bestAccessory = "";
    float finalATK = 0.0f;
    float finalDEF = 0.0f;
    float finalHP = 0.0f;

    float currentATK, currentDEF, currentHP;

    // Iterate through all possible combinations
    for (int w = 0; w < weaponCount; ++w) {
        for (int a = 0; a < armorCount; ++a) {
            for (int acc = 0; acc < accessoryCount; ++acc) {
                // Hitung atribut total untuk kombinasi saat ini
                currentATK = weaponList[w].baseATK + accessoryList[acc].ATK;
                currentDEF = armorList[a].baseDEF + accessoryList[acc].DEF;
                currentHP = accessoryList[acc].HP + armorList[a].baseHP;

                // Evaluasi kombinasi saat ini
                float currentCombination = currentATK + currentDEF + currentHP;

                // Periksa apakah kombinasi ini lebih baik dari yang sebelumnya
                if (currentCombination > bestCombination) {
                    bestCombination = currentCombination;
                    bestWeapon = weaponList[w].itemName;
                    bestArmor = armorList[a].itemName;
                    bestAccessory = accessoryList[acc].itemName;
                    finalATK = currentATK;
                    finalDEF = currentDEF;
                    finalHP = currentHP;
                }
            }
        }
    }

    // Output hasil
    cout << "Before power-up:" << endl;
    cout << "ATK: " << baseChar.baseATK << endl;
    cout << "DEF: " << baseChar.baseDEF << endl;
    cout << "HP: " << baseChar.baseHP << endl;

    cout << "\nAfter power-up:" << endl;
    cout << "ATK: " << finalATK + baseChar.baseATK << endl;
    cout << "DEF: " << finalDEF + baseChar.baseDEF << endl;
    cout << "HP: " << finalHP + baseChar.baseHP << endl;

    // Menampilkan kombinasi terkuat
    cout << "\nStrongest Combination: " << bestWeapon << ", "
         << bestArmor << ", " << bestAccessory
         << " value: " << bestCombination << endl;
}
