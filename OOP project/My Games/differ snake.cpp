#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<windows.h>
#include <iomanip>
using namespace std;

/* -- FUNCTION PROTOTYPES -- */
void MoveSnake(int x, int y);
void AddSegment();
void NewFood();
void HitTest();
void Clock();
void Draw();
void Move();
void End();
void In();
int InSnake(int x, int y);

/* -- VARIABLES -- */
int tailXPosition = 11;
int tailYPosition = 4;
int foodXPosition;
int foodYPosition;
int snakeSize = 3;
int score = 0;
int timer = 0;
string name;

char UserInput = '\0';
char direction = 'a';

int snakeBodySegments[128][2] = {{8, 4}, {9, 4}, {10, 4}};

/* -- FUNCTIONS -- */
/* -- THREADING FUNCTIONS -- */
void Clock()
{
    while (true)
    {
    	Sleep(1000);
        timer++;
    }
}

void In()
{
    char c;

    while (true)
    {
        c = _getch();

        if (c == 'q')
        {
            End();
        }

        UserInput = c;
    }
}

/* -- SNAKE FUNCTIONS -- */
void AddSegment()
{
    snakeBodySegments[snakeSize][0] = tailXPosition;
    snakeBodySegments[snakeSize][1] = tailYPosition;
    snakeSize++;
}

int InSnake(int x, int y)
{
    for (int i = 1; i < snakeSize; i++)
    {
        if (snakeBodySegments[i][0] == x && snakeBodySegments[i][1] == y)
        {
            return 1;
        }
    }

    return 0;
}

void MoveSnake(int x, int y)
{
    tailXPosition = snakeBodySegments[snakeSize - 1][0];
    tailYPosition = snakeBodySegments[snakeSize - 1][1];

    for (int i = snakeSize - 1; i > 0; i--)
    {
        snakeBodySegments[i][0] = snakeBodySegments[i - 1][0];
        snakeBodySegments[i][1] = snakeBodySegments[i - 1][1];
    }

    snakeBodySegments[0][0] += x;
    snakeBodySegments[0][1] += y;

    UserInput = '\0';
}

/* -- OTHER FUNCTIONS -- */
void Move()
{
    if (UserInput == 'w' && direction != 's')
    {
        MoveSnake(0, -1);
        direction = 'w';
    }
    else if (UserInput == 'a' && direction != 'd')
    {
        MoveSnake(-1, 0);
        direction = 'a';
    }
    else if (UserInput == 's' && direction != 'w')
    {
        MoveSnake(0, 1);
        direction = 's';
    }
    else if (UserInput == 'd' && direction != 'a')
    {
        MoveSnake(1, 0);
        direction = 'd';
    }
    else
    {
        UserInput = direction;
        Move();
    }
}

void NewFood()
{
    int x;
    int y;

    while (true)
    {
        x = (rand() % 16) + 1;
        y = (rand() % 8) + 1;

        if (InSnake(x, y) == 0 && snakeBodySegments[0][0] != x && snakeBodySegments[0][1] != y)
        {
            break;
        }
    }

    foodXPosition = x;
    foodYPosition = y;
}

void myDesign()
{
{

    cout << "  \033[32m/###############################################################################################################\\" << endl;
    cout << "  ##\033[31m                                                                                                         \033[32m\t  ##" << endl;
    cout << "  ##\033[31m   _____      __      _     ____      __   ___    _____         _____      ____       __    __      _____\033[32m\t  ##" << endl;
    cout << "  ##\033[31m   / ____\\    /  \\    / )   (    )    () ) / __)  / ___/        / ___ \\    (    )      \\ \\  / /     / ___/\033[32m\t  ##" << endl;
    cout << "  ##\033[31m  ( (___     / /\\ \\  / /    / /\\ \\    ( (_/ /    ( (__         / /   \\_)   / /\\ \\      () \\/ ()    ( (__\033[32m\t  ##" << endl;
    cout << "  ##\033[31m   \\___ \\    ) ) ) ) ) )   ( (__) )   ()   (      ) __)       ( (  ____   ( (__) )     / _  _ \\     ) __)\033[32m\t  ##" << endl;
    cout << "  ##\033[31m       ) )  ( ( ( ( ( (     )    (    () /\\ \\    ( (          ( ( (__  )   )    (     / / \\/ \\ \\   ( (\033[32m\t  ##" << endl;
    cout << "  ##\033[31m   ___/ /   / /  \\ \\/ /    /  /\\  \\   ( (  \\ \\    \\ \\___       \\ \\__/ /   /  /\\  \\   /_/      \\_\\   \\ \\___\033[32m\t  ##" << endl;
    cout << "  ##\033[31m  /____/   (_/    \\__/    /__(  )__\\  ()_)  \\_\\    \\____\\       \\____/   /__(  )__\\ (/          \\)   \\____\\\033[32m   ##" << endl;
    cout << "  ##\033[31m                                                                                                         \033[32m\t  ##" << endl;
    cout << "  \\################################################################################################################/" << endl;
    cout << "   \\##############################################################################################################/\n" << endl;
    Sleep(100);
    system ("cls");
    
    
    cout << "            ____" << endl;
    cout << "\033[32m      _,.-'`_ o `;__,                \033[1;33m ____   _  _    ____          _  _      _    \n";
    cout << "\033[32m       _.-'` '---'  '                \033[1;33m|  _ \\ (_)| |  |  _ \\        (_)| |    | |\n";
    cout << "\033[32m                    ____             \033[1;33m| |_) | _ | |_ | |_) | _   _  _ | |  __| |\n";
    cout << "\033[32m                 .'`_ o `;__,        \033[1;33m|  _ < | || __||  _ < | | | || || | / _` | / _ \\| '__|\n";
    cout << "\033[32m       .       .'.'` '---'`  '       \033[1;33m| |_) || || |_ | |_) || |_| || || || (_| ||  __/| |   \n";
    cout << "\033[32m       .`-...-'.'                    \033[1;33m|____/ |_| \\__||____/  \\__,_||_||_| \\__,_| \\___||_|   \n";   
    cout << "\033[32m        `-...-'                      \033[1;33m _____                    _               _    _     \n";
    cout << "\033[32m                        _,.--.       \033[1;33m|  __ \\                  | |             | |  (_) \n";
    cout << "\033[32m    --..,_           .'`__ o  `;__   \033[1;33m| |__) | _ __   ___    __| | _   _   ___ | |_  _   ___   _ __   ___\n";
    cout << "\033[32m       `'.'.       .'.'`  '---'`  '  \033[1;33m|  ___/ | '__| / _ \\  / _` || | | | / __|| __|| | / _ \\ | '_ \\ / __|\n";
    cout << "\033[32m          '.`-...-'.'                \033[1;33m| |     | |   | (_) || (_| || |_| || (__ | |_ | || (_) || | | |\\__ \\\n";
    cout << "\033[32m            `-...-'                  \033[1;33m|_|     |_|    \\___/  \\__,_| \\__,_| \\___| \\__||_| \\___/ |_| |_|\\___/\n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
 
    cout << "\t\t\t\t\t\033[0;33m+-------------------+\033[0;0m\n";
    cout << "\t\t\t\t\t\033[0;33m| Enter Your Name:  |\033[0;0m\n";
    cout << "\t\t\t\t\t\033[0;33m+-------------------+\033[0;0m\n";
    getline(cin,name);
    
}
}

/*
void Draw()
{
    system("cls");
    cout << "(Press Q to quit)\nScore: " << score << " - Time: " << timer << "\n";

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 18; x++)
        {
            if (y == 0 || y == 9 || x == 0 || x == 17)
            {
                cout << "[]";
            }
            else if (x == snakeBodySegments[0][0] && y == snakeBodySegments[0][1])
            {
                cout << "\033[0;32m()\033[0;0m";
            }
            else if (InSnake(x, y))
            {
                cout << "\033[0;34m[]\033[0;0m";
            }
            else if (x == foodXPosition && y == foodYPosition)
            {
                cout << "\033[0;31m()\033[0;0m";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
*/
void Draw()
{
    system("cls");

    
    cout << endl;
    
    cout << "\t\t\t\t\t\033[34m+-------------------------------------+\n";
    cout << "\t\t\t\t\t\033[34m| Player Name: " << setw(15) << right << "\033[33m" << name << "\033[34m|\n";
    cout << "\t\t\t\t\t\033[34m+-------------------------------------+\n";

    cout << "\t\t\t\t\t\033[34m+--------------+\033[0m\t\t\033[34m+---------------+\033[0m\n";
    cout << "\t\t\t\t\t\033[34m| Score: \033[33m" << setw(4) << score << " \033[34m |\t\t\033[34m| Time: \033[33m" << setw(8) << timer << "\033[34m|\033[0m\n";
    cout << "\t\t\t\t\t\033[34m+--------------+\033[0m\t\t\033[34m+---------------+\033[0m\n";

/*
    cout << "\t\t\t\t\t\033[34m+--------------+;
    cout << "\t\t\t\t\t\033[34m| Time: " << "\033[33m" << time << "\033[34m      |\n";
    cout << "\t\t\t\t\t\033[34m+--------------+\n";
	
*/
    for (int y = 0; y < 20; y++)  // Increase y boundary to 20
    {
        for (int x = 0; x < 30; x++)  // Increase x boundary to 30
        {
            if (y == 0 || y == 19 || x == 0 || x == 29)  // Draw top, bottom, left, and right walls
            {
                cout << "\033[34m[]";
            }
            else if (x == snakeBodySegments[0][0] && y == snakeBodySegments[0][1])
            {
                cout << "\033[32m()\033[0m";
            }
            else if (InSnake(x, y))
            {
                cout << "\033[34m[]\033[0m";
            }
            else if (x == foodXPosition && y == foodYPosition)
            {
                cout << "\033[31m()\033[0m";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    // Display the "Press Q to quit" message with a box design
    cout << "\033[0;33m+-----------------------+\033[0;0m\n";
    cout << "\033[0;33m|   Press Q to quit     |\033[0;0m\n";
    cout << "\033[0;33m+-----------------------+\033[0;0m\n";
}


void End()
{
    cout << "\033[13B\033[?25h";
    exit(0);
}

void HitTest()
{
    if (foodXPosition == snakeBodySegments[0][0] && foodYPosition == snakeBodySegments[0][1])
    {
        score++;
        AddSegment();
        NewFood();
    }
    else if (snakeBodySegments[0][1] == 0 || snakeBodySegments[0][1] == 9 || snakeBodySegments[0][0] == 0 || snakeBodySegments[0][0] == 17)
    {
        End();
    }
    else if (InSnake(snakeBodySegments[0][0], snakeBodySegments[0][1]))
    {
        End();
    }
}

/* -- MAIN ENTRY POINT -- */
int main()
{
    myDesign();
    cout << "\033[?25l";
    srand(time(NULL));
    NewFood();

    thread inputThread(In);
    thread clockThread(Clock);

    while (true)
    {
        Sleep(100);
        Move();
        Draw();
        HitTest();
    }

    End();
    return 0;
}

