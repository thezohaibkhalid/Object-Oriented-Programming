#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

class SnakeGame {
private:
    int tailXPosition;
    int tailYPosition;
    int foodXPosition;
    int foodYPosition;
    int snakeSize;
    int score;
    char UserInput;
    char direction;
    int snakeBodySegments[128][2];
    int length = 15;
    int width = 30;
    string player;

public:

    void thePlayer(const string a){
        this->player = a;

    }

    SnakeGame() {
        tailXPosition = 11;
        tailYPosition = 4;
        foodXPosition = 0;
        foodYPosition = 0;
        snakeSize = 3;
        score = 0;
        UserInput = '\0';
        direction = 'a';

        for (int i = 0; i < 128; i++) {
            snakeBodySegments[i][0] = 0;
            snakeBodySegments[i][1] = 0;
        }
        snakeBodySegments[0][0] = 8;
        snakeBodySegments[0][1] = 4;
        snakeBodySegments[1][0] = 9;
        snakeBodySegments[1][1] = 4;
        snakeBodySegments[2][0] = 10;
        snakeBodySegments[2][1] = 4;
    }

    void In() {
        char c;

        while (true) {
            c = _getch();

            if (c == 'q') {
                End();
            }

            UserInput = c;
        }
    }

    void AddSegment() {
        snakeBodySegments[snakeSize][0] = tailXPosition;
        snakeBodySegments[snakeSize][1] = tailYPosition;
        tailXPosition = snakeBodySegments[snakeSize - 1][0];
        tailYPosition = snakeBodySegments[snakeSize - 1][1];
        snakeSize++;
    }

    int InSnake(int x, int y) {
        for (int i = 1; i < snakeSize; i++) {
            if (snakeBodySegments[i][0] == x && snakeBodySegments[i][1] == y) {
                return 1;
            }
        }
        return 0;
    }

void MoveSnake(int x, int y) {
    // ...

    for (int i = snakeSize - 1; i > 0; i--) {
        snakeBodySegments[i][0] = snakeBodySegments[i - 1][0];
        snakeBodySegments[i][1] = snakeBodySegments[i - 1][1];
    }

    // Make sure the new head position is within the dimensions of the game board
    snakeBodySegments[0][0] = (snakeBodySegments[0][0] + x + width) % width;
    snakeBodySegments[0][1] = (snakeBodySegments[0][1] + y + length) % length;

    UserInput = '\0';
}


    void HitTest() {
        for (int i = 0; i < snakeSize; i++) {
            if (foodXPosition == snakeBodySegments[i][0] && foodYPosition == snakeBodySegments[i][1]) {
                score++;
                AddSegment();
                NewFood();  // Generate new food
            }
        }

        if (snakeBodySegments[0][1] == 0 || snakeBodySegments[0][1] == length - 1 || snakeBodySegments[0][0] == 0 || snakeBodySegments[0][0] == width - 1) {
            End();
        } else if (InSnake(snakeBodySegments[0][0], snakeBodySegments[0][1])) {
            End();
        }
    }

void NewFood() {
    int x, y;

    while (true) {
        x = rand() % width;
        y = rand() % length;

        if (!InSnake(x, y)) {
            foodXPosition = x;
            foodYPosition = y;
            break;
        }
    }
}
void Run() {
    while (true) {
        ClearScreen();
        PrintGameBoard();
        HitTest();
        this->Move();  // Call the Move() function in the SnakeGame class
        In();
        Sleep(250);
    }
}

void PrintGameBoard() {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == length - 1 || j == 0 || j == width - 1) {
                cout << "#";
            } else {
                for (int k = 0; k < snakeSize; k++) {
                    if (snakeBodySegments[k][0] == j && snakeBodySegments[k][1] == i) {
                        cout << "O";
                        break;
                    }
                }
                if (k == snakeSize) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    cout << "Score: " << setw(4) << score << endl;
    cout << "Player: " << player << endl;
}



    void End() {
        cout << "Game Over!" << endl;
        exit(0);
    }
};

int main() {
    SnakeGame game;
    game.NewFood();  // Generate initial food
    game.Run();
    return 0;
}
