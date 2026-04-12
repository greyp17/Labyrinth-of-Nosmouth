#pragma once
#include "ITEM.h"
#include <vector>

class Player;

class Inventory {

	private:

		std::vector<Item*> items;
		std::string armor = "None";
		std::string weapon = "knife";
		int currentDamage{6};
		int currentDefense{0};
		int currentAccuracy{8};

	public:

		//Deconstructor
		~Inventory();
		
		void display();
		void add(Item* item);
		void remove(int itemNum);
		void interface(Player& player);
		void clear();
		int element(std::string itemName);
		std::string stringLower(std::string input);
		int processInput(std::string input);

		

};