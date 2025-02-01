# Exercise 2.1: [Output Patterns]

## Problem Statement

Using only single-character output statements that output a hash mark, a
space, or an end-of-line, write a program that produces the following shape:

 ```txt
 ########   
  ######   
   ####  
    ##
```

## Strategy

In order to use the reduction techniques of the book I solve the folling
subproblems:

* Print a line of 8 hashes
* Print a rectangle of 8x4 hashes.
* Apply 'Counting down by Counting up' problem technique to find the algebraic
expression of the number of hashes.
* Apply 'Counting down by Counting up' problem technique to find the algebraic
expression of the number of spaces.

## Expression analysis

### Number of hashes

After some experimentation, I figured out that the expression that keeps the
difference constant at 10 is row * -2:

|Row|Desired Value|row * -2|Difference|
|:-:|:-----------:|:------:|:--------:|
|1|8|-2|10|
|2|6|-4|10|
|3|4|-6|10|
|4|2|-8|10|

The algebraic expression is `10 - 2 * row`.

### Number of leading spaces

The number of leading spaces must be one unit less than the row count.

|Row|Desired Value|Difference|
|:-:|:-----------:|:--------:|
|1|0|1|
|2|1|1|
|3|2|1|
|4|3|1|

So the expression is `row -1`.
