#include "LootTable.h"
#include "ITEM.h"
#include "ARMOR.h"
#include "WEAPON.h"
#include "POTION.h"
#include "RandomUtil.h"

Item* generateLoot() {

	int rand = randomInt(1, 20);

	switch (rand) {

		// Potions
		case 1:
			return new Potion("healing", "potion");

		case 2:
			return new Potion("healing", "potion");

		case 3:
			return new Potion("damage", "potion");

		case 4:
			return new Potion("defense", "potion");

		case 5:
			return new Potion("accuracy", "potion");

		// Weapons
		case 6:
			return new Weapon("dagger", "weapon", 7, 10);

		case 7:
			return new Weapon("sword", "weapon", 9, 8);

		case 8:
			return new Weapon("club", "weapon", 11, 6);

		case 9:
			return new Weapon("rapier", "weapon", 8, 10);

		case 10:
			return new Weapon("axe", "weapon", 10, 7);

		case 11:
			return new Weapon("saber", "weapon", 8, 9);

		case 12:
			return new Weapon("mace", "weapon", 11, 6);

		case 13:
			return new Weapon("spear", "weapon", 8, 9);

		// Armor
		case 14:
			return new Armor("cloth", "armor", 1);

		case 15:
			return new Armor("leather", "armor", 2);

		case 16:
			return new Armor("reinforced", "armor", 3);

		case 17:
			return new Armor("iron", "armor", 4);

		case 18:
			return new Armor("chain", "armor", 5);
		
		// Rare Weapons (Just high roll)
		case 19:
			return new Weapon("balanced", "weapon", 9, 9);

		case 20:
			return new Weapon("heavy", "weapon", 11, 7);
		}

	return nullptr;
}