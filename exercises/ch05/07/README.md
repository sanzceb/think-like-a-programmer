# Exercise 5.7 Student Records: add and average

## Problem Statement

Take the student record functions from Chapter 4 (addRecord and averageRecord)
and use them to create a class representing a collection of student records, as
before, making sure to implement all necessary constructors, a destructor,
and an overloaded assignment operator.

## Solution Overview

This exercise was focused on encapsulating work done in previous exercise in
classes. First we took the definition of a studentRecord, taken from the book:

```cpp
class studentRecord {
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    string name();
    void setName(string newName);
private:
    int _grade;
    int _studentID;
    string _name;
    bool isValidGrade(int grade);
};
```

After that, the next task was to define the collection of students. To do this,
I readapted the class `charCollection` implemented to solve the problem of the
[previous exercise][5-7]. We only kept the implementation of the linked list
and all the necessary operations. On top of that, we added to the public
definition the required support methods: `addRecord` and `averageRecord`.

```cpp
class studentCollection {
public:
    studentCollection();
    studentCollection(const studentCollection& original);
    ~studentCollection();

    studentCollection& operator=(const studentCollection& rhs);

    void addRecord(studentRecord newStudent);
    double averageRecord();

private:
    struct node {
        studentRecord value;
        node* next;
    };
    
    typedef node* listPtr;
    listPtr _listHead;

    bool isEmpty() const;

    node* lastNode();
    node* newNode(studentRecord value);
    void deleteList(listPtr& listPtr);
    listPtr copiedList(const listPtr& original);
};
```

Lastly, I took the implementation of the functions `addRecord` and
`averageRecord` and encapsulated them into the class:

```cpp
void studentCollection::addRecord(studentRecord newStudent) {
    if (isEmpty()) {
        _listHead = newNode(newStudent);
    } else {
        lastNode()->next = newNode(newStudent);
    }
}

double studentCollection::averageRecord() {
    if (isEmpty()) return 0;
    int count = 0;
    double sum = 0;
    node * loopPtr = _listHead;
    while (loopPtr != NULL) {
        studentRecord record = loopPtr->value;
        sum += record.grade();
        count++;
        loopPtr = loopPtr->next;
    }
    return sum / count;
}
```

## Notes

Since programs are now bigger due to all the code required to implement
the linked list, I have put the code that has been reused below the function
`main()` to improve readability.

<!-- Links -->
[5-7]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch05/07/README.md)