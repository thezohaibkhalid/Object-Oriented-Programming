#include <iostream>
#include <windows.h>
#include <conio.h>  //Console input output,
using namespace std;

bool gameOver;
const int width = 20;
const int height = 30;
int x, y, fruitX, fruitY, score;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; //enumration
/*As the snake will go constantly left or right or down or up so we has no need to keep pressing
the A button to go left, so somehow we need to track the direction of snake we are using enumration for this,*/
eDirecton dir; //Maked a variable dir that will hold the direction of snake

void Setup()
{
    gameOver = false;
    dir = STOP; //SO the snake will not move untill we start moving
    /*It's simply the position of the head of the snake in the map ---> as we have divided the height and length of the snake by 2,
    so the position of snake will be 20/2=10,, and it's the center of the map both in terms of length and width*/
    x = width / 2;
    y = height / 2;
    /*We are doing this to place the fruit randomly in the map,, it will divide a random number between 0-20 and will place the
    Fruit their in the map,,.----->>> ruitX for width and fruitY for height*/
    fruitX = rand() % width;
    fruitY = rand() % height;

    score = 0;//Initializing the score to zero at the start of the game
}

/*void Draw()
{
    /*We will be drawing a map in which our game will run,
    //Drawing of map is easy as i have already drawn shapes, using arrays, in the past Semester
    system("cls"); //Clear the screen ----> It'll flicker a little bit but will do the work
    for(int i = 0; i < width+2; i++)
    {
        cout<<'#';//Printing the top wall of map

    }
    cout<<endl;
    //The map is just like printing a holo rectangle
/*
#######
#     #    ---->>Map should look like this
#     #
#######

    for(int i = 0; i< height; i++)
    {

        for(int j = 0; j < width+2; j++){
        if ( j == 0 /*|| j == width - 1)
        {
            cout<<'#';
        }{
            cout<<" ";
        }
        if (j == width - 1)
        {
            cout<<'#';
        }
    }
    cout<<endl;

    }

    for(int i = 0; i < width;  i ++)
    {
        cout<<'#';//For the bottom wall
        cout<<endl;
    }
}*/

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
    {
        cout << '#'; // Printing the top wall of the map
    }
    cout << endl;

    // The map is just like printing a hollow rectangle

//  #######
//  #     #    ---->> Map should look like this
//  #     #
//  #######


    for (int i = 0; i < height + 5; i++) // Corrected the height loop to leave space for the bottom wall
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << '#'; // Print the left and right walls
            }
            if (i == y && j == x) //if i is equal to x coordinate and j is equal to y coordinate,,,then we are going to print the head
            {
                cout << "0";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                cout << " "; // Print spaces inside the rectangle
            }
            if (j == width - 1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << '#'; // Print the bottom wall
    }
    cout << endl;
    cout << " Score: " << score << endl;
}


void Input()
{
    //We will be using two functions in this function, These are for getting the character from the console window.

    if (_kbhit()) //This will return yes, means positive answer if a button is pressed by the user.
    {
        switch (_getch())//This will return the asky value of the character that is pressed
        {
        case'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void logic()
{
    //It looks like it's difficult but if we'll understand the coordinates, Then It's very very simple.

    switch (dir)
    {
    case LEFT: //Agr snake left wali side pr move kr rha ha to woh X coordinate ki trf move kraga, iska mrlb hm snake ko shota krna k lia x-- krn ga
        x--;
        break;
    case RIGHT://Agr woh RIGHT ki trf move kr rha ha to woh coordinate sa dur ja rha ha hm uska size bra krna k lia x++ krn ga
        x++;
        break;
    case UP:
        y--;//
        break;
    case DOWN:
        y++;
        break;
    default:
        break;

    }
    //Know going to add a codition so that the game will be terminated to gameover, if the head goes outside the map,

    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }
    //Increasing the score if the snake eats the fruit.
    if (x == fruitX && y == fruitY)
        //if (abs(x - fruitX) <= 1 && abs(y - fruitY) <= 1)//trying to use range based checking.
    {
        score += 10;
        fruitX = rand() % width;  //To place the food randomly after eating it
        fruitY = rand() % height;

        //The snake wasn't eating the food and, it was'nt input the score, It was because the position of the fruit was not correct
        //It was can place the food at x or y which is the position of the snake or at the previous one,So this time we'll insure that
        //the food is'nt at the place of snake or at the place of previous food and then we'll place the food

        /*bool validFrootPosition = false;

        while(!validFrootPosition)
        {
            //Placing the food randomly
          //This loop will keep generating new random positions for the fruit until it finds a position that is
          //not the same as the snake's head position (x and y). Once it finds a valid position, the loop will exit,
          //and the new fruit position will be used.
            fruitX = rand() % width;
            fruitY = rand() % height;
            if (fruitX != x || fruitY != y)   //------------>recursion
            {
                validFrootPosition = true;
            }
        }*/
        //-------------------->There was a simple error in draw function due to which all this happened<-----------------------------
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        logic();
    }
    return 0;
}
