#include "Functional.h"
#include "itemData.h"
#include <iostream>

void findBestCombinationIterative(int weaponCount, int armorCount, int accessoryCount, character &baseChar) {
    float bestCombination = 0.0f;
    float currentATK, currentDEF, currentHP;
    string bestWeapon, bestArmor, bestAccessory;
    float currentCombination = 0;
    float  attack_total,Def_total,HP_total = 0;


    // Iterasi melalui semua kemungkinan kombinasi
    for (int w = 0; w < weaponCount; ++w) {
        for (int a = 0; a < armorCount; ++a) {
            for (int acc = 0; acc < accessoryCount; ++acc) {
                // Hitung nilai kombinasi saat ini
                currentATK = weaponList[w].baseAttack + accessoryList[acc].ATK;
                currentDEF = armorList[a].baseDefend + accessoryList[acc].DEF;
                currentHP = accessoryList[acc].HP + armorList[a].baseHP;

                currentCombination = currentATK + currentDEF + currentHP;

                // Periksa apakah kombinasi ini adalah yang terbaik
                if (currentCombination > bestCombination) {
                    bestCombination = currentCombination;
                    bestAccessory = accessoryList[acc].itemName;
                    bestWeapon = weaponList[w].itemName;
                    bestArmor = armorList[a].itemName;
                    attack_total = currentATK;
                    Def_total = currentDEF;
                    HP_total= currentHP;

                }
            }
        }
    }

    // Output hasil
    cout << "\n=== Before Power-Up ===\n";
    cout << "ATK: " << baseChar.baseATK << "\n";
    cout << "DEF: " << baseChar.baseDEF << "\n";
    cout << "HP: " << baseChar.baseHP << "\n";

    cout << "\n=== After Power-Up ===\n";
    cout << "ATK: " << attack_total + baseChar.baseATK << "\n";
    cout << "DEF: " << Def_total + baseChar.baseDEF << "\n";
    cout << "HP: " << HP_total + baseChar.baseHP << "\n";

    cout << "\n=== Strongest Combination ===\n";
    cout << "Character get power-up: "<<endl;
    cout << "ATTACK: "<<attack_total<<endl;
    cout << "DEFENSE: "<<Def_total<<endl;
    cout << "ATTACK: "<<HP_total<<endl;
    cout << "Total Value: " << bestCombination << "\n";
    cout <<endl;
    cout << "Items: "<<endl;
    cout << "Weapon: " << bestWeapon <<" value: "<< "\n";
    cout << "Armor: " << bestArmor << "\n";
    cout << "Accessory: " << bestAccessory << "\n";
}
