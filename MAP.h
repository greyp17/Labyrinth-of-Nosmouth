//Grey code start here
#pragma once
#include <iostream>
#include <vector>
#include <random>

class MAP {
public:
    int difficulty = 1;
    int RunGame();
	int Play_again = 0;
    int NewGame();
    int playerHP = 100;
    int Game_Run = 0;
};

//Grey code end here
