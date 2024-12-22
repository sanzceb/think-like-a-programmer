#include <iostream>

using std::cout;

int main() {

    int totalCharacters = 8;
    for (int lineNum = 1; lineNum <= 4; lineNum++) {
        
        int totalSpaces = totalCharacters - lineNum * 2;

        for (int spaceNum = 1; spaceNum <= totalSpaces / 2; spaceNum++) {
            cout << ' ';
        }
        
        for (int hashNum = 1; hashNum <= totalCharacters - totalSpaces; hashNum++){
            cout << '#';
        }
                
        for (int spaceNum = 1; spaceNum <= totalSpaces / 2; spaceNum++) {
            cout << ' ';
        }

        cout << '\n';
    }

    for (int lineNum = 1; lineNum <= 4; lineNum++) {

        int totalHashes = totalCharacters - (lineNum - 1) * 2;

        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        }
        
        for (int hashNum = 1; hashNum <= totalHashes; hashNum++){
            cout << '#';
        }
        
        for (int spaceNum = 1; spaceNum < lineNum; spaceNum++) {
            cout << ' ';
        } 

        cout << '\n';
    }
    
    return 0;
}