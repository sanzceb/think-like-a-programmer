# Exercise 4.10: Sum Digits Linked Lists

## Problem Statement

For the digit list of the previous exercise, write a function that takes two
such lists and produces a new list representing their sum.

## Data structures & Definitions

```cpp
struct listNode {
    int number;
    listNode * next;
};

typedef listNode * intList;
```

Here is the signature of the funcion that we will implement. It takes two
`intList` and produces a new list that contains the digits of the sum:

```cpp
void sum(intList list1, intList list2, intList& output);
```

The function can be broken down into three clear steps:

1. Transform from `intList` to integers the two input lists.

2. Sum the produced integers.

3. Transform the integer sum to a `intList`.

Taking the function `intToList` implemented in the [past exercise][4-9], we
only need to figure out how to transform a given `intList` to an `int`. To do
that we can look back at the online processing problem of chapter 2 that reads
a stream of digit characters and store them in an integer. Setting that problem
aside, we can already propose a possible implementation for the `sum` function:

```cpp
void sum(intList list1, intList list2, intList& output) {
    int op1 = listToInt(list1);
    int op2 = listToInt(list2);
    output = intToList(op1 + op2);
}
```

To make the implementation of `sum` work, we have to implement the proposed
`listToInt` function to solve how to obtain the integers:

```cpp
int listToInt(intList list1);
```

## Solution Overview

After taking the steps described in the previous sections here is the code:

```cpp
int listToInt(intList list1) { //[1]
    int output = 0;
    listNode * loopPtr = list1;
    while (loopPtr != NULL) {
        output *= 10; //[2]
        output += loopPtr->number;
        loopPtr = loopPtr->next;
    }    
    return output;
}

void sum(intList list1, intList list2, intList& output) {
    int op1 = listToInt(list1);
    int op2 = listToInt(list2);
    output = intToList(op1 + op2); //[3]
}
```

[1]. The function must look familiar, because `listToInt` is a list traversal
operation where to compute the output we need to retrieve all the nodes of the
list.

[2]. The calculation of the integer is a simplified version of the program that
read from a [stream of characters][dec-to-bin]. For `intToList` we divided the
integer to shift the digits to the right. This time, we do the opposite to shift
the numbers to the left; perform a multiplication.

[3]. We reuse the function implemented [previously][4-9] to represent the digits
list of the sum.

## Final thoughts

The chapter 4 has been completed. It has been easier than I thought it would. I
think the learning progress has been great so far. I have been able to keep up
with the increase of difficulty. The experience acquired during the previous
chapters has been crucial to achieve it. Having the possibility of relying upon
written programs, of establishing analogies,and of breaking down the problems
methodically has facilitated the solution of these problems a lot. I expect more
of the same good learning experience in the upcoming chapter: **Classes**. I
can't wait to solve those problems too!.

<!--Links-->
[4-9]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter02/exercises/chapter04/4-9)
[dec-to-bin]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter02/exercises/chapter02/2-6/dec-to-bin/main.cpp#L18)
