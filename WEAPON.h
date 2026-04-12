#pragma once
#include "ITEM.h"
#include <string>

class Weapon : public Item {

	private:
		
		int damage;
		int accuracy;
		// add attack speed maybe for variance of weapons?

	public:

		//Constructor
		Weapon(std::string itemName, std::string itemType, int weaponDmg, int accuracy);

		//Member Functions

		//Polymorphism Functions
		void inspect() override;
		void use(Player& player) override;

		//Getters
		int getDmg();
		int getAcc();

};