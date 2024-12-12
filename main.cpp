#include <iostream>
#include <stdlib.h>

#include "Public/Board.h"

using namespace std;

int main()
{
    Board board1(10,10);

    cout<<board1;

    cout<<endl<<"---------------------------"<<endl;

    board1.solve();

    cout<<board1;
    return 0;
}