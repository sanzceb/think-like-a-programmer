#include <iostream>
#include <random>
#include <forward_list>
using std::cout;

typedef std::forward_list<int> intList;
typedef intList::iterator intIterator;

int main() {
    //1. Generate a number between 1 and 100
    std::random_device rd;
    std::uniform_int_distribution<> uDist(1, 100);
    std::uniform_int_distribution<> stuNumDist(1, 30000);
    intList myList;

    int count = 0;
    do {
        int newNumber = uDist(rd);
        // Simple search to avoid duplicates
        intIterator iter = myList.begin();
        while (iter != myList.end() && (*iter) != newNumber) iter++;
        if (iter == myList.end()) {
            myList.push_front(newNumber);
            count++;
        }
    } while (count < 100);
    
    intIterator iter = myList.begin();
    cout << *iter++;
    while (iter != myList.end()) {
        cout << ' ' << *iter++;
    }
    
}