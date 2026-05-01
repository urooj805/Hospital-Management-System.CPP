#include <iostream>
#include <windows.h>
using namespace std;
//function prototype
void printmaze();
void moveplayerDown();
void moveplayerUp();
void moveplayerLeft();
void moveplayerRight();
void printplayer(int playerx, int playery);
void eraseplayer(int playerx, int playery);
void gotoxy(int x, int y);//initializing the starting position
int playerx = 4 ;//player of x cod
int playery = 4 ;//player of ycod 
main()
{
    bool gamerunning = true;
    system ("cls");
    printmaze();
    gotoxy(playerx, playery);
    cout<<"p";
    while (gamerunning)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
           moveplayerLeft();
       }
        if (GetAsyncKeyState(VK_RIGHT))
    {
         {
            moveplayerRight();
        }

    }
     if (GetAsyncKeyState(VK_UP))
    { {
            moveplayerUp();
        }

    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        {
            moveplayerDown();
        }

    }
     if (GetAsyncKeyState(VK_ESCAPE))
    {
        gamerunning = false;

    }
        Sleep(200);
    }
}
void printmaze()
{
    cout<<"*************************************************************"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*                                                           *"<<endl;
    cout<<"*************************************************************"<<endl;
}
void printplayer(int playerx, int playery)
{
gotoxy(playerx,playery);
cout<<"P";
}
void eraseplayer(int playerx, int playery)
{
gotoxy(playerx,playery);
cout<<"  ";
}
char getCharAtxy(short int x, short int y)//read character function  . they say dont dont devle in the detail of it
{
 CHAR_INFO ci;
 COORD xy = {0, 0};
 SMALL_RECT rect = {x, y, x, y};
 COORD coordBufSize;
 coordBufSize.X = 1;
 coordBufSize.Y = 1;
 return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize , xy , &rect) ? ci.Char.AsciiChar: ' ';
}

void moveplayerLeft()
{
char nextLocation = getCharAtxy(playerx - 1, playery);
if (nextLocation ==' ')
{
 eraseplayer(playerx, playery);
playerx = playerx - 1;
printplayer (playerx, playery);
}
}

void moveplayerRight()
{
char nextLocation = getCharAtxy(playerx + 1, playery);
if (nextLocation ==' ')
{
eraseplayer(playerx, playery);
playerx = playerx + 1;
printplayer (playerx, playery);
}
}

void moveplayerUp()
{
char nextLocation = getCharAtxy(playerx, playery - 1);
if (nextLocation ==' ')
{
eraseplayer(playerx, playery);
playerx = playery - 1;
printplayer (playerx, playery);
}
}
void moveplayerDown()
{
char nextLocation = getCharAtxy(playerx, playery + 1);
if (nextLocation ==' ')
{
eraseplayer(playerx, playery);
playerx = playery + 1;
printplayer (playerx, playery);

}
}

                                 