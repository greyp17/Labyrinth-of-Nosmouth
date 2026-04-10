#include "PLAYER.h"
#include <iostream>

//Constructor
Player::Player(std::string playerName) {

	name = playerName;

}

//Member Functions
void Player::takeDamage(int damage) {

	health -= damage;

}
void Player::healHealth(int heal) {

	health += heal;

}

//Position Getters
int Player::getPlayerX() {

	return xPosition;

}

int Player::getPlayerY() {

	return yPosition;

}
//Name Getter
std::string Player::getPlayerName() {

	return name;

}

//HP Getter
int Player::getPlayerHP() {

	return health;

}
