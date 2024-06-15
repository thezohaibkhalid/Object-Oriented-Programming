/*
Q#.12: Write a program which takes a string as an input and stores that string to a pointer. Then the user inputs if the character is there or not. If it's there, then it prints the character, else it says no character found.
*/

#include <iostream>
#include <cstring>

using namespace std;

class StringSearch {
private:
    char str[100]; // Assuming a maximum length of 100 characters
    char* ptr;

public:
    StringSearch() {
        cout << "Enter a string: ";
        cin.getline(str, sizeof(str));
        ptr = str;
    }

    void searchCharacter() {
        char target;
        cout << "Enter a character to search for: ";
        cin >> target;

        bool found = false;
        while (*ptr != '\0') {
            if (*ptr == target) {
                found = true;
                break;
            }
            ptr++;
        }

        if (found) {
            cout << "Character '" << target << "' found." << endl;
        } else {
            cout << "Character '" << target << "' not found." << endl;
        }
    }
};

int main() {
    StringSearch search;

    search.searchCharacter();

    return 0;
}
