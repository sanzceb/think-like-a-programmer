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
    int grade(); [3]
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

//Implementation of a get/set pair
int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if((newGrade >= 0) && newGrade <= 100) // Gatekeeper validation
        _grade = newGrade;
}
...

// Implementation of the custom constructor
studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}
```

[1], [4] In this basic structure, the function members go to the public section
and the data members go to the private section.

[2] The first `studentRecord` is the default constructor, the second is a custom
constructor.

[3] Retrieval and store methods declaration, commonly known as `get` and `set`.
