# Exercise 4.2[Function substring]

## Problem Statement

For our dynamically allocated strings, create a function `substring` that takes
that takes three parameters: an `arrayString`, a starting position integer, and
an integer length of characters. The function returns a pointer to a new
dynamically allocated string array. This string array contains the characters in
the original string, starting at the specified position for the special length.
The original string is unaffected by the operation. So if the original string
was `abcdefg`, the position was 3, and the length was 4, then the new string
would contain `cdef`.

## Problem definition

```cpp
    typedef char * arrayString;

    arrayString substring(arrayString arrayStr, int startingPos, int subStrLen);
```

## Solution

I implemented the function without much trouble. The tricky point is the range
translation. Other than that, it is not much different from `append` function
explained in the book.

Here is my solution:

```cpp
typedef char * arrayString;

arrayString substring(arrayString str, int initPos, int subStrLen) {
 arrayString subStr = new char[subStrLen + 1];

 //Initial position starts from 1
 for (int i = 0; i < subStrLen; i++) {
        subStr[i] = str[initPos + i - 1];
 }

 subStr[subStrLen] = 0;

 return subStr;
}
```

This second exercise has still been a warmup. Let's see how hard I find the
exercises that are ahead.
