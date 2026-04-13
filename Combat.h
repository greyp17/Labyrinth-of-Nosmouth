#pragma once
#include <string>

class Player;
class Enemy;

std::string stringLower(std::string input);
int combatStart(Player& player, Enemy& enemy);
