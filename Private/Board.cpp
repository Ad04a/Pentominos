#include "../Public/Board.h"

#include "../Public/Figure.h"

Board::Board(int x, int y)
{
    this->x = x;
    this->y = y;
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

    colorCodes.insert({empty, "\033[38;5;231m"});


    vector<vector<Coordinate>> layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(4,0)}, // --
        {Coordinate(0,1), Coordinate(0,2), Coordinate(0,3), Coordinate(0,4)}  // I
    };
    pentominos.push_back(new Figure(layout, 'I'));
    colorCodes.insert({'I', "\033[38;5;196m"});


    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(0,1), Coordinate(0,2)}, // 
        {Coordinate(1,0), Coordinate(2,0), Coordinate(2,1), Coordinate(2,2)}, // 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(1,2), Coordinate(2,2)}, // 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,2), Coordinate(-2,2)}  // V
    };
    pentominos.push_back(new Figure(layout, 'V'));
    colorCodes.insert({'V', "\033[38;5;201m"});


    layout = {
        {Coordinate(0,1), Coordinate(1,0), Coordinate(2,0), Coordinate(2,1)}, // ^
        {Coordinate(1,0), Coordinate(0,1), Coordinate(0,2), Coordinate(1,2)}, // <
        {Coordinate(1,0), Coordinate(1,1), Coordinate(1,2), Coordinate(0,2)}, // >
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(2,0)}  // U
    };
    pentominos.push_back(new Figure(layout, 'U'));
    colorCodes.insert({'U', "\033[38;5;136m"});




    layout = {
        {Coordinate(-1,1), Coordinate(0,1), Coordinate(1,1), Coordinate(0,2)} // X
    };
    pentominos.push_back(new Figure(layout, 'X'));
    colorCodes.insert({'X', "\033[38;5;6m"});

    
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
            if(y+block.y<0 || y+block.y>=this->y || x+block.x<0 || x+block.x>=this->x || board[y+block.y][x+block.x] != empty)
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
    if(pentominoIndex > pentominos.size()-1 || board[y][x] != empty)
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
    placedPentominos.insert({pentominos[pentominoIndex], Coordinate(x,y)});

    return true;
}

bool Board::tryFit(int x, int y)
{
    int k=0;

    for(int j =0 ;j<this->y; j++)
    {
        for(int i=0; i<this->x; i++)
        {
            placeNode(i, j, k) ? k++ : k;
        }
    }
}

bool Board::solve()
{

    tryFit(0,0);
    
}

ostream& operator<< (ostream& outs, const Board& obj )
{
    char empty = obj.getEmpty();
    char fill = obj.getFill();
    map<char, string> colors = obj.getColors();

    for(vector<char> row : obj.getBoard())
    {
        for(int k=0; k<2; k++)
        {
            for(char unit : row)
            {
                if(unit != empty)
                {
                    outs<<colors[unit]<<fill<<fill;
                    continue;
                }

                outs<<colors[empty]<<fill<<fill;

            }
            outs<<endl;
        }

    }
	return outs;
}


