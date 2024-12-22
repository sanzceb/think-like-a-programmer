# Exercise 2.3: [Output Patterns]

## Problem Statement
Design your own: Think up your own symmetrical pattern of hash marks,
and see whether you can write a program to produce it that follows the
shapes rule.

I have generated the following shape with AI
```
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


## Approach

This figure can be broken down in different sub figures that can be solved using the shape rules:

1. The first pyramid
```
       ##        (7 spaces, 2 hashes,  7 spaces)
     ######      (5 spaces, 6 hashes,  5 spaces)
   ##########    (3 spaces, 10 hashes, 3 spaces)
 ##############  (1 space , 14 hashes, 1 space)
################ (16 hashes)
```
2.  The reverse pyramid:
```
################ (0 spaces, 16 hashes)
 ##############  (1 space , 14 hashes, 1 space)
   ##########    (3 spaces, 10 hashes, 3 spaces)
     ######      (4 spaces, 6 hashes,  4 spaces)
       ##        (7 spaces, 2 hashes, 7 spaces)
```
3. The nested diamonds have 4 sub parts:
```
From line 6 to 7
######    ###### (6 hashes, 4 spaces 6 hashes)
####        #### (4 hashes, 8 spaces 4 hashes)

From 8 to 10

###   ####   ### (3 hashes, 3 spaces, 4 hashes, 3 spaces, 3 hashes)
##   ######   ## (2 hashes, 3 spaces, 6 hashes, 3 spaces, 2 hashes)
#   ########   # (1 hash,   3 spaces, 8 hashes, 3 spaces, 1 hash)

From line 11 to 12

##   ######   ## (2 hashes, 3 spaces, 6 hashes, 3 spaces, 2 hashes)
###   ####   ### (3 hashes, 3 spaces, 4 hashes, 3 spaces, 3 hashes)

From 13 to 14

####        #### (4 hashes, 8 spaces, 4 hashes)
######    ###### (6 hashes, 4 spaces, 6 hashes)
```

### Key Components

The algebraic expressions for each figure where n is the line number at each step:

The pyramid expressions (1 ≤ n ≤ 4):
* Leading spaces: [9 - 2n]
* Medium hashes: [4n - 2]
* Trailing spaces: [9 - 2n]

The nested diamonds

First Quarter (6 ≤ n ≤ 7)
* Leading hashes: [18 - 2n]
* Spaces: [4n - 20]
* Trailing hashes: [18 - 2n]

Second Quarter (8 ≤ n ≤ 10)
* Leading hashes: [11 - n]
* Leading and trailing spaces: 3
* Medium hashes: [2n - 12]
* Trailing hashes: [11 - n]

Third Quarter (11 ≤ n ≤ 12)
* Leading hashes: [n - 9]
* Leading and trailing spaces: 3
* Medium hashes: [28 - 2n]
* Trailing hashes: [n - 9]

Fourth Quarter (13 ≤ n ≤ 14)
* Leading hashes: [2n - 22]
* Medium spaces: [60 - 4n]
* Trailing hashes: [2n - 22]

The reverse pyramid expressions (16 <= n <= 20)
* Leading spaces: [2n -31]
* Hashes: [78 - 4n]
* Trailing spaces: [2n - 31]



## Implementation Notes
Each section has its own fixed loop as in the previous exercises. I have encapsulated the printing loops to compact the program and improve readability.