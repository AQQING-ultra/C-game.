#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int x = 15;
int y = 15;

void eraseQ();
void maze();
void maze2();
void gotoxy(int x, int y);
int movement();
void printQ();
void right_movement();
void left_movement();
void jump_movement();
void triggerHole();
void checkFall();
void checkDoor();
void lvl2();
void fallingRock(int startX);
void lvl3();
void train();
void points();
int main()
{
    system("cls");
    system("Color C0");
    maze();
    points();
    gotoxy(1, 5);
    cout << "LVL 1";
    printQ();
    int coin = 0;
    while (true)
    {
        movement();
        Sleep(100);
        triggerHole();
        checkFall();
        checkDoor();
        if((x == 7 && y == 11)||(x == 17 && y == 8)||(x == 56 && y == 15)||(x == 22 && y == 15)||(x == 47 && y == 9)||(x == 57 && y == 7)||(x == 67 && y == 5)||(x == 77 && y == 13)||(x == 88 && y == 12)||(x == 99 && y == 14)||(x == 109 && y == 10))
        {
            coin = coin + 10;
            gotoxy(3,6);
            cout << "Money = "<< coin <<"$";
            Sleep(2000);
        }
        if (x >= 113 && x <= 114 && y == 15)
        {
            gotoxy(1, 18);
            cout << "Moving to the next level!";
            Sleep(2000);
            cout.flush();
            system("cls");
            break; // Exit Level 1 loop
        }
    }
    lvl2();

    return 0;
}
void points()
{
    gotoxy(7 , 11);
    cout<<"$";
    gotoxy(17 , 8);
    cout<<"$";
    gotoxy(56 , 15);
    cout<<"$";
    gotoxy(22 , 15);
    cout<<"$";
    gotoxy(47 , 9);
    cout<<"$";
    gotoxy(57 , 7);
    cout<<"$";
    gotoxy( 67, 5);
    cout<<"$";
    gotoxy(77 , 13);
    cout<<"$";
    gotoxy(88 , 12);
    cout<<"$";
    gotoxy(99 , 14);
    cout<<"$";
    gotoxy(109 , 10);
    cout<<"$";   
}

void maze()
{
    gotoxy(0, 1);
    cout << ":>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:" << endl;
    cout << ":<                                            LEVEL DEVIL GAMEPLAY                                                    >:" << endl;
    cout << ":<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<:" << endl;
    gotoxy(1, 14);
    cout << "                                                                                                               |+-+|";
    gotoxy(1, 15);
    cout << "                                                                                                               |+-+|";
    gotoxy(1, 16);
    cout << "=====================================================================================================================";
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int movement()
{

    if (GetAsyncKeyState(VK_LEFT))
    {
        left_movement();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        right_movement();
    }
    if (GetAsyncKeyState(VK_UP))
    {
        jump_movement();
    }
}
void eraseQ()
{
    gotoxy(x, y);
    cout << " ";
}
void printQ()
{
    gotoxy(x, y);
    cout << "@";
}
void right_movement()
{
    eraseQ();
    x = x + 1;
    printQ();
}
void left_movement()
{
    eraseQ();
    x = x - 1;
    printQ();
}
void jump_movement()
{
    eraseQ();
    y = y - 1;
    printQ();
    Sleep(100);
    movement();
    Sleep(100);
    movement();
    Sleep(100);
    eraseQ();
    y = y + 1;
    printQ();
}
void triggerHole()
{

    if (x == 19)
    {
        gotoxy(22, 16);
        cout << " ";
    }
    if (x == 53)
    {
        gotoxy(56, 16);
        cout << " ";
    }
}
bool isHoleBelow()
{
    return ((x == 22) || (x == 56));
}

void checkFall()
{
    if (y == 15 && isHoleBelow())
    {
        for (int k = 0; k < 3; k++)
        {
            eraseQ();
            y++;
            system("Color 74");
            Beep(500, 300);
            printQ();
            Sleep(300);
        }
        gotoxy(1, 10);
        cout << "You fell into a hole and died! Press esc key to quit and any other key to restart...";
        cout.flush();

        Sleep(2000);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        _getch();
        int key = _getch();
        if (key == 27)
        {
            exit(0);
        }
        else
        {
            system("cls");
            x = 1;
            y = 15;
            maze();
            printQ();
        }
    }
}

void checkDoor()
{
    if (x >= 113 && x <= 114 && y == 14)
    {
        gotoxy(1, 18);
        system("Color D5");
        cout << "Moving to the next level!";
        Sleep(2000);
        cout.flush();
        system("cls");
    }
}
void train()
{
    int ty = 15;
    int tx = 0;
    for (tx = 1; tx < 114; tx++)
    {
        gotoxy(tx, ty);
        cout << "###";
        Sleep(50);
        gotoxy(tx, ty);
        cout << "   ";
        int m = tx + 3;
        if (m == x && ty == y)
        {
            gotoxy(1, 10);
            cout << "You were hit by a moving rocK and you died! Press ESC to quit or any other key to restart...";
            cout.flush();
            Sleep(1000);
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            _getch();
            int key = _getch();
            if (key == 27)
                exit(0);
            else
            {
                system("cls");
                lvl2();
                return;
            }
        }
    }
}
void maze2()
{
    points();
	system("Color C0");
    gotoxy(0, 1);
    cout << ":>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>:" << endl;
    cout << ":<                                            LEVEL DEVIL GAMEPLAY                                                    >:" << endl;
    cout << ":<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<:" << endl;
    for (int a = 4; a < 16; a++)
    {
        if (a < 10 && a > 7)
        {
            continue;
        }
        gotoxy(18, a);
        cout << "##";
        gotoxy(50, a);
        cout << "##";
        gotoxy(70, a);
        cout << "##";
    }
    gotoxy(1, 14);
    cout << "                                                                                                               |+-+|";
    gotoxy(1, 15);
    cout << "                                                                                                               |+-+|";
    gotoxy(1, 16);
    cout << "=====================================================================================================================";
}
void lvl2()
{
    x = 1;
    y = 15;
    maze2();
    gotoxy(1, 5);
    cout << "LVL 2";
    printQ();

    int rockY = 4;
    const int rockX = 35;

    while (true)
    {

        while (true)
        {
            train();
            for(int w = 0 ; w < 15 ; w++)
            {
                movement();
                Sleep(50);
                triggerHole();
                checkFall();
                checkDoor();
                gotoxy(rockX,rockY );
                cout << "   ";
                Sleep(300);
                int rock_y = rockY + 1;
                gotoxy(rockX, rock_y);
                cout << "###";
                rockY++;
                if (x >= rockX && x <= rockX + 2 && y == rockY)
                {
                    gotoxy(1, 10);
                    cout << "You were crushed by a rock! Press ESC to quit or any other key to restart...";
                    cout.flush();
                    Sleep(1000);
                    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                    _getch();
                    int key = _getch();
                    if (key == 27)
                        exit(0);
                    else
                    {
                        system("cls");
                        lvl2();
                        return;
                    }
                }

                if (rockY > 15)
                {
                    gotoxy(rockX, rockY - 1);
                    cout << "   ";
                    rockY = 4;
                }
                movement();

                if (x >= 113 && x <= 114 && y == 15)
                {
                    gotoxy(1, 18);
                    cout << "Level 2 complete! Now go to studey game is over.";
                    Sleep(2000);
                    system("cls");
                    return;
                
                }
            }
            
        }
    }
}