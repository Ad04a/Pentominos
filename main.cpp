#include <iostream>
#include <stdlib.h>

#include "Public/Board.h"

using namespace std;

int main()
{
    char option = 0;
    Board board1(0,0);
    while(true)
    {
        cout<<"What board do you want to test?\n";
        cout<<"   (1) 3x20\n";
        cout<<"   (2) 4x15\n";
        cout<<"   (3) 5x12\n";
        cout<<"   (4) 6x10\n";
        cout<<"   (5) custom\n";
        cout<<"   (6) exit\n";
        cout<<">>";

        cin>>option;
        switch(option)
        {
            case '1': Board(3,20).solve(); break;
            case '2': Board(4,15).solve(); break;
            case '3': Board(5,12).solve(); break;
            case '4': Board(6,10).solve(); break;
            case '5': Board(8,8).solve(); break;
            case '6': return 0;
            default: cout<<"Not a valid option!!"<<endl;
        }

    }

    
    return 0;
}