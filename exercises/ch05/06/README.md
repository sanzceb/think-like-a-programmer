# Exercise 5.5 Variable-Length String: Refactor

## Problem Statement
Review your variable-length string class for possible refactoring. For example,
is there any common functionality that can be separated into a private
support method?

## Refactor Overview
As a result of the refactoring process, I have created four private support
methods whose functionality is used repeatedly:
```cpp
    bool isEmpty() const; //[1]
    charNode * newNode(char chr); //[2]
    charNode * lastNode(); //[3]
    charNode * posNode(int pos); //[4]
```
[1] A validation support method that is used to check if the list is empty.
The `const` statement guarantees the method does not change the state of the
object. It is required for the implementation of [`concatenate`][concat].
[2] A helper method that encapsulates the creation and initialization of one
node. [3], [4] lastNode and posNode are list traversal methods. lastNode
searches for the last node, and posNode searches for a node at the position
marked by the parameter.

Another significant change was the implementation of concatenate. Now it is
independent of the method `append`. That has improved the method's efficiency
because now is possible to do a preliminary traversal of the internal list to
make sure that there is no list traversal for each node that is copied. That
reduces the method complexity from $O(n.m)$ to $O(n + m)$.

Lastly, some minor changes have also been made such as the elimination of
comments that with the refactoring became unnecessary, and the renaming of some
variables.

<!--Links-->
[concat]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch05/06/main.cpp#L73)