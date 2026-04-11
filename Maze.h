#pragma once
#include <iostream>
#include <vector>
#include <random>

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
    std::vector<std::vector<int>> getMapArray() const;

private:
    int height = 0;
    int width = 0;

    std::vector<std::vector<int>> mapArray;

    int visitedCells = 0;
};