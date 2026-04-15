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

void Character::setHealth(int inputHealth) {
	health = inputHealth;
}

void Character::setDefense(int inputDefense) {
	defense = inputDefense;
}

void Character::setDamage(int inputDamage) {

	damage = inputDamage;

}

void Character::setAccuracy(int inputAccuracy) {

	accuracy = inputAccuracy;

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
int Character::getHealth() {

	return health;

}

int Character::getDamage() {

	return damage;

}
int Character::getDefense() {

	return defense;

}
int Character::getAccuracy() {

	return accuracy;

}