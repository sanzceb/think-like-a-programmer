# 7.4 Symbol Table

## Problem Statement

For the problem in 7-3, implement a solution by implementing an abstract
data type that allows an arbitrary number of items to be stored and individual
records to be retrieved based on a key value. A generic term for a structure
that can efficiently store and retrieve items based on a key value is a symbol
table, and common implementations of the symbol table idea are hash tables
and binary search trees.

## Analysis

I choose **hash tables** to implement the symbol table because:

- They have fast insertion and search.
- They are good for catching duplicates because the search is fast.
- The uniqueness student number makes the hash implementation easier.
- The internal structure uses an array, a structure that at this point is
relatively easy to work with.
- The search operation is trivial since it makes use of random access.

They key considerations are:

- When inserting elements, do *resizing* each time the *load factor* is reached.
- Resizing means allocating a more memory and then storing the existing
elements in the new array. <!--TODO add reference to grokking algorithms-->
- To store the existing elements, we need to reapply the hash function.
<!-- INSERT final definition here -->
```cpp
```

Implementation Plan:

1. Reuse the test case of exercise 3 and adapt it. Make it work with the
default `_size`.
2. Implementation of a basic hash function and the search function. The
`addRecord` will just call the hash function and store the student.
3. Make `addRecord` now support resizing. Extend the basic test case to insert
up to 100 elements.
4. Implement a test case to allocate as many records as possible.
5. Update the hash function to allow collisions and increase the number of
supported records to reduce the size of the array and avoid memory
fragmentation issues as much as possible without impacting the search
performance.
