void findBestCombinationIterative(int weaponCount, int armorCount, int accessoryCount, character &baseChar) {
    // Reset semua nilai global
    bestCombination = 0.0f;
    bestWeapon = "";
    bestArmor = "";
    bestAccessory = "";
    finalATK = 0.0f;
    finalDEF = 0.0f;
    finalHP = 0.0f;

    float currentATK, currentDEF, currentHP;

    // Iterate through all possible combinations
    for (int w = 0; w < weaponCount; ++w) {
        for (int a = 0; a < armorCount; ++a) {
            for (int acc = 0; acc < accessoryCount; ++acc) {
                currentATK = weaponList[w].baseAttack + accessoryList[acc].ATK;
                currentDEF = armorList[a].baseDefend + accessoryList[acc].DEF;
                currentHP = accessoryList[acc].HP + armorList[a].baseHP;

                float currentCombination = currentATK + currentDEF + currentHP;

                if (currentCombination > bestCombination) {
                    bestCombination = currentCombination;
                    bestAccessory = accessoryList[acc].itemName;
                    bestWeapon = weaponList[w].itemName;
                    bestArmor = armorList[a].itemName;
                    finalATK = currentATK;
                    finalDEF = currentDEF;
                    finalHP = currentHP;
                }
            }
        }
    }

    // Output hasil
    cout << "Before power-up:" << endl;
    cout << "ATK: " << baseChar.ATK << endl;
    cout << "DEF: " << baseChar.DEF << endl;
    cout << "HP: " << baseChar.HP << endl;

    cout << "\nAfter power-up:" << endl;
    cout << "ATK: " << finalATK + baseChar.ATK << endl;
    cout << "DEF: " << finalDEF + baseChar.DEF << endl;
    cout << "HP: " << finalHP + baseChar.HP << endl;

    // Menampilkan kombinasi terkuat
    cout << "\nStrongest Combination: " << bestWeapon << ", "
         << bestArmor << ", " << bestAccessory
         << " value: " << bestCombination << endl;
}
