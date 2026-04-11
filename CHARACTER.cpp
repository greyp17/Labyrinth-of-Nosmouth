#include "CHARACTER.h"
#include <iostream>

//Constructor
Character::Character(std::string characterName) {
	name = characterName;
}

//Member Functions
void Character::takeDamage(int damage) {
	health -= damage;
}

void Character::healHealth(int heal) {
	health += heal;
}

//Position Getters
int Character::getCharacterX() {
	return xPosition;
}

int Character::getCharacterY() {
	return yPosition;
}

//Name Getter
std::string Character::getCharacterName() {
	return name;
}

//HP Getter
int Character::getCharacterHP() {
	return health;
}
