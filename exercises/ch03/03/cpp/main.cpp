#include <iostream>

using std::cout;
// Basic OP: Easy-to-Modify Sorting with Insertion Sort
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

bool arraySorted(int intArray[], int ARRAY_SIZE) {
    int start = 0, end = ARRAY_SIZE - 1;
    for(int i = start + 1; i <= end; i++) {
	if (intArray[i-1] > intArray[i])
            return false;
    }
    return true;
}

int main() {
    const int ARRAY_SIZE = 8;
    int intArray[ARRAY_SIZE] = {1856, 498, 30924, 87478, 328, 2653, 387, 3754};

    cout << "Is the array sorted?: " << arraySorted(intArray, ARRAY_SIZE);
    arraySort(intArray, ARRAY_SIZE);
    cout << "\nIs the array now sorted?: " 
        << arraySorted(intArray, ARRAY_SIZE) << '\n';
}

