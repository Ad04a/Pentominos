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


    //I is 1st becasue it has a 5 side
    vector<vector<Coordinate>> layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(4,0)}, // --
        {Coordinate(0,1), Coordinate(0,2), Coordinate(0,3), Coordinate(0,4)}  // I
    };
    pentominos.push_back(new Figure(layout, 'I'));
    colorCodes.insert({'I', "\033[38;5;196m"});

    //L is 2nd because it has a 4 side
    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(0,1)}, 
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(3,1)},
        {Coordinate(1,0), Coordinate(0,1), Coordinate(0,2), Coordinate(0,3)},
        {Coordinate(1,0), Coordinate(1,1), Coordinate(1,2), Coordinate(1,3)},
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(3,1)}, 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(0,3), Coordinate(1,3)}, //L
        {Coordinate(0,1), Coordinate(0,2), Coordinate(0,3), Coordinate(-1,3)},
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(-2,1), Coordinate(-3,1)}, 
    };
    pentominos.push_back(new Figure(layout, 'L'));
    colorCodes.insert({'L', "\033[38;5;21m"});

    //Y is 3rd 
    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(1,1)}, 
        {Coordinate(1,0), Coordinate(2,0), Coordinate(3,0), Coordinate(2,1)},
        {Coordinate(1,1), Coordinate(0,1), Coordinate(0,2), Coordinate(0,3)},
        {Coordinate(1,2), Coordinate(0,1), Coordinate(0,2), Coordinate(0,3)},
        {Coordinate(-1,1), Coordinate(0,1), Coordinate(1,1), Coordinate(2,1)}, 
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(0,2), Coordinate(0,3)}, //Y
        {Coordinate(0,1), Coordinate(-1,2), Coordinate(0,2), Coordinate(0,3)},
        {Coordinate(0,1), Coordinate(1,1), Coordinate(-1,1), Coordinate(-2,1)}, 
    };
    pentominos.push_back(new Figure(layout, 'Y'));
    colorCodes.insert({'Y', "\033[38;5;55m"});

    //P is 4th because it has a 3 side
    layout = {
        {Coordinate(1,0), Coordinate(0,1), Coordinate(1,1), Coordinate(2,0)}, 
        {Coordinate(1,0), Coordinate(2,1), Coordinate(1,1), Coordinate(2,0)}, 
        {Coordinate(1,0), Coordinate(0,1), Coordinate(1,1), Coordinate(0,2)}, //P
        {Coordinate(1,0), Coordinate(0,1), Coordinate(1,1), Coordinate(2,1)}, 
        {Coordinate(1,0), Coordinate(0,1), Coordinate(1,1), Coordinate(1,2)},
        {Coordinate(0,1), Coordinate(1,1), Coordinate(0,2), Coordinate(1,2)},
        {Coordinate(1,0), Coordinate(0,1), Coordinate(1,1), Coordinate(-1,1)}, 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,1), Coordinate(-1,2)}, 
    };
    pentominos.push_back(new Figure(layout, 'P'));
    colorCodes.insert({'P', "\033[38;5;121m"});


    //V is 5th
    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(0,1), Coordinate(0,2)}, // 
        {Coordinate(1,0), Coordinate(2,0), Coordinate(2,1), Coordinate(2,2)}, // 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(1,2), Coordinate(2,2)}, // 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,2), Coordinate(-2,2)}  // V
    };
    pentominos.push_back(new Figure(layout, 'V'));
    colorCodes.insert({'V', "\033[38;5;213m"});

    //U is 6th
    layout = {
        {Coordinate(0,1), Coordinate(1,0), Coordinate(2,0), Coordinate(2,1)}, // ^
        {Coordinate(1,0), Coordinate(0,1), Coordinate(0,2), Coordinate(1,2)}, // <
        {Coordinate(1,0), Coordinate(1,1), Coordinate(1,2), Coordinate(0,2)}, // >
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(2,0)}  // U
    };
    pentominos.push_back(new Figure(layout, 'U'));
    colorCodes.insert({'U', "\033[38;5;136m"});

    //T is 7th
    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(1,1), Coordinate(1,2)}, // T
        {Coordinate(0,1), Coordinate(0,2), Coordinate(1,1), Coordinate(2,1)},
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,2), Coordinate(1,2)},
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,1), Coordinate(-2,1)}
    };
    pentominos.push_back(new Figure(layout, 'T'));
    colorCodes.insert({'T', "\033[38;5;28m"});

    //N is 8th
    layout = {
        {Coordinate(1,0), Coordinate(2,0), Coordinate(2,1), Coordinate(3,1)}, 
        {Coordinate(1,0), Coordinate(1,1), Coordinate(2,1), Coordinate(3,1)}, 
        {Coordinate(0,1), Coordinate(1,1), Coordinate(1,2), Coordinate(1,3)}, 
        {Coordinate(0,1), Coordinate(0,2), Coordinate(1,2), Coordinate(1,3)},
        {Coordinate(0,1), Coordinate(1,0), Coordinate(2,0), Coordinate(-1,1)},  
        {Coordinate(0,1), Coordinate(0,2), Coordinate(-1,2), Coordinate(-1,3)}, //N
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(-1,2), Coordinate(-1,3)},
        {Coordinate(0,1), Coordinate(1,0), Coordinate(-1,1), Coordinate(-2,1)},
    };
    pentominos.push_back(new Figure(layout, 'N'));
    colorCodes.insert({'N', "\033[38;5;209m"});

    //Z is 9th because it has a 2 sie
    layout = {
        {Coordinate(1,0), Coordinate(1,1), Coordinate(1,2), Coordinate(2,2)}, // Z
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(2,2)},
        {Coordinate(1,0), Coordinate(0,1), Coordinate(0,2), Coordinate(-1,2)},
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(-2,1), Coordinate(-2,2)}
    };
    pentominos.push_back(new Figure(layout, 'Z'));
    colorCodes.insert({'Z', "\033[38;5;6m"});

    //Wis 10th
    layout = {
        {Coordinate(1,0), Coordinate(1,1), Coordinate(2,1), Coordinate(2,2)},
        {Coordinate(0,1), Coordinate(1,1), Coordinate(1,2), Coordinate(2,2)}, //W
        {Coordinate(1,0), Coordinate(0,1), Coordinate(-1,1), Coordinate(-1,2)},  
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(-1,2), Coordinate(-2,2)}, 
    };
    pentominos.push_back(new Figure(layout, 'W'));
    colorCodes.insert({'W', "\033[38;5;51m"});

    //F is 11th
    layout = {
        {Coordinate(1,0), Coordinate(1,1), Coordinate(2,1), Coordinate(1,2)}, //F
        {Coordinate(0,1), Coordinate(1,1), Coordinate(2,1), Coordinate(1,2)},
        {Coordinate(1,0), Coordinate(0,1), Coordinate(-1,1), Coordinate(0,2)},
        {Coordinate(0,1), Coordinate(1,1), Coordinate(0,2), Coordinate(-1,2)},
        {Coordinate(0,1), Coordinate(0,2), Coordinate(1,2), Coordinate(-1,1)},
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(1,1), Coordinate(1,2)},
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(1,1), Coordinate(-1,2)},
        {Coordinate(0,1), Coordinate(-1,1), Coordinate(-2,1), Coordinate(-1,2)}
    };
    pentominos.push_back(new Figure(layout, 'F'));
    colorCodes.insert({'F', "\033[38;5;191m"});

    //X is 12th because it has a 1 side
    layout = {
        {Coordinate(-1,1), Coordinate(0,1), Coordinate(1,1), Coordinate(0,2)} // X
    };
    pentominos.push_back(new Figure(layout, 'X'));
    colorCodes.insert({'X', "\033[38;5;67m"});

    
}

vector<Coordinate> Board::canPlace(int x, int y, Figure* pentominoToCheck)
{
    vector<Coordinate> ValidCoordinates;
    if(pentominoToCheck == nullptr)
    {
        return ValidCoordinates;
    }

    pentominoToCheck->currentPlacement = 0;

    for(vector<Coordinate> position : pentominoToCheck->getPosiblePlacements())
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
        pentominoToCheck->currentPlacement++;

    }
    pentominoToCheck->currentPlacement = -1;
    return ValidCoordinates;
}

Coordinate Board::placeNode(int x, int y, Figure* pentominoToCheck)
{
    if(pentominoToCheck==nullptr || board[y][x] != empty)
    {
        return Coordinate();
    }
    //int currentPlacement = -1;
    vector<Coordinate> ValidCoordinates = canPlace(x, y, pentominoToCheck);
    if(ValidCoordinates.empty())
    {
        return Coordinate();
    }

    board[y][x] = pentominoToCheck->getSymbol();

    for(Coordinate valid : ValidCoordinates)
    {
        board[valid.y][valid.x] = pentominoToCheck->getSymbol();
    }

    //pentominos[pentominoIndex]->setPlacement(currentPlacement);
    //placedPentominos.insert({pentominos[pentominoIndex], Coordinate(x,y)});

    return Coordinate(x,y);
}

bool Board::tryFit(int x, int y, map<Figure*, Coordinate> alreadyPlaced)
{

    int next_x = x+1, next_y = y;
    if(x == this->x)
    {
        x = 0;
        next_y++;
    }
    if(next_y == this->y) return alreadyPlaced.size() == pentominos.size();

    /*if(board[y][x] != empty)
    {
        return tryFit(next_x, next_y, alreadyPlaced);
    }*/

    for(int i=0; i<pentominos.size(); i++)
    {
        //if(alreadyPlaced[pentominos[i]] != Coordinate(0,0)) continue;
        //bool isPlaced = placeNode(x, y, i);
        //if(isPlaced)tryFit(next_x, next_y, alreadyPlaced)
    }


}

bool Board::solve()
{
    
    map<Figure*, Coordinate> placedPentominos;
    tryFit(0, 0, placedPentominos);
    
    int k=0;

    for(int j =0 ;j<this->y; j++)
    {
        for(int i=0; i<this->x; i++)
        {
            placeNode(i, j, pentominos[k])!=Coordinate() ? k++ : k;
        }
    }

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


