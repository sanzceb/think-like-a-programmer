# Exercise 7.7 Student Extra Fields

Develop a solution to the problem described in 7-6 that does not make use
of the pattern you discovered but instead solves the problem using C++
library classes. Rather than focusing on the three particular data fields
described in the previous question, try to make a general solution: a version
of the studentRecord class that allows arbitrary extra fields of data to be
added to particular objects. So, for example, if sr1 is a studentRecord, you
might want client code to make the call sr1.addExtraField("Title", "Problems
of Unconditional Branching"), and then later sr1.retrieveField("Title") would
return “Problems of Unconditional Branching.”

## Analysis

We need a structure that allows arbitrary extra fields to be added but also
retrieved. Throughout this chapter I learned how to implement the symbol table,
which allows to efficiently add and retrieve items. We used it to add and
retrieve students, and we can apply it in the same way to fields.

We are requested to use the standard library, so we will apply what was learned
during the implementation of the symbol table that was written for solving
exercise 5. This means we will look at the associative containers components of
the standard library.

This is a problem where fast searching is more relevant than fast insertions,
because data fields are in nature more accessed than modified. Considering
that, I will choose again the `unordered_map` as the chosen associative
container.

```cpp
#include <unordered_map>
using std::unordered_map;
using std::pair;
```

The next topic is about what types are chosen to be values, I have considered
two options: store strings, and store generic pointers:

```cpp
std::unordered_map<string, string>
std::unordered_map<string, void*>
```

The option of storing pointers gives more flexibility and it is more efficient
in terms of memory management, because we store references to objects instead,
but each time we want to retrieve a value, a dynamic casting is required, and I
think that introduces a complexity that it is not worth it so I decided to
implement the string value solution.

## Solution overview

I have implemented a solution that is similar to the implemented in exercise 5.
The key difference is that I use the operator `[]` to insert new values
instead, which is more concise. However, I don't use it to search because it
inserts the key in case it is not found and I don't desire that behaviour.

I have ommitted the other data members of student record to be concise.
