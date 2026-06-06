# Exercise 2.5: [Input Processing]

## Problem Statement
If you like the Luhn formula problem, try writing a program for a different check-digit system, like the 13-digit ISBN system. The program could take an identification number an verify it or take a number without its check digit and generate the check digit.

## Introduction
The International Standard Book Number (ISBN) is a unique identifier for books. The 13-digit ISBN variant (ISBN-13) includes 12 digits plus a check digit that helps verify if the number is valid.

Here is an example of the calculation of the check digit.

```
9 7 8 1 5 9 3 2 7 4 2 4
× × × × × × × × × × × ×
1 3 1 3 1 3 1 3 1 3 1 3
===================
9+21+8+3+5+27+3+6+7+12+2+12 = 115
115 ÷ 10 = 11 remainder 5
10 - 5 = 5, so check digit = 5
```

An ISBN code must have 13 digits. Starting from the leftmost digit, the odd digits will be multiplied by **1** and the even digits will be multiplied by **3**. The code will be valid if only if the sum of all digits is divisible by 10.

Both problems of the exercise were solved: the validation in C++ and the check digit generation in Java.

## ISBN Validation
The validation problem will read a complete ISBN code and will verify that the code is 13-digits long and divisible by 10. I divided the problem into three parts:

1. **Problem: What are the codes in your computer for a hyphen, a whitespace, or an ENTER?**. An ISBN input might contain hyphens and whitespaces, so I need to know the codes of my computer for those characters as the book does with the end of line

2. **Problem: Write a program that reads characters until the user presses ENTER. It will validate the input only if 13 characters are entered, ignoring hyphens and whitespaces**. This will help me deal with the condition to calculate the checksum and read the check digit.

3. **Problem: Taking a number and its position, multiply by one if the position is odd or multiply by three if the position is even**. I will follow a similar approach to the book's Luhn formula example.

## ISBN calculation
The ISBN calculation program expects the first 12 digits and calculates the 13th digit based on the formula analyzed in the introduction with a new function: `checkDigit`.

## Implementation Notes

`System.in.read()` returns an integer. The java compiler does not accept conversions from type `int` to `char`. Therefore the digit can only be stored as an integer.

## Test cases

| Input | Expected Output |
|-------|----------------|
| 9781593274245 | Valid |
| 978-1-59327-424-5 | Valid |
| 978 1 59327 424 5 | Valid |
| 9781593274242 | Invalid |
| 9781593274246 | Invalid |
| 978159327424 | Invalid |

