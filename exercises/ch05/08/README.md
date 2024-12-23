# Exercise 5.8: Student Records: Records within Range

## Problem Statement

For the student record collection class of the previous exercise, add a method
RecordsWithinRange that takes a low grade and a high grade as parameters and
returns a new collection consisting of the records in that range (the original
collection is unaffected). For example, myCollection.RecordsWithinRange(75, 80)
would return a collection of all records with grades in the range 75–80
inclusive.

## Class definition

Here is the updated version of the class, including `recordsWithinRange`:

```cpp
class studentCollection {
public:
    studentCollection();
    studentCollection(const studentCollection& original);
    ~studentCollection();

    studentCollection& operator=(const studentCollection& rhs);

    void addRecord(studentRecord newStudent);
    double averageRecord();
    studentCollection recordsWithinRange(const int begin, const int end);
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

Our collection is not sorted, so we are required to traverse the list and add
the student records whose grade equal or greater than `begin` and equal or
lesser than `end`.

## Solution Overview

The exercise was about extending the class `studentCollection` with a new
support method; `recordsWithinRange`:

```cpp
    studentCollection studentCollection::recordsWithinRange(
        const int begin, const int end) {
        if (begin > end ) return studentCollection(); //[1]
        studentCollection records;
        node* loopPtr = _listHead;
        while (loopPtr != NULL) { //[2]
            int grade = loopPtr->value.grade();
            if ((grade >= begin) && (grade <= end)) { //[3]
                records.addRecord(loopPtr->value);
            }
            loopPtr = loopPtr->next;
        }
        return records;
    }
```

[1]. We check if the range is actually valid otherwise we will avoid unnecessary
processing.

[2]. The implementation is based on a list traversal. Since the linked
list is not sorted we must retrieve all the nodes to ensure that we get all
the nodes that meet the requirements.

[3]. Only the nodes whose grade is within the range are valid nodes for the
final collection.

## Final thoughts

The completion of this chapter has been a great experience. By going through all
the exercises I had the opportunity of reapplying concepts learned in previous
chapters, like memory management, problem solving techniques, linked-list
fundamentals, etc. I expect that the recursion exercises go even deeper on this
path and allow me to solidify all of these concepts even more.
