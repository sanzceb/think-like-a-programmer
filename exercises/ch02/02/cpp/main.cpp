#include <iostream>

using std::cout;

int main() {
    for (int row = 1; row <= 4; row++) {
            for (int spaceNum = 1; spaceNum <= 4 - row; spaceNum++) {
               cout << ' ';
            }
            for (int hashNum = 1; hashNum <= row * 2; hashNum++) {
                cout << '#';
            }
            cout << '\n';
    }

    for (int row = 1; row <= 4; row++){
        for (int spaceNum = 1; spaceNum < row; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++){
            cout << '#';
        }
        cout << '\n';
    }
}