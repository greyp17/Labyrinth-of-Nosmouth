#pragma once
#include <string>

class Player;

class Item {

	private:

		std::string name;
		std::string type;

	public:

		//Constructor
		Item(std::string itemName, std::string itemType);

		//Member Functions

		//Polymorphism Functions
		virtual void inspect() = 0;
		virtual void use(Player& player) = 0;
		virtual int getDefense() { return 0; }
		virtual int getDmg() { return 0; }
		virtual int getAcc() { return 0; }
		virtual std::string drink(Player& player) { return "none"; }
		

		//Getters
		std::string getName();
		std::string getType();

};
