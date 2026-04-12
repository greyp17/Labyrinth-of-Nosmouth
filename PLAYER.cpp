#include "PLAYER.h"
#include "CHARACTER.h"
#include "Inventory.h"
#include <iostream>
#include "WEAPON.h"
#include "ARMOR.h"

Player::Player(std::string name) : Character( name ) {
    // constructor implementation
    
    // Starter equipment
    inventory.add(new Weapon("knife", "weapon", 6, 8));

}

//Member Functions

Inventory& Player::getInventory() {
    return inventory;
}

void Player::invAdd(Item* item) {

    //Add items to inventory through player... player picks up -> add to inventory
    inventory.add(item);

}

