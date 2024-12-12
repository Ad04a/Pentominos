#include <iostream>
#include <stdlib.h>

#include "Public/Board.h"

using namespace std;

int main()
{
    Board board1(5,6);

    cout<<board1;

    cout<<endl<<"---------------------------"<<endl;

    /*board1.placeNode(3, 2, 0);
    board1.placeNode(0, 0, 1);
    board1.placeNode(2, 1, 2);*/

    int k=0;

    for(int j =0 ;j<6; j++)
    {
        for(int i=0; i<5; i++)
        {
            board1.placeNode(i, j, k) ? k++ : k;
        }
    }

    cout<<board1;
    return 0;
}