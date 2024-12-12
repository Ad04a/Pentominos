#pragma once


#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "Figure.h"

using namespace std;


class Board
{

private:

    vector<Figure*> pentominos;

    vector<vector<char>> board;

    map<char, string> colorCodes;

    int x;
    int y;
    char empty = ' ';
    char fill = 219;//206 - 219;

    vector<Coordinate> canPlace(int x, int y, Figure* pentominoToCheck);

    bool tryFit(int x, int y, map<Figure*, Coordinate> alreadyPlaced);

public:

    Board(int x, int y);

    
    Coordinate placeNode(int x, int y, Figure* pentominoToCheck);
    bool solve();

    inline vector<vector<char>> getBoard() const {return board;}
    inline map<char, string> getColors() const {return colorCodes;}
    inline char getFill()const {return fill;}
    inline char getEmpty()const {return empty;}

};

ostream& operator<< (ostream& outs, const Board& obj );