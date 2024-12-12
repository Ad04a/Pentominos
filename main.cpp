#include <iostream>
#include <stdlib.h>

#include "Public/Board.h"

using namespace std;

void blockUnit(int width, int height, Board* boardPtr)
{
    int x = -1;
    int y = -1;
    
    cout<<"Enter x of the unit to block: ";
    cin>>x;
    while(x<1 || x>width)
    {
        cout<<"The x must be between 0 and "<<width<<"! Enter again: ";
        cin>>x;
    }

    cout<<"Enter y of the unit to block: ";
    cin>>y;
    while(y<1 || y>height)
    {
        cout<<"The y must be between 0 and "<<height<<"! Enter again: ";
        cin>>y;
    }

    boardPtr->blockNode(x-1,height-y);
}

void solveCustomBoard()
{
    int x = -1;
    int y = -1;
    
    cout<<"Enter width of the field: ";
    cin>>x;
    while(x<3 || x>100)
    {
        cout<<"The width must be between 3 and 100! Enter again: ";
        cin>>x;
    }

    cout<<"Enter height of the field: ";
    cin>>y;
    while(y<3 || y>100)
    {
        cout<<"The height must be between 3 and 100! Enter again: ";
        cin>>y;
    }

    Board board = Board(x,y);

    bool drawing = true;
    char option;
    while(drawing)
    {   
        cout<<"Current board:\n"<<board;
        cout<<"What to do?\n";
        cout<<"   (1) bloack a unit\n";
        cout<<"   (2) solve\n";
        cout<<">>";

        cin>>option;
        switch(option)
        {
            case '1': blockUnit(x,y,&board); break;
            case '2': drawing=false; break;
            default : cout<<"Not a valid option!\n";
        }
    }
    board.solve();
}

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
            case '5': solveCustomBoard(); break;
            case '6': return 0;
            default: cout<<"Not a valid option!!"<<endl;
        }

    }

    
    return 0;
}