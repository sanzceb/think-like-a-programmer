# Exercise 7.2 Standard C++ list: add and average

## Problem Statement

Rewrite our studentCollection functions from Chapter 4 (addRecord and
averageRecord) so that instead of directly implementing a linked list, you
use a class from the C++ library.

## Analysis

The most analogous component to our custom component in the standard C++
library is the class [forward_list][flist]. For the implementation of
`addRecord`, we have a direct alternative with `push_front`, which inserts an
element to the beginning. For the method `averageRecord` we need an find a
component to traverse the linked list. I have made use of the [iterator][fiter]
component that the linked list contains. In page 184 of the book the `iterator`
component is explained in detail.

## Solution Plan

These are the tasks that I planned to implement the solution:

1. Take the code from Chapter 4 pp. (101-108).
2. Remove the dynamic structure.
3. Reuse the studentRecord component located in `shared`.
4. Replace the custom component used for the `studentCollection`
with the component `forward_list`.
5. Reimplement `addRecord` using the operation `push_front` of `forward_list`.
6. Reimplement the `averageRecord` using the `iterator` component.

## Solution Overview

The code block below shows the difference between the old structure with the
custom linked list and the new structure with the standard linked list:

```cpp
struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

// New implementation using forward_list
typedef std::forward_list<studentRecord> studentCollection;
```

<!-- Links -->
[flist]:(https://en.cppreference.com/w/cpp/container/forward_list)
[fiter]:(https://en.cppreference.com/w/cpp/container/forward_list/begin)
