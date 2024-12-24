# Exercises 6.1 Recursive Positive Sum

## Problem Statement

Write a function to compute the sum of just the positive numbers in an array
of integers. First, solve the problem using iteration. Then, using the technique
shown in this chapter, convert your iterative function to a recursive function.

## Analysis

```cpp
// Compute the sum of just the positive numbers iteratively
int iterativeArrayPosSum(int[] array, int size);

// Compute the sum of just the positive numbers recursively
int recursiveArrayPosSum(int array[], int size);

```
<!--1. Explain the technique -->
The technique explained in the book is called *The Big Recursive Idea*. It is
based on the idea of pretending that no recursion is taking place by following
certain code conventions. It is a great technique to apply when we struggle
with the understanding of the recursive solution but we can solve the problem
iteratively. To apply the technique properly, we must follow these steps:
<!--Steps -->
1. Write the iterative function.
2. Create a second function, we will refer to it as a *dispatcher*.
3. Make the dispatcher solve the most trivial case, without calling the
iterative function.
4. Make the dispatcher call the iterative function, with a smaller version of
the problem.
5. Once it is solved, make the dispatcher call itself. The solution will be
now recursive.

## Solution Overview
<!--2. Explain briefly the iterative solution-->
Here is the implementation of the iterative solution:

```cpp
// Compute the sum of just the positive numbers iteratively
int arrayPositiveSum(int intArray[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (intArray[i] > 0) { //[1]
            sum += intArray[i];
        }
    }
    return sum;
}
```

It is a simple loop that retrieves the whole array with a conditional statement
[1] to verify that the number is positive.

<!--3. Explain the technique application-->
```cpp
int recursiveArrayPosSum(int array[], int size) {
    if (size == 0) return 0; //[1] 
    int lastNum = iterativeArrayPosSum(array, size - 1); //[2]
    int last = 0;
    if (array[size - 1] > 0) {
        last = array[size - 1];
    }
    return last + lastNum; 
}
```

[1] The most trivial case of a sum problem is when there are no elements. We
return 0 by default without calling the iterative function.
[2] If the problem is bigger, we call the iterative function with a smaller
version of the problem. Reducing the problem in this case means reducing the
size of the array.

<!--4. Show the final recursive function-->
Now we are only one step ahead of the final solution. We just now replace the
call to the iterative function by a call to the function itself.

```cpp
int recursiveArrayPosSum(int array[], int size) {
    if (size == 0) return 0;    
    int lastNum = recursiveArrayPosSum(array, size - 1);
    int last = 0;
    if (array[size - 1] > 0) {
        last = array[size - 1];
    }
    return last + lastNum; 
}
```

## Final thoughts

The method described is really simple but shockingly effective! It is really
systematic so we are guaranteed to get the recursive solution if we follow the
steps properly.
