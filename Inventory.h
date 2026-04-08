#pragma once
#include "ITEM.h"
#include <vector>

class Inventory {

	private:

		std::vector<Item*> items;

	public:
		
		void display();
		void add(Item* item);
		void remove(int itemNum);
		void remove(std::string item);
		void interface();
		int size();
		void clear();
		int element(std::string itemName);
		int checkType(std::string input);

};