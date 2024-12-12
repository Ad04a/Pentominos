#pragma once


#include <iostream>
#include <vector>
#include <map>

#include "Figure.h"

using namespace std;


class Board
{

private:

    vector<Figure*> pentominos;

    vector<vector<char>> board;

    map<Figure*, Coordinate> placedPentominos;

    char empty = ' ';
    char fill = 206;

public:

    Board(int x, int y);

    vector<Coordinate> canPlace(int x, int y, unsigned int pentominoIndex, int& pentaminoPlacement);

    bool placeNode(int x, int y, unsigned int pentominoIndex);

    vector<vector<char>> getBoard() const {return board;}

    char getFill()const {return fill;}
    char getEmpty()const {return empty;}

};

ostream& operator<< (ostream& outs, const Board& obj );