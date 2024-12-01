# Exercise 2.2: [Output Patterns]

## Problem Statement
Using only single-character output statements that output a hash mark, a
space, or an end-of-line, write a program that produces the following shape:
 ```
    ##   
   ####  
  ###### 
 ########
 ########
  ###### 
   ####  
    ##  
```
## Approach
Having solved exercise 2-1, the second half of the problem is already solved. For the first part, I have followed the same approach but this time is the space width the variable that is reduced from 6 to 0 following this pattern:
 ```
Line 1:    ##    (2 hashes, 6 spaces)
Line 2:   ####   (4 hashes, 4 spaces)
Line 3:  ######  (6 hashes, 2 spaces)
Line 4: ######## (8 hashes, 0 spaces)
 ```

## Implementation Notes
Each line has exactly 8 characters, and it is something I have overlooked in the previous solution. I made the algebraic expression for the part of the problem that corresponds to the previous exercise easier to understand