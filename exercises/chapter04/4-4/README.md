# Exercise 4.4 [Size-Prefixed String] <!-- TODO Add Name-->

## Problem Statement

Change the implementation of our strings such that location[0] in the array
stores the size of the array (and therefore location[1] stores the first actual
character in the string), rather than using a null-character terminator.
Implement each of the three functions, append, concatenate, and charactertAt,
taking advantage of the stored size information whenever possible. Because
we’ll no longer be using the null-termination convention expected by the
standard output stream, you’ll need to write your own output function that
loops through its string parameter, displaying the characters.

## Problem definition

Here is the type used, which has been taken from the book:

```cpp
typedef char * arrayString;
```

Here are the list of functions that will be implemented.

```cpp
void output(arrayString s);
char characterAt(arrayString s, int position);
void append(arrayString& s, char c);
void concatenate(arrayString& s1, arrayString s2);
```

After a bit of thinking, we can notice the following differences with the null-
character appraoch:

* Length calculation will now be a lookup rather than searching for the null-
character.
* Functions now will require range translation (The payload is shifted)
* Functions that create an `arrayString` they now must store the length at
location `[0]`

## Solution Overview

If we compare the solution I implemented with the book examples, we will notice
that the changes are based on what was stated above. Below there is an excerpt
of the solution. I highlighted the key components.

```cpp
int length(arrayString s) {
    return s[0] - '0'; //[1]
}

void output(arrayString s) {
    int sLen = length(s);
    for (int i = 1; i <= sLen; i++) { //[2]
        cout << s[i];
    }
}

void append(arrayString& s, char c) {
    int oldLen = length(s);   
    // COPY s
    arrayString newS = new char[oldLen + 2];
    for (int i = 1; i <= oldLen; i++) { //[3]
        newS[i] = s[i];
    }    
    // STORE c and length
    newS[oldLen] = c;
    newS[0] = (oldLen + 1) + '0'; //[4]

    delete[] s;
    s = newS;
}
```

[1] Our function length is now a lookup. We must remember to translate the char
code as we learned in chapter 2.

[2] & [3] As stated before, the range of the string payload is now shifted one
position, so we must start at one.

[4] Also, when we require creating a new `arrayString`, we must store the
length as the first character as a char code as like we learned in chapter 2.

## Final Thoughts

After the solving the [text replacer][4-3] problem, this one felt quite easy! I
think personally that is a great choice from the author adding an easier
exercise after a difficult one. The next group of exercises will be about linked
lists.

<!--Links -->
[4-3]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter04/4-3)