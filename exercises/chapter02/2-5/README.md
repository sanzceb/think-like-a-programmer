# Exercise 2.3: [Input Processing]

## Problem Statement
If you like the Luhn formula problem, try writing a program for a different check-digit system, like the 13-digit ISBN system. The program could take an identification number an verify it or take a number without its check digit and generate the check digit.

## Introduction
The International Standard Book Number (ISBN) is a unique identifier for books. The 13-digit ISBN variant (ISBN-13) includes 12 digits plus a check digit that helps verify if the number is valid.

## Approach
The problem I have chosen is the **ISBN validation**.  Here is an example of the calculation of the check digit.
```
9 7 8 1 5 9 3 2 7 4 2 4
× × × × × × × × × × × ×
1 3 1 3 1 3 1 3 1 3 1 3
===================
9+21+8+3+5+27+3+6+7+12+2+12 = 115
115 ÷ 10 = 11 remainder 5
10 - 5 = 5, so check digit = 5
```
The code must have 13 digits. Starting from the leftmost digit, the odd digits will be multiplied by **1** and the even digits will be multiplied by **3**. These products will be summed and then compared with the 13th digit, which is the check digit. If they are equal, the number is valid. Otherwise the number is not valid.

I have divided the problem into four parts:

1. **Problem: What are the codes in your computer for a hyphen, a whitespace, or an ENTER?**. An ISBN input might contain hyphens and whitespaces, so I need to know the codes of my computer for those characters as the book does with the end of line

2. **Problem: Write a program that reads characters until the user presses ENTER. It will validate the input only if 13 characters are entered, ignoring hyphens and whitespaces**. This will help me deal with the condition to calculate the checksum and read the check digit.

3. **Problem: Taking a number and its position, multiply by one if the position is odd or multiply by three if the position is even**. I will follow a similar approach to the book's Luhn formula example.

4. **Problem: Divide an integer by 10 and subtract the remainder from 10. if the result is 10 print 0.** I will isolate the calculation of the check digit and I will encapsulate it in a function.

## Implementation Notes
After joining all solutions to finish the program, I realized when the user inputs an invalid format, the output of the program is confusing, so I added a check of the read positions.

## Test cases

| Input | Expected Output |
|-------|----------------|
| 9781593274245 | Valid |
| 978-1-59327-424-5 | Valid |
| 978 1 59327 424 5 | Valid |
| 9781593274242 | Invalid |
| 9781593274246 | Invalid |
| 978159327424 | Invalid |