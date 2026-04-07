#include "PLAYER.h";
#include <iostream>

//Constructor
Player::Player(std::string playerName) {

	name = playerName;

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
