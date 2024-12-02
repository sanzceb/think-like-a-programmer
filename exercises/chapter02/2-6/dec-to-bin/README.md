# Exercise 2.6: [Input Processing: Decimal to Binary]

## Problem Statement
If you’ve learned about binary numbers and how to convert from decimal
to binary and the reverse, try writing programs to do those conversions with
unlimited length numbers (but you can assume the numbers are small
enough to be stored in a standard C++ int).

## Approach

Contrary to the  decimal to binary problem, we are moving from a larger base (base-10) to a smaller one (base-2). This means an expansion in the number of digits and requires special considerations that I point out in this document. 

The purpose of the exercise is to use of the techniques prescribed in the book. That means we cannot allocate memory and therefore it is not easy to develop a direct solution as we read the input. That is the reason that has made me think of adding a post-processing task to compute each bit after reading the whole number.

I have divided the problem into the following sub problems:

### Input Processing
The input processing mechanism has been adapted from our previous binary to decimal conversion solution. We are now in a decimal system so each time we read a new digit, the current value is increased 10 times so we must multiply it by 10.

### Bit Counting

One of the key insights is realising that in order to compute a decimal digit that goes from 0 to 9 we require at most 4 bits. That's the wisdom behind counting four bits per new digit.

### Binary Conversion and Output: 
The conversion process uses arithmetic operations to extract each binary digit. Dividing by two is equivalent to shift one bit to the left. Once the desired bit is at the right most position, we get rid of the leading bits using with the modulo operation. A more efficient approach is to use bitwise operations, but since they are not shown in the book, I have decided to restrain their use. This logic has been implemented in the function get_bit


## Implementation Notes

During the implementation it emerged the idea of get rid of the leading zeros. It is not a requirement of the exercise but I put it as an extra since it provides a clearer output.