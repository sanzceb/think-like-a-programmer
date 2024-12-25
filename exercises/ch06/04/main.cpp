#include <iostream>

using std::cout;
// Helper function to do the test
void arraySort(int intArray[], int ARRAY_SIZE) {
    int start = 0, end = ARRAY_SIZE - 1;
    for(int i = start + 1; i <= end; i++) {
        for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--) {
            int temp = intArray[j - 1];
            intArray[j - 1] = intArray[j];
            intArray[j] = temp;
        }
    }
}

bool iterativeArraySorted(int intArray[], int ARRAY_SIZE) {
    int start = 0, end = ARRAY_SIZE - 1;
    for(int i = start + 1; i <= end; i++) {
        for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--)
            return false;
    }
    return true;
}

bool arraySorted(int intArray[], int ARRAY_SIZE) {
    if (ARRAY_SIZE == 1) return true;
    bool subArraySorted = arraySorted(intArray, ARRAY_SIZE - 1);    
    return (intArray[ARRAY_SIZE - 2] <= intArray[ARRAY_SIZE - 1]) &&
        subArraySorted;
}

int main() {
    const int ARRAY_SIZE = 8;
    int intArray[ARRAY_SIZE] = {1856, 498, 30924, 87478, 328, 2653, 387, 3754};

    cout << "Is the array sorted?: " << arraySorted(intArray, ARRAY_SIZE);
    arraySort(intArray, ARRAY_SIZE);
    cout << "\nIs the array now sorted?: " 
        << arraySorted(intArray, ARRAY_SIZE) << '\n';
}
