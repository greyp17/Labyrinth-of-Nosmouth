#include "WEAPON.h"

//Constructor
Weapon::Weapon(std::string itemName, int weaponDmg) : Item(itemName) {

	damage = weaponDmg;

}

//Getters
int Weapon::getWeaponDmg() {

	return damage;

}

std::string Weapon::getType() {

	return type;

}
