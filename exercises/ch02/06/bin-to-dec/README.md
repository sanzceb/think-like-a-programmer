# Exercise 2.6: [Input Processing: Binary to Decimal]

## Problem Statement
If you’ve learned about binary numbers and how to convert from decimal
to binary and the reverse, try writing programs to do those conversions with
unlimited length numbers (but you can assume the numbers are small
enough to be stored in a standard C++ int).

## Introduction
This document will cover the **conversion from binary to decimal**. This is the most straightforward problem since we are moving from a smaller base (base - 2) to a larger one (base-10). This means it is possible to implement a solution that processes each digit only once and have the final solution after reading the last digit without requiring any additional task.

## Approach

Following the approach of previous input processing problems we can break it down into subparts:

### Input processing
**Keep reading digits until the user presses ENTER**. I have reused the solution implemented for the ISBN validator and simplify it, because it is not needed to deal with hyphens nor blanks and we don't need to track the position of the input.

### Adding new bits.
For each new binary digit we multiply the current decimal by two (equivalent to shifting left in binary) and then we add the new digit.

For example, when processing the binary number 1101:

Read 1: decimal = 1  
Read 1: decimal = (1 × 2) + 1 = 3  
Read 0: decimal = (3 × 2) + 0 = 6  
Read 1: decimal = (6 × 2) + 1 = 13
