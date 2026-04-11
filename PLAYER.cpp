#include "PLAYER.h"
#include "CHARACTER.h"
#include "Inventory.h"
#include <iostream>

Player::Player(std::string name, Inventory inventory) : Character{ name } {
    // constructor implementation
    setInventory(inventory);
}

//Member Functions, inventory etc...
void Player::setInventory(Inventory inventory) {
    this->inventory = inventory;
}

Inventory Player::getInventory() {
    return inventory;
}