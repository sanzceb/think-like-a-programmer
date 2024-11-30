#include <iostream>

using std::cout;

int main() {

    for (int lineNum = 1; lineNum <= 4; lineNum++) {

        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        }

        for (int hashNum = 1; hashNum <= lineNum; hashNum++) {
            cout << '#';
        }

        for (int spaceNum = 1; spaceNum <= 16 - 4 * lineNum; spaceNum++) {
            cout << ' ';
        }

        for (int hashNum = 1; hashNum <= lineNum; hashNum++) {
            cout << '#';
        }

        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        }

        cout << '\n';
    }

    for (int lineNum = 5; lineNum <= 8; lineNum++) {

        for (int spaceNum = 1; spaceNum < 9 - lineNum; spaceNum++) {
            cout << ' ';
        }

        for (int hashNum = 1; hashNum <= 9 - lineNum; hashNum++) {
            cout << '#';
        }

        for (int spaceNum = 1; spaceNum <= 4 * lineNum - 20; spaceNum++) {
            cout << ' ';
        }
        
        for (int hashNum = 1; hashNum <= 9 - lineNum; hashNum++) {
            cout << '#';
        }

        for (int spaceNum = 1; spaceNum < 9 - lineNum; spaceNum++) {
            cout << ' ';
        }
        
        cout << '\n';
    }
    
    return 0;
}