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
- Student ID is a number so that makes the hash implementation easier.
- The internal structure uses an array, a structure that at this point is
relatively easy to work with.
- The search operation is trivial since it makes use of random access.

They key considerations are:

- When inserting elements, do *resizing* each time the *load factor* is reached.
- Resizing means allocating a more memory and then storing the existing
elements in the new array. <!--TODO add reference to grokking algorithms-->
- To store the existing elements, we need to reapply the hash function.

```cpp
int symbolTable::hash(int stuNum) {
    return stuNum % _size;
}
```

Implementation Plan:

1. Reuse the test case of exercise 3 and adapt it. Make it work with the
default `_size`.
2. Implementation of a basic hash function and the search function. The
`addRecord` will just call the hash function and store the student.
3. Make `addRecord` support resizing. Extend the basic test case to insert
up to 100 elements and force multiple resizing.

## Solution Analysis

Here is the definition of the symbol table implementation:

```cpp
class symbolTable {
public:
    // Constructors
    symbolTable();
    symbolTable(int size);
    symbolTable(const symbolTable& original);

    ~symbolTable();

    symbolTable & operator=(const symbolTable & rhs);

    // Support Methods
    void addRecord(int stuNum, int grade); //[1]
    studentRecord record(int stuNum); //[2]
private:
    typedef studentRecord * studentArray; //[3]
    
    const static int LOAD_FACTOR = 7; //[4]
    const static int RESIZE_FACTOR = 2; //[5]
    
    int _count; //[6]
    int _size;
    studentArray _studentArray;
    
    bool requiresResize();
    int hash(int stuNum); //[7]
    studentArray copiedArray(const studentArray & original);
};
```

[1], [2] These methods are the basic operations of the abstract data type. It
allows to insert and retrieve records.

[3] The internal structure uses a dynamic array, which is the data structure
that will support the hash table along with the hash function. [7]

[4], [5] These constants are set the adjust the resizing of the hash table.
They have been set based on common rules of thumb. (See pp 90-91
Grokking Algorithms).

[6] We keep count of the inserted elements to know when is moment to resize.

## Final Notes

This exercise has helped me to consolidate my understanding of hash tables even
with this very basic implementation. I struggled a bit with a bug that happened
because dummy students where being rehashed. I should take more care of
addressing edge cases better in the future.
