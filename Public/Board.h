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

    map<Figure*, Coordinate> placedPentominos;

    map<char, string> colorCodes;

    char empty = ' ';
    char fill = 219;//206 - 219;

public:

    Board(int x, int y);

    vector<Coordinate> canPlace(int x, int y, unsigned int pentominoIndex, int& pentaminoPlacement);

    bool placeNode(int x, int y, unsigned int pentominoIndex);

    inline vector<vector<char>> getBoard() const {return board;}
    inline map<char, string> getColors() const {return colorCodes;}
    inline char getFill()const {return fill;}
    inline char getEmpty()const {return empty;}

};

ostream& operator<< (ostream& outs, const Board& obj );