#pragma once

#include <vector>

using namespace std;

struct Coordinate
{
    int x;
    int y;

    Coordinate(int x=-1, int y=-1) : x(x), y(y){}

    inline bool operator==(Coordinate a) {
       return a.x==x && a.y== y;
    }

    inline bool operator!=(Coordinate a) {
       return !(operator==(a));
    }
};

class Figure
{

private:

    vector<vector<Coordinate>> posiblePlacements;

    char symbol;

    

public:

    int currentPlacement;

    Figure(vector<vector<Coordinate>> posiblePlacements, char symbol);

    inline vector<vector<Coordinate>> getPosiblePlacements(){return posiblePlacements;}
    inline char getSymbol(){return symbol;}
   
    
};