Exercise 5.3 Variable-Length String

## Problem Statement

Take the variable-length string functions from Chapter 4 (append, concatenate,
and characterAt) and use them to create a class for variable-length strings,
making sure to implement all necessary constructors, a destructor, and an
overloaded assignment operator.

## Class definition
Here is the class I have defined to solve the exercise:

```cpp
class charCollection {
public:
    charCollection(); //[1]
    charCollection(const charCollection& original);
    ~charCollection();
    charCollection& operator=(const charCollection& rhs); //[2]
    char characterAt(int pos); //[3]
    void append(char c);
    void concatenate(const charCollection& s2);
    void output(); //[4]
private:
    struct charNode { //[5]
        char character;
        charNode * next;
    };
    typedef charNode * charList;
    charList _listHead; //[6]
    void deleteList(charList& listPtr); //[7]
    charList copiedList(const charList original);
};
```
In the public section, [1] first we specify the default, the copy constructor
and the destructor. [2] We define the overloading of the assignment operator.
[3] Lastly, we add the support methods; [4] I have added to the definition an
`output` method to see the content of the object.

In the private section, we put the type members [5], then the data members [6]
and finally the private support methods [7], which will support the
implementation of the methods of the public section.

## Conclusions

This has been an exercise of "putting things together" I have studied the problem
of the `studentCollection` explained in the book and I followed along. I have done
the minimum work required to rewrite the functions `characterAt`, `append` and
`concatenate` as support methods so the reader will notice that this is not enough
to make the implementation good. But since there is an exercise intended to do
refactoring, I will hold on the changes and wait for that exercise to make
improvements.
