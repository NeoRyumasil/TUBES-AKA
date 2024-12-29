#include <iostream>
#include "ItemData.h"
#include "Functional.h"

using namespace std;

int weaponCount = 0;
int armorCount = 0;
int accessoryCount = 0;

// Global variables untuk menyimpan kombinasi terbaik
float bestCombination = 0.0f;
string bestWeapon, bestArmor, bestAccessory;
float finalATK, finalDEF, finalHP;

void insertWeapon(weapon WEA) {
    if (weaponCount < 10) {
        weaponList[weaponCount++] = WEA;
    } else {
        cout << "Weapon list is full!" << endl;
    }
}

void insertArmor(armor ARM) {
    if (armorCount < 10) {
        armorList[armorCount++] = ARM;
    } else {
        cout << "Armor list is full!" << endl;
    }
}

void insertAccessory(accessory ACC) {
    if (accessoryCount < 10) {
        accessoryList[accessoryCount++] = ACC;
    } else {
        cout << "Accessory list is full!" << endl;
    }
}

void findBestCombinationRecursive(int w, int a, int acc, character &baseChar) {
    // Base case: jika sudah mencoba semua kombinasi
    if (w >= weaponCount) {
        return;
    }

    // Hitung nilai kombinasi saat ini
    float currentATK = weaponList[w].baseAttack + accessoryList[acc].ATK;
    float currentDEF = armorList[a].baseDefend + accessoryList[acc].DEF;
    float currentHP = accessoryList[acc].HP + armorList[a].baseHP;
    float currentCombination = currentATK + currentDEF + currentHP;

    // Update kombinasi terbaik jika ditemukan yang lebih baik
    if (currentCombination > bestCombination) {
        bestCombination = currentCombination;
        bestWeapon = weaponList[w].itemName;
        bestArmor = armorList[a].itemName;
        bestAccessory = accessoryList[acc].itemName;
        finalATK = currentATK;
        finalDEF = currentDEF;
        finalHP = currentHP;
    }

    // Rekursif untuk mencoba kombinasi berikutnya
    if (acc + 1 < accessoryCount) {
        // Coba accessory berikutnya
        findBestCombinationRecursive(w, a, acc + 1, baseChar);
    } else if (a + 1 < armorCount) {
        // Jika sudah mencoba semua accessory, pindah ke armor berikutnya
        findBestCombinationRecursive(w, a + 1, 0, baseChar);
    } else {
        // Jika sudah mencoba semua armor, pindah ke weapon berikutnya
        findBestCombinationRecursive(w + 1, 0, 0, baseChar);
    }
}

void startRecursiveSearch(character &baseChar) {
    // Reset nilai global
    bestCombination = 0.0f;
    bestWeapon = "";
    bestArmor = "";
    bestAccessory = "";

    // Mulai pencarian rekursif dari indeks 0
    findBestCombinationRecursive(0, 0, 0, baseChar);

    // Output hasil
    cout << "\n=== Before Power-Up ===\n";
    cout << "ATK: " << baseChar.baseATK << "\n";
    cout << "DEF: " << baseChar.baseDEF << "\n";
    cout << "HP: " << baseChar.baseHP << "\n";

    cout << "\n=== After Power-Up ===\n";
    cout << "ATK: " << finalATK + baseChar.baseATK << "\n";
    cout << "DEF: " << finalDEF + baseChar.baseDEF << "\n";
    cout << "HP: " << finalHP + baseChar.baseHP << "\n";

    cout << "\n=== Strongest Combination ===\n";
    cout << "Character get power-up: " << endl;
    cout << "ATTACK: " << finalATK << endl;
    cout << "DEFENSE: " << finalDEF << endl;
    cout << "HEALTH: " << finalHP << endl;
    cout << "Total Value: " << bestCombination << "\n";
    cout << endl;
    cout << "Items: " << endl;
    cout << "Weapon: " << bestWeapon << "\n";
    cout << "Armor: " << bestArmor << "\n";
    cout << "Accessory: " << bestAccessory << "\n";
}

