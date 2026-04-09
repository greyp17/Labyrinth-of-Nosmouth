#pragma once
#include <string>

class Item {

	private:

		std::string name;

	public:

		//Constructor
		Item(std::string itemName);

		//Member Functions

		//Polymorphism Functions
		virtual void inspect() = 0;
		virtual void use() = 0;

		//Getters
		std::string getName();

};
