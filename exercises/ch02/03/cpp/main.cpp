#include <iostream>

using std::cout;

int main() {
    for (int row = 1; row <= 4; row++) {
        for (int spaceNum = 1; spaceNum <= row - 1; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 16 - 4 * row; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }

    for (int row = 1; row <= 4; row++) {
        for (int spaceNum = 1; spaceNum <= 4 - row; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 5 - row; hashNum++) {
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum <= 4 * row - 4; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 5 - row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
}
