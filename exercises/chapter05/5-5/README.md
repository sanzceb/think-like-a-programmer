# Exercise 5.5 Variable-Length String: remove

## Problem Statement

For the variable-length string class of the previous exercises, add a remove
method that takes a starting position and a number of characters and removes
that many characters from the middle of the string. So myString.remove(5,3)
would remove three characters starting at the fifth position. Make sure your
method behaves when the value of either of the parameters is invalid.

# Method definition

Here is the signature of the method that will be implemented

```cpp
void charCollection::remove(int pos, int len)
```

The implementation of this method will be based on the function `removeChars`
implemented for solving the [exercise 8 of chapter 4][4-8].

# Solution overview

Here is the implementation of the method:
```cpp
void charCollection::remove(int pos, int len) {
	if (_listHead == NULL) return;
	// SEARCH for node prior to pos
    charNode * prevPtr = _listHead;
    while (prevPtr != NULL && pos-- > 1) {
        prevPtr = prevPtr->next;
    }
	//if(position not found)
	if (prevPtr == NULL) return;
	// remove each node between pos and len
	while (prevPtr->next != NULL && len-- > 0) {
        charNode * newNext = prevPtr->next->next;
		delete prevPtr->next;
		prevPtr->next = newNext;
    }
}
```

The logic is the same as the logic implemented in the function of the
[previous chapter][4-8]. The only difference is that now we work with
the linked list data member `_listHead` instead of the function parameter `s1`.
We have now encapsulated the implementation and reduced the number of required
parameters. This change has also consequently simplified the test case. We do
not need anymore the helper method to cleanup the memory. Now that cleanup
action is being performed by the destructor after the main function ends.

<!--Links-->
[4-8]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/chapter04/4-8/README.md)