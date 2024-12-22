#include <iostream>

using std::cout;

int intCompar(const void * voidA, const void * voidB) {
    int * intA = (int *) voidA;
    int * intB = (int *) voidB;
    return *intA - *intB;
}

double arrayAverage(int intArray[], int ARRAY_SIZE) {
    double sum = 0;
    if (ARRAY_SIZE == 0) return 0;
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

struct agentStruct { 
    int * monthlySales;
    int numMonths;
};

void addNewMonthlySale(agentStruct * & agent, int monthlySale) {
    int * newMonthlySales = new int[agent->numMonths + 1];

    for(int i = 0; i < agent->numMonths; i++) {
        newMonthlySales[i] = agent->monthlySales[i];
    }

    newMonthlySales[agent->numMonths] = monthlySale;
    delete[] agent->monthlySales;
    agent->monthlySales = newMonthlySales;
    agent->numMonths++;
}

int main() {
    const int NUM_AGENTS = 3, NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, -1},
        {-1, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, -1},
        {-1, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, -1}
     };

    double highestMedian = 0, highestAvg = 0;
    for (int agentNum = 0; agentNum < NUM_AGENTS; agentNum++) {
        agentStruct * agent = new agentStruct;
        agent->monthlySales = new int[0]; agent->numMonths = 0;

        // We add only the actual monthly sales
        for (int month = 0; month < NUM_MONTHS; month++) {
            if(sales[agentNum][month] != -1) {
                addNewMonthlySale(agent, sales[agentNum][month]);
            }
        }
	
        // We only sort now the filtered values
        qsort(agent->monthlySales, agent->numMonths, sizeof(int), intCompar);
        
        double agentMedian = arrayMedian(agent->monthlySales, agent->numMonths);
        double agentAvg = arrayAverage(agent->monthlySales, agent->numMonths);
        
        if (agentMedian > highestMedian) highestMedian = agentMedian;
        if (agentAvg > highestAvg) highestAvg = agentAvg;
        delete[] agent;
    }

    cout << "Highest monthly median: " << highestMedian << "\n";
    cout << "Highest monthly average: " << highestAvg << "\n";

    return 0;
}
