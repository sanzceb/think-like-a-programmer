#include <iostream>

using std::cout;

void print_hashes(int n) {
    for (int i = 1; i <= n; i++) cout << '#';
}

void print_spaces(int n) {
    for (int i = 1; i <= n; i++) cout << ' ';
}

int main() {

    for (int lineNum = 1; lineNum <= 4; lineNum++) {
 
        print_spaces(9 - 2 * lineNum);
        print_hashes(4 * lineNum - 2);
        print_spaces(9 - 2 * lineNum);      
        cout << '\n';       
    }

    print_hashes(16);
    cout << '\n';

    for (int lineNum = 6; lineNum <= 7; lineNum++) {

        print_hashes(18 - 2 * lineNum);
        print_spaces(4 * lineNum - 20); 
        print_hashes(18 - 2 * lineNum);
        cout << '\n';              
    }

    for (int lineNum = 8; lineNum <= 10; lineNum++) {

        print_hashes(11 - lineNum);
        print_spaces(3);   
        print_hashes(2 * lineNum - 12);
        print_spaces(3);    
        print_hashes(11 - lineNum);
        cout << '\n';              
    }
   
    for (int lineNum = 11; lineNum <= 12; lineNum++) {

        print_hashes(lineNum - 9);
        print_spaces(3);     
        print_hashes(28 - 2 * lineNum);
        print_spaces(3);  
        print_hashes(lineNum - 9);
        cout << '\n';              
    }

    for (int lineNum = 13; lineNum <= 14; lineNum++) {

        print_hashes(2 * lineNum - 22);
        print_spaces(60 - 4 * lineNum);
        print_hashes(2 * lineNum - 22);
        cout << '\n';              
    }

    print_hashes(16);
    cout << '\n';

    for (int lineNum = 16; lineNum <= 20; lineNum++) {

        print_spaces(2 * lineNum - 31);
        print_hashes(78 - 4 * lineNum);
        print_spaces(2 * lineNum - 31);        
        cout << '\n';
    }

    return 0;
}
