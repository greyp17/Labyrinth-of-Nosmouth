#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "PLAYER.h"

// start garrison work
class Maze {
public:
    int Random_Gen(int height, int width);
    void Print_Map();

    bool isWalkable(int r, int c) const;
    bool isValid(int r, int c) const;

    void setMazeHeight(int h);
    void setMazeWidth(int w);
    int getMazeHeight();
    int getMazeWidth();

    void setMapArray(const std::vector<std::vector<int>>& mapArray);
    void setMapArrayValue(int height, int width, int value);
	int getMapArrayValue(int height, int width) const;

    std::vector<std::vector<int>> getMapArray() const;

    void triggerChest();

private:
    int height = 0;
    int width = 0;

    std::vector<std::vector<int>> mapArray;

    int visitedCells = 0;

    Player player;
};
// end garrison work