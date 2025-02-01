# Exercise 2.2: [Output Patterns]

## Problem Statement

Using only single-character output statements that output a hash mark, a
space, or an end-of-line, write a program that produces the following shape:

 ```txt
    ##   
   ####  
  ###### 
 ########
 ########
  ###### 
   ####  
    ##  
```

## Strategy

This figure can be seen as an extension of the figure of
[exercise 1](../01/README.md). We can reduce then the problem by half by reusing
our previous solution. For the first half of the figure, I will apply the
*counting down by counting* up technique used in the previous exercise. What
is different now is that the number of hashes grow, where as the number of
blanks decreses.

## Expression analysis

### Number of hashes

|Row|Desired Value|row * 2|Difference|
|:-:|:-----------:|:----------:|:---------:|
|1|2|2|0|
|2|4|4|0|
|3|6|6|0|
|4|8|8|0|

The algebraic expression will be `row*2` keeps the difference constant at 0.

### Number of spaces

|Row|Desired Value|row * - 1|Difference|
|:-:|:-----------:|:----------:|:---------:|
|1|3|-1|4|
|2|2|-2|4|
|3|1|-3|4|
|4|0|-4|4|

The difference is fixed at 4, so the algebraic expression is `4-row`.
