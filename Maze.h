
#pragma once
#include <iostream>
#include <vector>
#include <random>


class Maze {
public:
    int Random_Gen(int mapArray[][25], int mapHeight, int mapWidth);
    int Print_Map(int mapArray[][25], int mapHeight, int mapWidth);
private:

    static constexpr int EasyHeight = 25;
    static constexpr int EasyWidth = 50;
    static constexpr int MediumHeight = 25;
    static constexpr int MediumWidth = 75;
    static constexpr int HardHeight = 25;
    static constexpr int HardWidth = 100;

};
