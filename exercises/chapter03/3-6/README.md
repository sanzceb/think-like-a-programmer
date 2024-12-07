# Exercise 3.6

## Problem Statement
To make the ciphertext problem even more challenging, have your program   
randomly generate the cipher array instead of a hard-coded one `const` array.  
Effectively, this means placing a random character in each element of the array,  
but remember that you can't substitute a letter for itself. So the first  
element can't be A, and you can't use the same letter for two substitutions.  
That is, if the first element is S, no other element can be S.

## Approach

I will break down the problem into three different parts

1. Generate an array of random characters.
```cpp
```
2. Check that a letter can't substitute itself. [x]
```cpp
```
3. Search a letter that is duplicated.
```cpp
```
