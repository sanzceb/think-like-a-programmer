#include <iostream>

using std::cout;

const int NUM_MONTHS = 12;

struct structAgent {
    int monthlySales[NUM_MONTHS];
};

int intCompar(const void * voidA, const void * voidB) {
    int * intA = (int *) voidA;
    int * intB = (int *) voidB;
    return *intA - *intB;
}

double arrayAverage(int intArray[], int ARRAY_SIZE) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) sum += intArray[i];
    return sum / ARRAY_SIZE;
}

double arrayMedian(int intArray[], int ARRAY_SIZE) {
    int intArrayCopy [ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) intArrayCopy[i] = intArray[i];

    qsort(intArrayCopy, ARRAY_SIZE, sizeof(int), intCompar);

    if (ARRAY_SIZE % 2 == 0) {
        int middleValues[2] = { 
            intArrayCopy[ARRAY_SIZE / 2 - 1], 
            intArrayCopy[ARRAY_SIZE / 2]
        };
        return arrayAverage(middleValues, 2); 
    }

    else return intArrayCopy[ARRAY_SIZE / 2];
}

int main() {
    const int NUM_AGENTS = 3;
    structAgent sales[NUM_AGENTS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    double highestMedian = arrayMedian(sales[0].monthlySales, NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agentMedian = arrayMedian(sales[agent].monthlySales, NUM_MONTHS);
        if (agentMedian > highestMedian) highestMedian = agentMedian;
    }

    cout << "Highest monthly median: " << highestMedian << "\n";

    return 0;
}