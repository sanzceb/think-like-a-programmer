# Exercise 3.9 [Highest Monthly Period Sales]

## Problem Statement
Consider this modification of the sales array: Because salespeople come and
go throughout the year, we are now marking months prior to a sales agent’s
hiring, or after a sales agent’s last month, with a –1. Rewrite your highest
sales average, or highest sales median, code to compensate.


## Data Structures Analysis
The given input is a multidimensional array of integers where the first dimension is the number of agents and the last dimension is the number of months. `int sales[NUM_AGENTS][NUM_MONTHS]`.

The target values are two scalars of class `double`. The highest median, and the highest average.

## Approach
To solve this problem, I initially planned it this way.

* Solve simple search problem of finding the first -1
* Solve simple search of finding the first number that is not -1
* Solve a copy problem to create a sub array from the first non -1 to 
last non -1
* Put all together with the sales agent problem.

I started the first problem

```cpp
#include <iostream>

using std::cout;

int main() {
    const int ARRAY_SIZE = 10;
    int tenIntegerArray[ARRAY_SIZE] = {...};

    int minusOnePos = 0;
    while (minusOnePos < ARRAY_SIZE && tenIntegerArray[minusOnePos] != -1) {
        minusOnePos++;
    }

    cout << "The position of " << tenIntegerArray[minusOnePos] 
        << " is " << minusOnePos << '\n';
}
```

But then in the middle of the implementation, I realized that `qsort` will put all the -1 at the beginning and my previous program to solve exercise 3-4 would not work. This made me realize that my previous implementation of the median was not good (it sorted the array, and made unnecesary copies). Fortunately I found a much simpler solution that my initial plan.

1. Sort the array with `qsort` to put all the months without sales at the beginning.
2. Simple search of the first sales month.
3. Copy the sales month into a sub-array.
4. Calculate median and the average of the sub-array.
5. Reuse the Criterion-Based Search to find the highest median and average

At this point, all of this sub problems were easily solvable having done all of the previous exercises.

## Final thoughts
Having a tough time with the quartiles problem, it felt rewarding solving this problem fast! 

The quartile ranges problem gave me the skill to intuitively solve the search problem and from then I had just to review the previous agent solution and improve it. Also looking at my previous solution of the sales agents , I can notice the skill I have gained just a few exercises later!

Let's see what happens with the pointers. I have the temptation at this point to go through the previous exercises again and improve them, but I think I will get more benefit if I move on.
