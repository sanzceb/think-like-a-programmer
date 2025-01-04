#include <iostream>

#include "../shared/student_record.h"

using std::cout;

class studentCollection {
public:
    enum firstStudentPolicy {
        HIGHER_GRADE, 
        LOWER_STUDENT_NUMBER, 
        NAMES_COMES_FIRST
    };

    studentCollection();
    ~studentCollection();
    studentCollection(const studentCollection &copy);
    studentCollection& operator=(const studentCollection &rhs);

    void setFirstStudentPolicy(firstStudentPolicy f);

    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int IDnum);
    void removeRecord(int IDnum);
    studentRecord firstStudent();

private:
    struct studentNode {
        studentRecord studentData;
        studentNode * next;
    };
    typedef studentNode * studentList;
    typedef bool (* firstStudentPolicyFunc)(studentRecord r1, studentRecord r2);


    studentList _listHead;
    firstStudentPolicyFunc _currentPolicy;
    
    void deleteList(studentList &studentList);
    studentList copiedList(const studentList& copy);
    
    // First Student Policies
    static bool lowerStudentNumber(studentRecord r1, studentRecord r2);
    static bool higherGrade(studentRecord r1, studentRecord r2);
    static bool namesComesFirst(studentRecord r1, studentRecord r2);

};

// Exercise implementation 

void studentCollection::setFirstStudentPolicy(
    studentCollection::firstStudentPolicy policy) {
    const firstStudentPolicyFunc STUDENT_POLICIES[] = {
        higherGrade, lowerStudentNumber, namesComesFirst
    };
    _currentPolicy = STUDENT_POLICIES[policy];
}

studentRecord studentCollection::firstStudent() {
    if (_listHead == NULL || _currentPolicy == NULL) {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    studentNode * loopPtr = _listHead;
    studentRecord first = loopPtr->studentData;
    loopPtr = loopPtr->next;
    while (loopPtr != NULL) {
        if (_currentPolicy(loopPtr->studentData, first)) {
            first = loopPtr->studentData;
        }
        loopPtr = loopPtr->next;
    }
    
    return first;
}

bool studentCollection::higherGrade(studentRecord r1, studentRecord r2) {
    return r1.grade() > r2.grade();
}

bool studentCollection::lowerStudentNumber(studentRecord r1, studentRecord r2) {
    return r1.studentID() < r2.studentID();
}

bool studentCollection::namesComesFirst(studentRecord r1, studentRecord r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

int main(){
    studentCollection sc;
    sc.addRecord(studentRecord(87, 10001, "Fred"));
    sc.addRecord(studentRecord(28, 10002, "Tom"));
    sc.addRecord(studentRecord(100, 10003, "Alistair"));
    sc.addRecord(studentRecord(78, 10004, "Sasha"));
    sc.addRecord(studentRecord(84, 10005, "Erin"));
    sc.addRecord(studentRecord(98, 10006, "Belinda"));
    sc.addRecord(studentRecord(75, 10007, "Leslie"));
    sc.addRecord(studentRecord(70, 10008, "Candy"));
    sc.addRecord(studentRecord(81, 10009, "Aretha"));
    sc.addRecord(studentRecord(68, 10010, "Veronica"));
    
    sc.setFirstStudentPolicy(sc.LOWER_STUDENT_NUMBER);
    cout << sc.firstStudent().studentID() << " "
        << sc.firstStudent().name() << '\n';

    sc.setFirstStudentPolicy(sc.HIGHER_GRADE);
    cout << sc.firstStudent().studentID() << " "
        << sc.firstStudent().name() << '\n';

}

// class studentCollection

studentCollection::studentCollection() {
    _listHead = NULL;
    _currentPolicy = NULL;
}

studentCollection::studentCollection(const studentCollection & original) {
    _listHead = copiedList(original._listHead);
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

studentCollection& studentCollection::operator=(const studentCollection & rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

void studentCollection::addRecord(studentRecord newStudent) {
    studentNode * newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int IDnum) {
    studentNode * loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != IDnum) {
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum) {
    studentNode * loopPtr = _listHead;
    studentNode * trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) return;
    trailing->next = loopPtr->next;
    delete loopPtr;
}

void studentCollection::deleteList(studentList & studentList) {
    while (studentList != NULL) {
        studentNode * tmpPtr = studentList->next;
        delete studentList;
        studentList = tmpPtr;
    }
}

studentCollection::studentList studentCollection::copiedList(
    const studentList & original) {
    if (original == NULL) return NULL;
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}
