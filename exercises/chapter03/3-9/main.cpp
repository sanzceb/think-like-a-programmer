#include <iostream>

using std::cout;


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
    if (ARRAY_SIZE % 2 == 0) {
        return (intArray[ARRAY_SIZE / 2 - 1] 
            + intArray[ARRAY_SIZE / 2]) / 2; 
    }
    else return intArray[ARRAY_SIZE / 2];
}

int main() {
    const int NUM_AGENTS = 3, NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, -1},
        {-1, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, -1},
        {-1, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, -1}
     };

    double highestMedian = 0, highestAvg = 0;
    for (int agent = 0; agent < NUM_AGENTS; agent++) {

        // Sorting first will put all the -1 at the beginning
        qsort(sales[agent], NUM_MONTHS, sizeof(int), intCompar);
        
        // Simple Search of the first month of sales
        int firstMonthSales = 0;
        while (firstMonthSales < NUM_MONTHS && 
            sales[agent][firstMonthSales] == -1) {
            firstMonthSales++;
        }

        // Array copy to resize
        const int SALES_SIZE = NUM_MONTHS - firstMonthSales;
        int realMonthlySales[SALES_SIZE];
        for (int i = 0; i < SALES_SIZE; i++) {
            realMonthlySales[i] = sales[agent][firstMonthSales + i];
        }        
        
        double agentMedian = arrayMedian(realMonthlySales, SALES_SIZE);
        double agentAvg = arrayAverage(realMonthlySales, SALES_SIZE);
        
        if (agentMedian > highestMedian) highestMedian = agentMedian;
        if (agentAvg > highestAvg) highestAvg = agentAvg;
    }

    cout << "Highest monthly median: " << highestMedian << "\n";
    cout << "Highest monthly average: " << highestAvg << "\n";

    return 0;
}