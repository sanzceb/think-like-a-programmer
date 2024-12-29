# Exercise 7.1 Internal Strategy Pattern - First Student

## Problem Statement

A complaint offered against the policy/strategy pattern is that it requires
exposing some internals of the class, such as types. Modify the “first student”
program from earlier in this chapter so that the policy functions are all
stored within the class and are chosen by passing a code value (of a new,
enumerated type, for example), instead of passing the policy function itself.

## Analysis

### Analogy with the lookup problem

The key behind the solution I have implemented is looking at this problem as a
lookup problem. We have a code that is associated with a function, so we need a
search function of another function. At this point, this idea came really
naturally to my head just right after reading the problem.

In order to solve a lookup problem, we need to define the lookup codes and
values. What we learned during the study of arrays and dynamic structures
is that arrays are really powerful when we have to search among a
constant set of values. This is one of those cases, because we only have three
possible policies to choose the first student with: `lowerStudentNumber`,
`higherGrade` and `namesComesFirst`.

Once discussed the domain and data structures, let's now look at the high-level
solution.

### Solution Strategy

Here is the high level definition of the solution I implemented:

1. I have hidden the function pointer definition and offerered an enum-based
type which favours information hiding and it is easier to use for the client.
2. All the policy functions were moved into the student collection class.
3. An array-based lookup was implemented to map the policy codes to the policy
functions.
4. The interface remained the same, but implementation details were hidden with
the encapsulation of the strategy.

Now that we have explained the solution, we are ready to look at the
implementation details.

## Solution Overview

```cpp
    enum firstStudentPolicy { //[1]
        HIGHER_GRADE, 
        LOWER_STUDENT_NUMBER, 
        NAMES_COMES_FIRST
    };

    typedef bool (* firstStudentPolicyFunc)(studentRecord r1 //[2]
    , studentRecord r2)

    void studentCollection::setFirstStudentPolicy( //[3]
    studentCollection::firstStudentPolicy policy) {
    const firstStudentPolicyFunc STUDENT_POLICIES[] = {
        higherGrade, lowerStudentNumber, namesComesFirst
    };
    _currentPolicy = STUDENT_POLICIES[policy];
}
```

[1] As the author suggested I have defined an enumerated type. This is the
interface the client will use to interact with the student collection and select
the policy to choose the first student. I have kept the name that the author
used to define the former function pointer because it conveys the same
information: the chosen policy.

[2] The function pointer type defined to implement the student comparators.

[3] This is another key of the solution. As stated in point [1], both the code
and the value convey the same information, but for our internal structure only
the value is useful. So to keep a similar interface, enforce
information hiding of the internal structures and avoid data redundancy, I still
store the function pointer but instead of getting the pointer straight from the
argument, we get the pointer by a lookup of the argument. This makes the
internal changes very transparent for the client.

### Search functions made static

The final modification was the internalization of the search functions. This is
also another key step that might be tricky. To make the hiding possible, it was
required to make the functions `static`:

```cpp
class studentCollection {
...
private:
...
    static bool lowerStudentNumber(studentRecord r1, studentRecord r2);
    static bool higherGrade(studentRecord r1, studentRecord r2);
    static bool namesComesFirst(studentRecord r1, studentRecord r2);

};
```

The reason for this is that by default C++ sets the function members as
methods. The signature of any method has the pointer `this` implicit in it
although is not visible in the method declaration. But the `typedef` we are
given does not have the `this` pointer because it is not needed.
To avoid that the compiler treats our search functions as methods and changes
its signature, we must make our search functions `static` so that the definition
matches with `typedef firstStudentPolicyFunc`.

## Final thoughts

This has been an exercise that has made me think a lot and experiment with
function pointers and their singularities in C++. It has made me realized that I
never really understood them when I was at college. Having understood them, now
lambda functions in any other modern language are more than ever a walk in the
park! I am also now more confident of using this pattern because my knowledge
of how to use it has been really solidified.
