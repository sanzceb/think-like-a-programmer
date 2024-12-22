# Exercise 3.2: [Median Sales Finder]

## Problem Statement
Rewrite the code that finds the agent with the best monthly sales average so  
 that it finds the agent with the highest median sales. As stated earlier, the  
 median of a set of values is the “one in the middle,” such that half of the   
 other values are higher and half of the other values are lower. If there is  
 an even number of values, the median is the simple average of the two values  
 in the middle. For example, in the set 10, 6, 2, 14, 7, 9, the values in the  
 middle are 7 and 9. The average of 7 and 9 is 8, so 8 is the median.

## Approach
With a focus on sticking to the basic operations taught in the book, I have  
defined the following subproblems to implement the median.

### Best Montly sales average
Here I have rewritten the code of the Best Monthly average to have it as a  
baseline and for getting a better understanding of the problem.

```cpp
        #include <iostream>

        using std::cout;

        const int NUM_MONTHS = 12;

        struct structAgent {
            int monthlySales[NUM_MONTHS];
        };

        double arrayAverage(int intArray[], int ARRAY_SIZE) {
            double sum = 0;
            for (int i = 0; i < ARRAY_SIZE; i++) sum += intArray[i];
            return sum / ARRAY_SIZE;
        }

        int main() {
            const int NUM_AGENTS = 3;
            structAgent sales[NUM_AGENTS] = {
                {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
                {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
                {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
            };

            double highestAverage = arrayAverage(sales[0].monthlySales, NUM_MONTHS);
            for (int agent = 1; agent < NUM_AGENTS; agent++) {
                double agentAverage = arrayAverage(sales[agent].monthlySales, NUM_MONTHS);
                if (agentAverage > highestAverage) highestAverage = agentAverage;
            }

            cout << "Highest monthly average: " << highestAverage << "\n";

            return 0;
        }
```

#### Output
`Highest monthly average: 43220.5`

### Highest median for even sales
After rewriting and studying the monthly average problem, the median problem  
solution emerged quite naturally following these sequence of operations.

1. Create a working copy of the array
2. Sort the working copy
3. If the array is even, calculate the average of the middle numbers  
with `arrayAverage`. If the array is uneven, take the middle number.

```cpp
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
```

#### Output
`Highest monthly median: 4872`

## Final Notes
I have chosen avoiding the matrix because I am more comfortable  
with the dimension reduction that defining the agent struct offers.
