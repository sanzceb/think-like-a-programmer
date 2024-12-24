# Exercise 6.2 Recursive Parity Checker

## Problem Statement

Consider an array representing a binary string, where every element’s data
value is 0 or 1. Write a bool function to determine whether the binary string
has odd parity (an odd number of 1 bits). Hint: Remember that the recursive
function is going to return true (odd) or false (even), not the count of 1 bits.
Solve the problem first using iteration, then recursion.

## Analysis

<!-- Define the function signatures-->
```cpp
bool iterativeHasOddParity(string binaryStr);
bool hasOddParity(string binaryStr);
```

The strategy to solve the problem iteratively will be counting first the number
of ones, and then apply the modulo to the count. If it is zero, the parity will
be even, otherwise the parity will be considered odd.

To solve the recursive problem, I will consider as the trivial case a binary
string of one bit. I won't consider the empty string, since it does not
represent a valid binary string.

## Solution Overview
<!-- Solve the problem iteratively -->
After considering the strategy for both solutions, here it is how I applied the
*Big Recursive Idea*. Firstly, I solved the problem iteratively as I described
in the analysis:

```cpp
bool iterativeHasOddParity(string binaryStr) {
    int strLen = binaryStr.size();
    int onesCount = 0;
    for (int i = 0; i < strLen; i++) {
        if(binaryStr[i] == '1') 
            onesCount++;
    }
    return (onesCount % 2) == 1;
}
```

Secondly, I implemented the trivial case. As discussed, my trivial case is a
binary string that has one bit:

```cpp
if (binaryStr.size() == 1) {
    return binaryStr[0] == '1';
}
```

The next step is to call the iterative function which I already have tested:

```cpp
bool hasOddParity(string binaryStr) {
    if (binaryStr.size() == 1) {
        return binaryStr[0] == '1';
    }
    bool hasSubstrOddParity = iterativeHasOddParity(binaryStr.substr(1));
    bool isFirstBitOne = (binaryStr[0] == '1');
    if (isFirstBitOne) return !hasSubstrOddParity;
    else return hasSubstrOddParity;
}
```

The key of this problem is realizing that the parity of the first bit must be
opposite to the parity of the rest of the bits combined. Finally, to get the
recursive solution we must simply replace the call to the iterative function by
a call to the function itself.

```cpp
bool hasOddParity(string binaryStr) {
    if (binaryStr.size() == 1) {
        return binaryStr[0] == '1';
    }
    bool hasSubstrOddParity = hasOddParity(binaryStr.substr(1));    
    bool isFirstBitOne = (binaryStr[0] == '1');
    if (isFirstBitOne) return !hasSubstrOddParity;
    else return hasSubstrOddParity;
}
```
