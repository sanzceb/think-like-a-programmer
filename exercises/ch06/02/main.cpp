#include <iostream>
#include <cassert>

using std::cout;
using std::string;

bool iterativeHasOddParity(string binaryString) {
    int strLen = binaryString.size();
    int onesCount = 0;
    for (int i = 0; i < strLen; i++) {
        if(binaryString[i] == '1') 
            onesCount++;
    }
    return (onesCount % 2) == 1;
}

bool hasOddParity(string binaryStr) {
    // Trivial case, one bit
    if (binaryStr.size() == 1) {
        return binaryStr[0] == '1';
    }
    bool hasSubstrOddParity = hasOddParity(binaryStr.substr(1));    
    bool isFirstBitOne = (binaryStr[0] == '1');
    if (isFirstBitOne) return !hasSubstrOddParity;
    else return hasSubstrOddParity;
}


//Note: The test cases are AI generated
void iterativeTester() {

    string test1 = "1010101";  // 4 ones - should return false
    cout << "\nTest 1 - String \"" << test1 << "\": " << 
        (iterativeHasOddParity(test1) ? "Has odd parity" : "Has even parity");
    assert(iterativeHasOddParity(test1) == false);

    string test2 = "11110000";  // 4 ones - should return false
    cout << "\nTest 2 - String \"" << test2 << "\": " << 
        (iterativeHasOddParity(test2) ? "Has odd parity" : "Has even parity");
    assert(iterativeHasOddParity(test2) == false);

    string test3 = "0010000";  // 1 one - should return true
    cout << "\nTest 3 - String \"" << test3 << "\": " << 
        (iterativeHasOddParity(test3) ? "Has odd parity" : "Has even parity");
    assert(iterativeHasOddParity(test3) == true);

    string test4 = "0000000";  // 0 ones - should return false
    cout << "\nTest 4 - String \"" << test4 << "\": " << 
        (iterativeHasOddParity(test4) ? "Has odd parity" : "Has even parity");
    assert(iterativeHasOddParity(test4) == false);

    string test5 = "1111111";  // 7 ones - should return true
    cout << "\nTest 5 - String \"" << test5 << "\": " << 
        (iterativeHasOddParity(test5) ? "Has odd parity" : "Has even parity");
    assert(iterativeHasOddParity(test5) == true);

    cout << "\n\nAll test cases passed successfully!\n";
}

void recursiveTester() {
    string test1 = "1010101";  // 4 ones - should return false
    cout << "\nTest 1 - String \"" << test1 << "\": " << 
        (hasOddParity(test1) ? "Has odd parity" : "Has even parity");
    assert(hasOddParity(test1) == false);

    string test2 = "11110000";  // 4 ones - should return false
    cout << "\nTest 2 - String \"" << test2 << "\": " << 
        (hasOddParity(test2) ? "Has odd parity" : "Has even parity");
    assert(hasOddParity(test2) == false);

    string test3 = "0010000";  // 1 one - should return true
    cout << "\nTest 3 - String \"" << test3 << "\": " << 
        (hasOddParity(test3) ? "Has odd parity" : "Has even parity");
    assert(hasOddParity(test3) == true);

    string test4 = "0000000";  // 0 ones - should return false
    cout << "\nTest 4 - String \"" << test4 << "\": " << 
        (hasOddParity(test4) ? "Has odd parity" : "Has even parity");
    assert(hasOddParity(test4) == false);

    string test5 = "1111111";  // 7 ones - should return true
    cout << "\nTest 5 - String \"" << test5 << "\": " << 
        (hasOddParity(test5) ? "Has odd parity" : "Has even parity");
    assert(hasOddParity(test5) == true);

    cout << "\n\nAll test cases passed successfully!\n";
}


int main (){
    cout << "Testing iterative version:";
    iterativeTester();
    cout << "Testing recursive version:";
    recursiveTester();
}

