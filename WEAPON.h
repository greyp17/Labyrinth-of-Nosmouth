#pragma once
#include "ITEM.h"

class Weapon : public Item {

	private:
		
		std::string type = "weapon";
		int damage;
		// add attack speed maybe for variance of weapons?

	public:

		//Constructor
		Weapon(std::string itemName, int weaponDmg);

		//Member Functions

		//Getters
		int getDmg();
		std::string getType();

};