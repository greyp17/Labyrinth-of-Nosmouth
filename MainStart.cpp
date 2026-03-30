//Grey code starts here
#include <iostream>
#include "MAP.h"
MAP Game;
int difficulty;


int main() {
    MAP Game;
	int difficulty;
	int Game_Run = 0;
	while (Game_Run == 0) {
		std::cout << "Welcome to the Labyrinth of Nosmouth!" << "\n";
		std::cout << "Please select a difficulty level:" << "\n";
		std::cout << "Easy (1), Medium (2), Hard (3)" << "\n";
		std::cin >> difficulty;
		Game.difficulty = difficulty;
		Game.Game_Run = Game_Run;
		Game.RunGame();
		
		return 0;
	}
}
//Grey code ends here
