# Exercise 5.4 Variable-Length String: Operator[].

## Problem Statement
For the variable-length string class of the previous exercise, replace the
characterAt method with an overloaded [] operator. For example, if myString
is an object of our class, then myString[1] should return the same result as
myString.characterAt(1).

## Solution Overview
This is the function signature I added to the public section:

```cpp
char operator[](int pos);
```

I have used the same signature that `characterAt` has:

```cpp
char characterAt(int pos)
```

And the implementation is a direct call to `characterAt`:

```cpp
char charCollection::operator[](int pos) {
    return characterAt(pos);
}
```
