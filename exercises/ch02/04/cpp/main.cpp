#include <iostream>

using std::cout;

int main() {
    // First Pyramid
    for (int row = 1; row <= 4; row++) {
        for (int spaceNum = 1; spaceNum <= 9 - 2 * row; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 4 * row - 2; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
    
    for (int row = 1; row <= 3; row++) {
        for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 4 * row - 4; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
    
    for (int row = 1; row <= 2; row++) {
        for (int hashNum = 1; hashNum <= 4 - row; hashNum++){
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 2 * row + 2; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 4 - row; hashNum++){
            cout << '#';
        }
        cout << '\n';
    }
    
    for (int row = 1; row <= 3; row++) {
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }

    for (int row = 1; row <= 3; row++) {
        for (int hashnum = 1; hashnum <= 2 * row + 2; hashnum++) {
            cout << '#';
        }
        for (int spacenum = 1; spacenum <= 12 - 4 * row; spacenum++) {
            cout << ' ';
        }
        for (int hashnum = 1; hashnum <= 2 * row + 2; hashnum++) {
            cout << '#';
        }
        cout << '\n';
    }

    // second pyramid
    for (int row = 1; row <= 4; row++) {
        for (int spacenum = 1; spacenum <= 2 * row - 1; spacenum++) {
            cout << ' ';
        }
        for (int hashnum = 1; hashnum <= 18 - 4 * row; hashnum++) {
            cout << '#';
        }
        cout << '\n';
    }
}
