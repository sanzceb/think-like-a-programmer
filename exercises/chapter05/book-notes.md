# Chapter 5: Classes

This chapter is about classes and object-oriented programming and how to apply
them to solve problems, discussing when it is good and no so good to use them.

## The Basic Class Framework

The basic class framework gives us *information hiding* by declaring all the
data as private and then adding public methods to allow client code indirect
access to read or change the data.

```cpp
class studentRecord {
public: //[1]
    studentRecord(); //[2]
    studentRecord(int newGrade, int newID, string newName);
    int grade(); //[3]
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    string name();
    void setName(string newName);
private: //[4]
    int _grade;
    int _studentID;
    string _name;
};
```

[1], [4] In this basic structure, the function members go to the public section
and the data members go to the private section.

[2] The first `studentRecord` is the default constructor, the second is a custom
constructor.

[3] Retrieval and store methods declaration, commonly known as `get` and `set`.

```cpp
// Validation Support Methods
bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}
```
<!--ADD comment here -->

```cpp
//Implementation of a get/set pair
int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if(isValidGrade(_grade))
        _grade = newGrade;
}
```
<!--Comment about get/set-->

```cpp
// Constructors
studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord() { //[1]
    setGrade(0);
    setStudentID(-1);
    setName("");
}
```

[1]. The constructor without arguments is the *default constructor*. It is
usually set either with most common values or with illegitimate values to
make clear that it is a default object.

```cpp
//Support Methods [6]
// The function will convert the numerical grade into
// the appropriate string
string studentRecord::letterGrade() { //[7]
 if (!isValidGrade(_grade)) return "ERROR";
 const int NUMBER_CATEGORIES = 11;
 const string GRADE_LETTER[] = {...}
 const int LOWEST_GRADE_SCORE[] {...}
 
 // SEARCH category
 int category = 0;
 while (category <= NUM_CATEGORIES 
  && LOWEST_GRADE_SCORE[category] <= _grade) {
     category++;
 }
 return GRADE_LETTER[category - 1];
 }
```

[6] Support methods are common operations that a client of the class is expected
to perform with the data. They are also called *helper* or *auxiliary* methods.

[7] The reason for this method to get the grade letter on the fly instead of
storing it is avoiding *data redundancy*, since the grade letter does not tell
us anything we cannot get from the `_grade` itself

## Destructor

The *destructor* is a special method that is called when an object goes out of
scope. It is needed when a class creates dynamic data with `new`. Otherwise, we
would face memory leaks. The destructor must go in the public section, and its
name must correspond with the name of the class with a tilde before the name
to distinguish it from the constructors. For example:

```cpp
studentCollection::~studentCollection();
```

## Operator overloading

Operator overloading is a feature of C++ that allows us to change the default
behaviour of built-in operators. The definition of the method that overloads
the operator must be defined in the public section. The book overloads the
assignment operator as an example:

```cpp
studentCollection& operator=(const studentCollecion& rhs);
```
* `rhs` stands for right-hand-side and it is a name of common use in operator
overloads.
* The return type must be a direction, because C++ allows *assignment chaining*
like `s3 = s2 = s1;` so the type of the return value must be equal to the type
of the parameter.

## Copy constructor

A *copy constructor* is a constructor that takes an object of the same type:

```cpp
studentCollection(const studentCollection &original);
```

Copy constructors can be invoked to create object duplicates. Another important
issue about copy constructors is that they are used implicitely whenever an
object is passed as a value parameter. When we work with classes, it is better
to work with shared references (such as `const studentCollection &original`) to
avoid unnecessary processing work unless the function that takes the object
needs to modify a copy of it. This is because if, for example, an object
contains a linked-list of thousands of nodes created through dynamic memory,
these nodes are copied if the object is passed as value, and this ultimately
means a lot of unnecessary work being done.
