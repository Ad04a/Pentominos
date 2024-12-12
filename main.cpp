#include <iostream>
#include <stdlib.h>

#include "Public/Board.h"

using namespace std;

int main()
{
    Board board1(15,4);

    int tries;
    bool solved = board1.solve(tries);

    if(solved)
    {
        cout<<board1;
    }else
    {
        cout<<"No ";
    }
    
    cout<< "Solution found in "<< tries<<" tries";
    

    //Coordinate p = board1.placeNode(4,4,board1.getPentominos()[3],0);

    //board1.removeNode(p.x, p.y, board1.getPentominos()[3]->getPosiblePlacements()[0]);

    
    return 0;
}