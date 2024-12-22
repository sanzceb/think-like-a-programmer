# Exercise 2.8: [Input Processing: From Base to Base]

## Problem Statement
Want an extra challenge? Generalize the code for the previous exercise to
make a program that converts from any number base-16 or less to any other
number base. So, for example, the program could convert from base-9 to
base-4.

## Approach
With the insights learned and the code we implemented in previous exercises, the step
of implementing the general case (from any base to any base) emerges quite naturally.

The work done for extending the solution built for exercise 2-7 can be summarized in these subproblems:

- Take the previous solution and generalize the get_bit and get_hex into one function get_base_digit
- Count the increase of digits we need to transform from decimal into a smaller base and expand the representation.
    - For base two we need at most 4 times the number of decimal digits
    - For base three we need at most 3 times the number of digits.
    - From base four to base nine we need at most 2 times the number of digits.
- Count the decrease of digits we need to transform from decimal into a bigger base and reduce the representation.
    - For any base above ten, the number is at most the number of decimal digits we already have

## Implementation notes
The program is capable of reading both letters in lowercase and uppercase, but the output representation is always in lowercase. I have not tested the highest base this implementation can represent.

## Usage example
```
Enter the base of the input: 16
Enter the number in base 16: ff  
Enter the base of the output: 4  
The number in base 4 is: 3333  
```
===============================
```
Enter the base of the input: 16
Enter the number in base 16: ff
Enter the base of the output: 2
The number in base 2 is: 11111111
```