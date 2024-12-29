#include "Functional.h"
#include "itemData.h"

pack findBestCombinationIterative(int weaponCount, int armorCount, int accessoryCount, character &baseChar) {
    pack bestCombinationPack;
    float bestCombination = 0.0f;
    float currentATK, currentDEF, currentHP = 0.0;

    for (int w = 0; w < weaponCount; ++w) {
        for (int a = 0; a < armorCount; ++a) {
            for (int acc = 0; acc < accessoryCount; ++acc) {
                // Hitung atribut total untuk kombinasi saat ini
                currentATK = weaponList[w].baseATK + accessoryList[acc].ATK;
                currentDEF = armorList[a].baseDEF + accessoryList[acc].DEF;
                currentHP = accessoryList[acc].HP + armorList[a].baseHP;

                float currentCombination = currentATK + currentDEF + currentHP + baseChar.baseATK + baseChar.baseDEF + baseChar.baseHP;

                if (currentCombination > bestCombination) {
                    bestCombination = currentCombination;
                    bestCombinationPack.WEA = weaponList[w];
                    bestCombinationPack.ARM = armorList[a];
                    bestCombinationPack.ACC = accessoryList[acc];
                }
            }
        }
    }

    return bestCombinationPack;

}
