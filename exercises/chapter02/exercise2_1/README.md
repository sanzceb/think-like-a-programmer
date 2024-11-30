# Exercise 2.1: [Input Processing]

## Problem Statement
Using only single-character output statements that output a hash mark, a
space, or an end-of-line, write a program that produces the following shape:
 ```
 ########   
  ######   
   ####  
    ##
```
## Approach
I have broken down the problem into different parts:
* Print one single line of hashes. 
* Print a next line with 6 hashes wrapped by 4 spaces.
* Print the line 4 times with a loop.
* Create an inner loop with an algebraic expression that reduces the number of hashes 
## Implementation
* Inspired on the input processing example of the book, I have designed the expression of the inner loop using a symbols table.
* The created expression ``` hashnum <= (10 - 2 * lineNum)``` decreases the width of the hash line two on each step. I have chosen 10 to start the line number at 1

## Code
```cpp
[Your code here]