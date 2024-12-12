#include "../Public/Board.h"

#include "../Public/Figure.h"

Board::Board(int x, int y)
{
    //board = new vector<vector<char>>();
    for(int i=0; i<y; i++)
    {
        vector<char> temp;
        for(int j=0 ; j<x; j++)
        {
            temp.push_back(empty);
        }
        board.push_back(temp);
    }


    vector<vector<Coordinate>> layout = {
        {Coordinate(-1,1), Coordinate(0,1), Coordinate(1,1), Coordinate(0,2)} // X
    };
    pentominos.push_back(new Figure(layout, 'X'));


    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(4,0)}, // I
        {Coordinate(0,1), Coordinate(0,2), Coordinate(0,3), Coordinate(0,4)}  // --
    };
    pentominos.push_back(new Figure(layout, 'I'));


    layout = {
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(2,0)}, // U
        {Coordinate(1,0), Coordinate(1,1), Coordinate(1,2), Coordinate(0,2)}, // >
        {Coordinate(0,1), Coordinate(1,0), Coordinate(2,0), Coordinate(2,1)}, // ^
        {Coordinate(1,0), Coordinate(0,1), Coordinate(0,2), Coordinate(1,2)}  // <
    };
    pentominos.push_back(new Figure(layout, 'U'));
    
}

vector<Coordinate> Board::canPlace(int x, int y, unsigned int pentominoIndex, int& pentaminoPlacement)
{
    vector<Coordinate> ValidCoordinates;
    if(pentominoIndex > pentominos.size()-1)
    {
        return ValidCoordinates;
    }

    pentaminoPlacement = 0;

    for(vector<Coordinate> position : pentominos[pentominoIndex]->getPosiblePlacements())
    {
        for(Coordinate block : position)
        {
            if(y+block.y<0 || y+block.y>=board.size() || x+block.x<0 || x+block.x>=board[0].size() || board[y+block.y][x+block.x] != empty)
            {
                break;
            }

            ValidCoordinates.push_back(Coordinate(x+block.x,y+block.y));
        }

        if(ValidCoordinates.size() == 4)
        {
            return ValidCoordinates;
        }

        ValidCoordinates.clear();
        pentaminoPlacement++;

    }
    pentaminoPlacement = -1;
    return ValidCoordinates;
}

bool Board::placeNode(int x, int y, unsigned int pentominoIndex)
{
    if(pentominoIndex > pentominos.size()-1)
    {
        return false;
    }
    int currentPlacement = -1;
    vector<Coordinate> ValidCoordinates = canPlace(x, y, pentominoIndex, currentPlacement);
    if(ValidCoordinates.empty())
    {
        return false;
    }

    board[y][x] = pentominos[pentominoIndex]->getSymbol();

    for(Coordinate valid : ValidCoordinates)
    {
        board[valid.y][valid.x] = pentominos[pentominoIndex]->getSymbol();
    }

    pentominos[pentominoIndex]->setPlacement(currentPlacement);
    //placedPentominos.insert(pentominos[pentominoIndex], Coordinate(x,y));

    return true;
}


ostream& operator<< (ostream& outs, const Board& obj )
{
    for(vector<char> row : obj.getBoard())
    {
        for(char unit : row)
        {
            if(unit != obj.getEmpty())
            {
                outs<<"\x1b[32;1m"<<unit;
                continue;
            }

            outs<<obj.getFill();

        }
        outs<<endl;
    }
	return outs;
}


