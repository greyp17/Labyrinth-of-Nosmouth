#include "Headers/WEAPON.h"
#include <iostream>
//Constructor
Weapon::Weapon(std::string itemName, int weaponDmg) : Item(itemName) {

	damage = weaponDmg;

}

//Position Getters
int Weapon::getWeaponDmg() {

	return damage;

}
