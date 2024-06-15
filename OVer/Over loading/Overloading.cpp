#include <iostream>
using namespace std;
// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    int result1 = add(5, 10);
    double result2 = add(3.14, 2.71);
    
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    
    return 0;
}
