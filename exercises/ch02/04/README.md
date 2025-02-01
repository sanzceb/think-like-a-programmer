# Exercise 2.3: [Output Patterns]

## Problem Statement

Design your own: Think up your own symmetrical pattern of hash marks,
and see whether you can write a program to produce it that follows the
shapes rule.

I have generated the following shape with AI

```txt
       ##        
     ######      
   ##########    
 ##############  
################ 
######    ######
####        ####
###   ####   ###
##   ######   ##
#   ########   #
##   ######   ##
###   ####   ###
####        ####
######    ######
################ 
 ##############  
   ##########    
     ######      
       ##
```

## Strategy

Application the reduction technique, we can break down this huge shape into
smaller, manageable shapes.

### The First Pyramid

```txt
       ##
     ######
   ##########
 ##############
```

Computation table:

|Row|Spaces|Row * -2|Hashes|Row * 4|Difference
|:-:|:----:|:------:|:----:|:-----:|:--------:
|1|7|-2|2|4|2
|2|5|-4|6|8|2
|3|3|-6|10|12|2
|4|1|-8|14|16|2

There is a fixed difference with row * -2 of 9 so an algebraic expression could
be: `9 - 2 * row`. There is a fixed difference with `row * 4` and the number of
hashes of 2. An expression could be `4 * row - 2`.

### The Reverse Pyramid

```txt
 ##############
   ##########
     ###### 
       ##
```

|Row|Spaces|Row * 2|Hashes|Row * -4|Difference
|:-:|:----:|:------:|:----:|:-----:|:--------:
|1|1|2|14|-4|18
|2|3|4|10|-8|18
|3|5|6|6|-12|18
|4|7|8|2|-16|18

There is a fixed difference of -1 in the sequence of spaces. A proposed
expression can be: `2 * row - 1`. For the number of hashes, we can use the
expression `18 - 4 * row`.

### Nested diamonds

```txt
################
######    ###### 
####        ####
###   ####   ###
##   ######   ##
#   ########   #
##   ######   ##
###   ####   ###
####        ####
######    ######
################
```

Taking this structure as a whole is quite complex. A way of reduce it can be:

Compute the first and last three rows this way:

```txt
################
######    ######
####        ####
####        ####
######    ######
################
```

The algebraic expressions for the figure are:

* For the hashes of the first half: `10 - 2 * row`
* For the hashes of the second half: `2 * row + 2`
* For the spaces of the first half: `4 * row - 4`
* For the spaces of the second half: `12 - 4 * row`

I put the figures all together to get the following intermediate figure:

```txt
     ######
   ##########
 ##############
################
######    ######
####        ####
####        ####
######    ######
################
 ##############
   ##########
     ######
       ##
```

Finally we can tackle the rows in the middle:

```txt
###   ####   ###
##   ######   ##
#   ########   #
##   ######   ##
###   ####   ###
```

* For the hashes of the edges first half: `4 - row`
* For the central hashes of the first half: `2 * row + 2`
* For the central hashes of the secon half: `10 - 2 * row`
* For the hashes of the edges second half: `row`
* Spaces are constant at 3
