#include "Combat.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "RandomUtil.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

// TODO... be more clear about how much defense is working...

// Starts combat loop... If win returns 1, if lose returns a 0.
int combatStart(Player& player, Enemy& enemy) {
	
	int invLoop{1};
	int turn{0};
	std::string input;
	int initP = randomInt(2, 4);
	int initE = randomInt(1, 4);

	if (initP > initE) {

		// Player goes first
		turn = 1;

	}
	else {

		// Enemy goes first
		turn = 0;

	}

	std::cout << "Player has " << player.getHealth() << " health, " << player.getDamage() << " damage, "
				<< player.getAccuracy() << " accuracy, " << player.getDefense() << " defense\n";
	std::cout << "Enemy has " << enemy.getHealth() << " health, " << enemy.getDamage() << " damage, "
				<< enemy.getAccuracy() << " accuracy.\n";

	std::string effectName = "none";
	int effect = 0;

	while (invLoop == 1) {

		if (turn == 1) {
			
			std::cout << "Player Turn.\nCommands: Attack, Use\n";
			std::cin >> input;
			input = stringLower(input);

			if (input == "attack") {
				
				std::cout << "Player attacks.\n";
				//randomInt(1, 10);
				if (player.getAccuracy() >= randomInt(1, 10)) {
					
					enemy.takeDamage(player.getDamage());

					if (enemy.getHealth() < 0) {
						enemy.setHealth(0);
					}

					std::cout << "Player hits. Enemy takes " << player.getDamage() << " damage. Enemy has " <<
						enemy.getHealth() << " health.\n";

				}
				else {

					std::cout << "Player misses.\n";

				}

				turn = 0;
				if (effect > 0) {
					effect--;
				}
				
			}
			else if (input == "use") {

				if (effect == 0) {

					std::vector<Item*>& items = player.getInventory().getItems();

					std::cout << "Which potion? healing, damage, accuracy, or defense? ";
					std::cin >> input;
					int inputNum = player.getInventory().processInputSafe(input);
					if (inputNum != -1) {

						effectName = items.at(inputNum)->drink(player);

						player.getInventory().remove(inputNum);

						if (effectName != "healing") {

							effect = 3;

						}
						else {
							effectName = "none";
							if (effect > 0) {
								effect--;
							}
						}

						turn = 0;

					}

				}
				else {

					std::cout << "A potion effect already active.\n";

				}

			}

			

			if (effect == 0 && effectName != "none") {

				if (effectName == "damage") {

					player.setDamage(player.getDamage() - 4);
					std::cout << "Damage potion worn off.\n";

				}
				if (effectName == "defense") {

					player.setDefense(player.getDefense() - 5);
					std::cout << "Defense potion worn off.\n";

				}
				else if (effectName == "accuracy") {

					
					player.setAccuracy(player.getAccuracy() - 2);
					std::cout << "Accuracy potion worn off.\n";

				}

				effectName = "none";

			}

		}
		else if (turn == 0) {
			std::cout << "Enemy Turn.\n";
			// Enemy attack
			std::cout << "Enemy attacks.\n";
			if (enemy.getAccuracy() >= randomInt(1, 10)) {
				
				int dmg = enemy.getDamage() - player.getDefense();
				if (dmg < 0) {
					dmg = 0;
				}
				player.takeDamage(dmg);
				
				std::cout << "Enemy hits. Player takes " << (enemy.getDamage() - player.getDefense()) << " damage. Player has " <<
							player.getHealth() << " health.\n";

			}
			else {

				std::cout << "Enemy misses.\n";

			}

			turn = 1;

		}

		if (enemy.getHealth() <= 0) {

			return 1; //Player wins

		}
		else if (player.getHealth() <= 0) {

			return 0; //Player loses

		}

		std::cout << "Next turn. ---------\n";

	}

	return 0; //placeholder

}

std::string stringLower(std::string input) {

	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return input;
}