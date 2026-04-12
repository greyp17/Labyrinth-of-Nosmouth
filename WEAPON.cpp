#include "WEAPON.h"
#include "PLAYER.h"
#include <iostream>

//Constructor
Weapon::Weapon(std::string itemName, std::string itemType, int weaponDmg, int acc) : Item(itemName, itemType) {
	
	damage = weaponDmg;
	accuracy = acc;

}

//Member Functions

//Polymorphism Functions
void Weapon::inspect() {
	
	//gives stats of weapon
	std::cout << "Accuracy: " << accuracy << "\nDamage: " << damage << "\n";

}

void Weapon::use(Player& player) {

	//equips weapon
	std::string input = getName();
	std::cout << "Equipping " << input << " weapon...\n";
	player.setDamage(getDmg());
	player.setAccuracy(getAcc());


}

//Getters
int Weapon::getDmg() {

	return damage;

}
int Weapon::getAcc() {

	return accuracy;

}


