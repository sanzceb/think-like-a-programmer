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
retrieved. Throughout this chapter we have studied an implemented the
symbol table, which allows to efficiently add and retrieve items. We use it to
add and retrieve students, and we can use it in the same way to manage fields.

We are requested to use the standard library, so we will apply what was learned
during the implementation of the symbol table of that was written for solving
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
