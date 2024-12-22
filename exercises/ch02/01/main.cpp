#include <iostream>

using std::cout;

int main() {

    for (int lineNum = 1; lineNum <= 4; lineNum ++) {
        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 10 - 2 * lineNum; hashNum++){
            cout << '#';
        }
        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        } 
        cout << '\n';
    }

    return 0;
}