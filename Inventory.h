#pragma once
#include "ITEM.h"
#include <vector>

class Inventory {

	private:

		std::vector<Item*> items;

	public:

		void add(Item* item);
		void remove(int itemNum);
		void interface();
		int size();
		void clear();

};