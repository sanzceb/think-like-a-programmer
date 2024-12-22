# Exercise 2.7: [Input Processing: From 3 bases into 3 bases]

## Problem Statement
Have you learned about hexadecimal? Try writing a program that lets the
user specify an input in binary, decimal, or hexadecimal, and output in any
of the three.

## Approach
The problem consists of expanding the solution we implemented specifically to convert from decimal to binary to also include the hexadecimal system. The key of my solution was the realization of the fact that we can reduce a problem that can perform 9 possible conversion (from 3 bases into 3 bases) into two subproblems:
- Read any input and convert it into decimal.
- Convert any decimal into any output

### Input Processing
The input processing mechanism has been adapted from our prior solutions. From that experience we already know how to read a binary number and store it in decimal and how to read a decimal number and store it in decimal. We need the base of the number and the digit conversion from one base into decimal. So I have formulated the following subproblems:

- Given a hexadecimal digit, convert it into decimal. This solution is implemented in the function ```int as_decimal(int)```
- Write a program that takes a base, a number in that base and converts it into decimal. We reused our input processing solution of the problem of reading a decimal number to specifically read a base.

Then I put these new code together and reused the code from the binary decimal case and at this stage I had a solution that reads any of the three bases and converts it into one of these two: binary or decimal.

## Conversion and output
Our remaining problems are. How do I represent a decimal number in hexadecimal? I realized that the problem can be solved by formulating these questions:

- **How do I represent a decimal number as an hexadecimal digit**? I solved that problem and encapsulated the solution in the function `get_hex` .

- **How many digits do I need to represent a decimal number in hexadecimal?** Actually at most, the same number of digits we already require for the decimal representation, because this time we are expanding the base and not compressing it as we did for the binary case. *At most* means that we might require less digits to represent the same number. Applying into our program, that means the only thing I need to do is to get rid of the trailing zeros as we did for the binary case

```cpp 
while (get_hex(decimal, digitsNum) == '0') --digitsNum;
```

I put all together and the solution was developed quite smoothely!
## Usage examples

Input in binary (base 2) to hexadecimal (base 16):
```
Enter the base of the input: 2
Enter the number in base 2: 1010
Enter the base of the output: 16
The number in base 16 is: a
```