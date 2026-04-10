#pragma once
#include <string>

class Item {

	private:

		std::string name;

	public:

		//Constructor
		Item(std::string itemName);

		//default constructor for creating items without a name (for testing purposes)
		Item(){
			name = "Unnamed Item";
		}
		//Member Functions

		//Getters
		std::string getName();

};
