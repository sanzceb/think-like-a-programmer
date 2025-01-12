# Exercise 7.8 Design your own: Text Replacer using standard library

## Problem Statement

Design your own: Take a problem you have already solved, and solve it again
using a different component. Remember to analyze the results in comparison to
your original solution.

## Introduction

For this exercise I have chosen the [text replacer][txtrep]. The implementation
I did was quite complex, and I think it is one of those in which using the
standard library can benefit more.

I am going to replace the custom string based on a char pointer by the string
class.

## Analysis

This is a problem where there are two main operations: search the matches and
store the characters in the same position.

Looking at the **Search** section of the string class, I see that it has a
method `find`

Looking at the **Modifiers** section, I found a method called `replace` that
replaces a range of characters by the given characters.

```cpp
basic_string& replace( size_type pos, size_type count,
                       const basic_string& str );
```

I will implement the function `replaceText` based on these two functions.

## Solution overview

The final solution using string is much simpler to implement because:

- Memory management is delegated
- The calculation of the length of each string is already supported by `size`.
- The matches are found by `find` and the update is managed by `replace`.

Also notice the fact that for big texts, `string` is more robust because
it supports `size_t` positions instead of integers.
<!--Links -->
[txtrep]:(https://github.com/sanzceb/think-like-a-programmer/tree/main/exercises/ch04/03)
