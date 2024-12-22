# Exercise 2.3: [Output Patterns]

## Problem Statement
Using only single-character output statements that output a hash mark, a space, or an end-of-line, write a program that produces the following shape:
```
#            #
 ##        ##
  ###    ###
   ########   
   ########   
  ###    ###
 ##        ##
#            #
```


## Approach
This figure is significantly more complex than the other two, so I have annotated the number of hashes and spaces again to find patterns:
```
#            # (0 spaces, 1 hash,  12 spaces, 1 hash,   0 spaces)
 ##        ##  (1 space,  2 hashes, 8 spaces, 2 hashes, 1 space)
  ###    ###   (2 spaces, 3 hashes, 4 spaces, 3 hashes, 2 spaces)
   ########    (3 spaces, 4 hashes, 0 spaces, 4 hashes, 3 spaces)
   ########    (3 spaces, 4 hashes, 0 spaces, 4 hashes, 3 spaces)
  ###    ###   (2 spaces, 3 hashes, 4 spaces, 3 hashes, 2 space)
 ##        ##  (1 space,  2 hashes, 8 spaces, 2 hashes, 1 space)
#            # (0 spaces, 1 hash,  12 spaces, 1 hash,   0 spaces)
```

1. The numbers of characters at each step is always 14.
2. The figure has simmetry around the lines 4 and 5 so we can break down the figure into two: lines 1-4 and lines 5-8 as in exercise 2-2.
3. To solve the problem there are 3 algebraic expressions that must be created based on the number of the line at each step:
    * One for both the leading and trailing spaces
    * One for both hash groups
    * One for the middle spaces.
4. The sum of the three values must always be 14.
5. For the second half of the figure we need another 3 algebraic expressions that sum 14 at each step for the line range 5-8 

### Key Components
In this section I list the algebraic expressions where n is the number of lines

First Half (1 ≤ n ≤ 4)
1. Leading spaces: n - 1
2. First hashes: n
3. Middle spaces: 16 - 4n
4. Second hashes: n
5. Trailing spaces: n - 1
6. Sum Equation: (n-1) + n + (16-4n) + n + (n-1) = 14

Second Half (5 ≤ n ≤ 8):

1. Leading spaces: 8 - n
2. First hashes: 9 - n
3. Middle spaces: 4n - 20
4. Second hashes: 9 - n
5. Trailing spaces: 8 - n
6. Sum equation: (8-n) + (9-n) + (4n-20) + (9-n) + (8-n) = 14


## Implementation Notes
To implement both equations I have used two fixed main loops that have five nested loops each.