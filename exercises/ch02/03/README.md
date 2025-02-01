# Exercise 2.3: [Output Patterns]

## Problem Statement

Using only single-character output statements that output a hash mark, a space,
or an end-of-line, write a program that produces the following shape:

```txt
#            #
 ##        ##
  ###    ###
   ########   
   ########   
  ###    ###
 ##        ##
#            #
```

## Strategy

This figure is significantly more complex than the other two, so I will
reduce by 4 and go step by step:

```txt
#     
 ##   
  ### 
   ####
```

With the experience of solving the previous exercises, I can intuitively see
expressions for this figure, but I will confirm my intuition with the analysis
table

### Expression analysis

|Row|Desired #|Desired left spaces
|:-:|:-------:|:-----------------:
|1|1|0
|2|2|1
|3|3|2
|4|4|3

The expression for the hashes is the row count and the number of spaces goes
always one behind: `row - 1`.

Now I feel confident to tackle the first half

```txt
#            #
 ##        ##
  ###    ###
   ########  
```

|Row|Desired right spaces|row * -4|Difference
|:-:|:------------------:|:------:|:---------:
|1|12|-4|16
|2|8|-8|16
|3|4|-12|16
|4|0|-16|16

The difference is fixed at 16, so the algebraic expression is `16 - 4 * row`.

Following the same procedure, I figured out the expressions for the second
half. I did not include the tables for brevity:

- Number of left spaces: `4 - row`
- Number of hashes: `5 - row (twice)`
- Number of middle spaces: `4 * row - 4`
