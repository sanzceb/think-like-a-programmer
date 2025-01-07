# 7.5 Quick Search using Standard Library

## Problem Statement

For the problem in 7-3, implement a solution using a class from the C++ library.

## Analysis

The problem 7-3 states as follows: "Consider a collection of `studentRecord`
objects. We want to be able to quickly find a particular record based on
student number"

We need to find a container that is efficient in search. Among the three
available type of containers: **sequence containers**, **associative
containers**, and **unordered associative containers**, I choose the unordered
associative containers because the time complexity they offer on average is
constant ($O(1)$). We want to the studentRecord to be found by its student
number so the container suitable for this task is [`unordered_map`][um],
because it allows to associate a key with a value.

## Implementation notes

- I have implemented a validation of the `addRecord` arguments to avoid that a
dummy student is inserted.

- Notice that `find` method returns an iterator to the position of the pair and
there is no way to have straight access to the value. This was the preferrable
option to lookup the value, since the operator [`at`][subscript] `[]` inserts
the key in case the student is not found.

[subscript]:(https://en.cppreference.com/w/cpp/container/unordered_map/operator_at)
[um]:(https://en.cppreference.com/w/cpp/container/unordered_map)
