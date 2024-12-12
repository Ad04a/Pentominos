#pragma once

#include <vector>

using namespace std;

struct Coordinate
{
    int x;
    int y;

    Coordinate(int x, int y) : x(x), y(y){}
};

class Figure
{

private:

    vector<vector<Coordinate>> posiblePlacements;

    char symbol;

    int currentPlacement;

public:

    Figure(vector<vector<Coordinate>> posiblePlacements, char symbol);


    inline vector<vector<Coordinate>> getPosiblePlacements(){return posiblePlacements;}
    inline char getSymbol(){return symbol;}
    inline void setPlacement(int placementIndex){currentPlacement = placementIndex;}
    
};