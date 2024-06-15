#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PlayerProfile {
    string name;
    int wins = 0;
    int losses = 0;
    int longestWinningStreak = 0;
};

class TicTacToe {
private:
    char board[3][3];
    PlayerProfile players[2];
    int currentPlayerIndex = 0;
    int totalGames = 0;

public:
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() {
        cout << "   1   2   3" << endl;
        cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "   ---------" << endl;
        cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "   ---------" << endl;
        cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    }

    void updateScore(int winnerIndex) {
        int loserIndex = (winnerIndex == 0) ? 1 : 0;

        players[winnerIndex].wins++;
        players[loserIndex].losses++;

        if (players[winnerIndex].wins > players[winnerIndex].longestWinningStreak) {
            players[winnerIndex].longestWinningStreak = players[winnerIndex].wins;
        }

        players[0].wins = players[1].wins = 0;
    }

    bool checkWin(char symbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
                return true;
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
                return true;
        }

        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
            return true;
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
            return true;

        return false;
    }

    bool checkTie() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
            return false;

        char symbol = (currentPlayerIndex == 0) ? 'X' : 'O';
        board[row][col] = symbol;
        return true;
    }

    void switchPlayer() {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    void playGame() {
        cout << "Enter Player 1's Name: ";
        cin >> players[0].name;
        cout << "Enter Player 2's Name: ";
        cin >> players[1].name;

        displayBoard();
        while (true) {
            cout << players[currentPlayerIndex].name << "'s Turn (" << ((currentPlayerIndex == 0) ? 'X' : 'O') << ")" << endl;
            int row, col;
            cout << "Enter the row and column to place your symbol (e.g., 1 2): ";
            cin >> row >> col;

            if (row == -1 || col == -1) {
                break;
            }

            row--;
            col--;

            if (!makeMove(row, col)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            displayBoard();

            if (checkWin('X')) {
                cout << players[0].name << " wins!" << endl;
                updateScore(0);
                totalGames++;
                displayScoreboard();
                resetBoard();
            } else if (checkWin('O')) {
                cout << players[1].name << " wins!" << endl;
                updateScore(1);
                totalGames++;
                displayScoreboard();
                resetBoard();
            } else if (checkTie()) {
                cout << "It's a tie!" << endl;
                totalGames++;
                displayScoreboard();
                resetBoard();
            }

            switchPlayer();
        }
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayScoreboard() {
        cout << "----- Scoreboard -----" << endl;
        for (int i = 0; i < 2; ++i) {
            cout << players[i].name << "'s Record: " << players[i].wins << " Wins, " << players[i].losses << " Losses, Longest Winning Streak: " << players[i].longestWinningStreak << endl;
        }
        cout << "Total Games Played: " << totalGames << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

