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

private:

    static constexpr int EasyHeight = 25;
    static constexpr int EasyWidth = 50;
    static constexpr int MediumHeight = 25;
    static constexpr int MediumWidth = 75;
    static constexpr int HardHeight = 25;
    static constexpr int HardWidth = 100;

};

//Grey code end here
