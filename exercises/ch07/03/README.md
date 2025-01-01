# Exercise 7.3: Interpolation Search Algorithm

## Problem Statement

Consider a collection of studentRecord objects. We want to be able to quickly
find a particular record based on student number. Store the student records
in an array, sort the array by student number, and investigate and implement
the interpolation search algorithm.

## Analysis of Interpolation Search

*Interpolation Search* is an enhancement of the binary search algorithm. It aims
to make more intelligent guesses about the position of a target value. While
binary search always splits the search space in half, interpolation search uses
the values being searched to make a guess about where the target might be
located.

The algorithm is based on the mathematical concept of *linear interpolation*,
which estimates a value between two points using a straight line. It uses the
following formula:

$$x = x_0 + \left\lfloor \frac{(t - A[x_0])(x_1 - x_0)}{A[x_1] - A[x_0]}
\right\rfloor$$
where:

- $x_{0}, x_{1}$ represent the lower and upper bound limits of the search space
in the array.
- $t$ is the target student
- The $floor$ function ensures we get a valid array index

This formula estimates the position by assuming a linear relationship between
indices and values, making it particularly efficient for uniformly distributed
data like sequential student numbers. It will perform really well in uniform
and big distributions.

## Solution Plan

Before studying the algorithm, I initially planned these steps ahead to get me
started:

1. Reuse a [written program][3-1] that works with `qsort`.
2. Implement a comparator that works with student numbers
3. Study the interpolation search algorithm.
4. Plan the implementation.

After studying the algorithm, I realized it is an algorithm close to *binary
search*, an algorithm I am very familiar with. They both work by reducing the
search space on each step when they make a guess. The difference is that
Binary Search divides the search space by two arbitrarely whereas Interpolation
Search makes an informed guess because it makes a relative division based on
the search values.

After this realization, I defined my implementation plan:

1. Implement search test cases
2. Implement Binary Search
3. Update Binary Search implementation to be Interpolation Search.

## Solution Analysis

The transition from one algorithm to the other was not as simple as I thought
it would because the binary search formula is much simpler, but it definitely
helped starting from there. Here is my solution for the search student based on
interpolation search:

```cpp
int studentWithNumber(studentRecord sc[], const int ARRAY_SIZE, int stuNum) {
    int begin = 0, end = ARRAY_SIZE - 1;
    if (sc[begin].studentNum > stuNum //[1]
        || stuNum > sc[end].studentNum) {
            return -1;
    }
    while (begin <= end) {
        int valueDist = stuNum - sc[begin].studentNum; //[2]
        int valueRange = sc[end].studentNum - sc[begin].studentNum; //[3]
        int posRange = end - begin;
        int searchPos = begin + (valueDist * posRange) / valueRange; //[4]
        if (sc[searchPos].studentNum == stuNum) { //[5]
            return searchPos;
        } else if (sc[searchPos].studentNum < stuNum) {
            begin = searchPos + 1;
        } else {
            end = searchPos - 1;
        }
    }
    return -1;
}
```

I based my implementation on the value search technique explained in the book
(p. 58), which I will denominate *Simple Search*, and my familiarity with Binary
Search. Let's look at the solution step by step:

[1] We look that the student number is not out of bounds. Since now the
position is relative to the value, it is important to check that the value
range of the array. This will ensure that `searchPos` is always within the
array bounds. This is not necesary in Simple Search or in Binary Search because
in those algorithms the search range is reduced arbitrarily.

[2] Here we calculate the value distance between the first student of our
search range and our target student. This part corresponds to the formula
section $(t - A[x_0])$.

[3] Here we calculate the value distance between the first and last student of
our search range. This part corresponds to the formula section
(${A[x_1] - A[x_0]}$).

[4]. With `posRange` $(x_1 - x_0)$ and `begin` $(x_0)$ we translate the linear
interpolation into a valid index within the array.

[5]. From this step the algorithm is like Binary Search.

## Testing

This is the planned I followed to implement the test cases

1. Generate a random number between 1 and 100
2. Define a students collection as forward linked list.
3. Store a high number students with distributed random IDs
4. Test several searchings.

After doing some testing with collections of thousands of elements, I realized
a linked list was not an efficient structure. The reason is that to avoid
duplicates, I had to perform a lot of searches, so the creation was taking a lot
of time. That is why I decided to implement the collection of students with a
set:

```cpp
struct studentRecord {
    int grade;
    int studentNum;
};

struct studentCompar {
    bool operator()(const studentRecord& a, const studentRecord& b) const {
        return a.studentNum < b.studentNum;
    }
};

typedef std::set<studentRecord, studentCompar> studentCollection;
typedef studentCollection::iterator studentIterator;
```

The struct `studentCompar` is required because the set keeps the records sorted
and for that it needs a comparator that can compare the keys.

I tried to push the number of students over 30000, but I started having
segmentation faults in some of the runs. It is happening probably due to
memory fragmentation issues (an array requires a contigous block of memory
available). Despite those technical issues, the interpolation search has
demonstrated to be a very efficient search algorithm.

The performance test also runs the basic linear search algorithm taught in
the book to compare performance.

<!--Links-->
[3-1]:(https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch03/01)
