# Exercise 6.12 Statistics Revisited

## Problem Statement

Design your own: Consider basic statistical questions you can ask of a set of
numerical values, such as average, median, mode, and so forth. Attempt to write
recursive functions to compute those statistics for a binary tree of integers.
Some are easier to write than others. Why?

## Analysis

### BRI for the median

Given that a binary tree $T$ according to our book definition is complete, and
therefore balanced, the median corresponds to the node value of $T$. This is
because it leaves the same number of nodes on the left and the same number of
nodes on the right.

### BRI for the mode

Given that a binary tree $T$ according to our book definition is complete, and
therefore balanced, the mode can be any of the nodes of the tree, since there
are no duplicates in a binary tree. In practice, the mode does not exist.

### BRI for the average

The average is trickier. The average cannot be calculated through head
recursion because in order to give each node its proper weight, we need to know
the number of nodes of the whole tree. This is a situations in which the
function we are requested to implement is not a recursive function, but a
wrapper of another recursive function. In this case, `average` wraps a function
I called `stats` which calculates recursively the aggregated values
required to calculate the average.

This is the BRI plan I implemented for the function `stats`:

Given a complete binary tree $T$ and its value $V$:

1. If $T$ is minimal, return 1 as count and the node value as the sum.
Otherwise ...

2. Make a call to a recursive function to get the size and sum of $T_{left}$.

3. Make a recursive call to get the size and sum of $T_{right}$.

4. Inspect $V$, sum its value and increase the count and return both values.

## Notes

I have grouped the sum and count in a struct to get both values in a single
recursive traversal.
