#include "WEAPON.h"

//Constructor
Weapon::Weapon(std::string itemName, int weaponDmg) : Item(itemName) {

	damage = weaponDmg;

}

//Getters
int Weapon::getDmg() {

	return damage;

}

std::string Weapon::getType() {

	return type;

}
