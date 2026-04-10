#pragma once
#include "ITEM.h"

class Weapon : public Item {

	private:
		
		std::string type = "weapon";
		int damage;
		int accuracy;
		// add attack speed maybe for variance of weapons?

	public:

		//Constructor
		Weapon(std::string itemName, int weaponDmg, int accuracy);

		//Member Functions

		//Polymorphism Functions
		void inspect() override;
		void use() override;

		//Getters
		int getDmg();
		std::string getType();

};