#include "WEAPON.h"
#include <iostream>

//Constructor
Weapon::Weapon(std::string itemName, int weaponDmg, int acc) : Item(itemName) {

	damage = weaponDmg;
	accuracy = acc;

}

//Member Functions

//Polymorphism Functions
void Weapon::inspect() {
	
	//gives stats of weapon
	std::cout << "Damage: " << damage << "\nAccuracy: " << accuracy << "\n";

}

void Weapon::use() {

	//equips weapon
	std::string input = getName();
	std::cout << "Equipping " << input << "...\n";

}

//Getters
int Weapon::getDmg() {

	return damage;

}

std::string Weapon::getType() {

	return type;

}
