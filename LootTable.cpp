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
			return new Potion("Healing");

		case 2:
			return new Potion("Healing");

		case 3:
			return new Potion("Damage");

		case 4:
			return new Potion("Defense");

		case 5:
			return new Potion("Accuracy");

		// Weapons
		case 6:
			return new Weapon("Dagger", 7, 10);

		case 7:
			return new Weapon("Sword", 9, 8);

		case 8:
			return new Weapon("Club", 11, 6);  

		case 9:
			return new Weapon("Rapier", 8, 10); 

		case 10:
			return new Weapon("Axe", 10, 7);

		case 11:
			return new Weapon("Saber", 8, 9); 

		case 12:
			return new Weapon("Mace", 11, 6);   

		case 13:
			return new Weapon("Spear", 8, 9);   

		// Armor
		case 14:
			return new Armor("Cloth", 1);

		case 15:
			return new Armor("Leather", 2);

		case 16:
			return new Armor("Reinforced", 3);

		case 17:
			return new Armor("Iron", 4);

		case 18:
			return new Armor("Chain", 5);
		
		// Rare Weapons (Just high roll)
		case 19:
			return new Weapon("Balanced", 9, 9);

		case 20:
			return new Weapon("Heavy", 11, 7);
		}

}