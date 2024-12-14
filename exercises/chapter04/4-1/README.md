# Exercise 4.1[Design Your Own: Sales History Analyzer]

## Problem Statement
Design your own: Take a problem that you already know how to solve using
 an array but that is limited by the size of the array. Rewrite the code
 to remove that limitation using a dynamically allocated array.

### Problem taken:
Consider this modification of the sales array: Because salespeople come
 and go throughout the year, we are now marking months prior to a sales
 agent’s hiring, or after a sales agent’s last month, with a –1. Rewrite
 your highest sales average, or highest sales median, code to
 compensate.

I have chosen the last version of the sales agent, because it is a
 problem that clearly benefits from dynamic sizing. The months in which
 the agents does not work for the company are marked by -1 because we
 cannot reduce the size of the array of monthly sales once is created.
 I think the program can be more efficient with a dynamic allocated
 array.However, this my first program with pointers in a really long
 time, so let's see how it goes!.


## Data Structures
I have decided to create an agent struct to encapsulate the management
 of the sales array. Now instead of using an fixed array of 12 months,
 we will use a dynamic array of integers.

```cpp
struct agentStruct { 
    int * monthlySales;
    int numMonths;
};
```

With this defined `struct`, we are working with a vector or monthly sales.
 Since it is my first exercise with pointers, I have first created a
 simple program that given a dynamic array of integers, add it a new one
 to the end. I tried to follow the approach of starting from the shell
 and a test function, then study the problem with a diagram in paper and
 finally do the implementation.

## Solution
Before working on the actual problem, I ensured that I was comfortable with
 the pointers fundamentals before starting the actual problem, so I created
 this sub problem for me.

1. Knowing how to add a new integer to a dynamic array of integers.

After implementing a simple function that solves the stated sub problem, I was
capable of implementing a simple function to add a new sale to the agent. The
 tricky part is to remember that we must keep the size updated (yes, I
 forgot it at the first try).

```cpp
void addNewSales(agentStruct * & agent, int monthlySale) {
    int * newMonthlySales = new int[agent->numMonths + 1];

    for(int i = 0; i < agent->numMonths; i++) {
        newMonthlySales[i] = agent->monthlySales[i];
    }

    newMonthlySales[agent->numMonths] = monthlySale;
    delete[] agent->monthlySales;
    agent->monthlySales = newMonthlySales;
    agent->numMonths++;
}
```
The implementation of the final solution was not too difficult, since it was a
matter to redesign the array operations to leverage usage of dynamic memory.

```cpp
// New implementation
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
        qsort(agent->monthlySales, agent->numMonths, sizeof(int),
        intCompar);

        double agentMedian = arrayMedian(agent->monthlySales,
        agent->numMonths);
        double agentAvg = arrayAverage(agent->monthlySales,
        agent->numMonths);

        if (agentMedian > highestMedian) highestMedian = agentMedian;
        if (agentAvg > highestAvg) highestAvg = agentAvg;
        delete[] agent;
    }
```

Here I included the old solution so that you can compare them and notice the
differences:

```cpp
	// Old implementation
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
```

The previous workflow was:

Sort the full array &rarr; Search for the first sale &rarr; Copy the sales
&rarr; Compute statistics

With a dynamic array, we have now simplified the process to:

Copy the sales &rarr; Sort the sales &rarr; Compute statistics

## Final Notes

I kept the problem really simple, and going beyond is now easy. For example,
there is no need of keeping a multidimensional array with arrays of twelve
months. There is no need of including months with -1 if we extend the
solution to read the sales from the user input. However, I decided to keep it
short as a first contact with pointers and spend time on new exercises, because
I was not going to solve any new problem from this point.
