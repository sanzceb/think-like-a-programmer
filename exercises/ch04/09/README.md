# Exercise 4.9: Digits Linked-List

## Problem Statement

Imagine a linked list where instead of the node storing a character, the node
stores a digit: an `int` in the range 0-9. We could represent positive numbers
of any size using a linked list; the number 149, for example, would be a linked
list in which the first node stores a 1, the second a 4, and the third and last
a 9. Write a function `intToList` that takes an integer value and produces a
linked list of this sort. Hint: You may find it easier to build the linked list
backward, so if the value were 149, you would create the node 9 first.

## Data structures & Definitions

The linked list that we will use for this exercise is:

```cpp
struct listNode {
    int number;
    listNode * next;
};

typedef listNode * intList;
```

The difference between this linked list and the previous [string linked list][strll] is
the payload, which this time is an integer that represents a digit. The
`typedef` has been renamed accordingly.

The signature of the function that we will implement is:

```cpp
//takes an integer value and produces its linked list
intList intToList(int number);
```

Here is a visual representation of the book's example:

```
149 becomes:
1 -> 4 -> 9
^    ^    ^
First node points to second node points to third node
```

To solve this problem, first we need to know how to extract the last digit from
a decimal number. Secondly we also need to implement how to reduce `number` on 
each step so that we can retrieve all the digits. These are problems we already
solved in previous chapters, when we were dealing with digit manipulation.
For each digit, we must allocate memory to create one node and add it to the
list. This problem was already solved in the book for the case of a linked list
of students. Here is the signature I will implement based on that example:

```cpp
void addInt(intList& intList, int number);
```

Notice that this function does not need to know about the number of digits, so
we can work on this function as a subproblem. Putting all together, these are
the problems that we will solve:

* Implement the function `addInt`.
* Given an integer extract the last digit.
* Given an integer, implement a loop that extracts all the digits.

## Solution Overview
After putting the solution of each subproblem together, here is the
implementation:

```cpp
void addInt(intList& intList, int number) { //[1]
    listNode * newInt = new listNode;
    newInt->number = number;
    newInt->next = intList;
    intList = newInt;
}

intList intToList(int number) {
    intList il = NULL;
    do {
        int digit = number % 10; //[2]
        addInt(il, digit); //[3]
        number /= 10;  //[4]
    } while (number > 0); //[5]
    return il;
}
```
[1] This function is a simplified version of the function `addRecord` that
is explained and implemented in the book's chapter. It creates the node
with the number as a payload, and adds it to the beginning of the list.

[2] The modulo 10 operation solves the problem of extracting the last digit of
a decimal integer.

[3] The extracted digit is then added as a node to the list.

[4] In the last step, the number is reduced by division by 10. It has the
effect of shifting the remaining digits to the right.

[5] The input to the function guarantees that there is at least one digit, so
we can use `do while` to emphasize that fact and avoid unnecessary condition
checks.

## Final Thoughts
This problem is another example of how the power of looking for analogies and
breaking down the problem into steps. We were able to leverage what he have
learned in previous chapters to make a non-trivial problem at a first glance a
problem that ended up being quite simple to solve.

<!--Refs & Links-->
[strll]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch04/06/README.md#data-structures--definitions)