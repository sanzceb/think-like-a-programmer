# Exercise 6.4 Recursive Array Sorted

## Problem Statement

Design your own: Find a problem processing a one-dimension array that you
have already solved or that is trivial for you at your current skill level, and
solve the problem (or solve it again) using recursion.

## Analysis

I have chosen the [exercise 3 of chapter 3][3-3], which is about determining if
an array is sorted. To implement the recursive version, we must set a trivial
case and a way of reducing the problem. For this function the way of reducing
the function is the usual for arrays; reduce the size by one. I have set the
trivial case an array of one item, which by default is sorted. The recursive
case will compare the last item with the item before. If it is bigger, then
the result will depend on the result of the recursive call. Otherwise the array
is not sorted.

<!--Links -->
[3-3]:(http://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter03/3-3)
