#pragma once
#include "ITEM.h"
#include <vector>

class Inventory {

	private:

		std::vector<Item*> items;

	public:

		//Deconstructor
		~Inventory();
		
		void display();
		void add(Item* item);
		void remove(int itemNum);
		void interface();
		void clear();
		int element(std::string itemName);
		std::string stringLower(std::string input);
		int processInput(std::string input);
		

};