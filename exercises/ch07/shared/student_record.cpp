#include "student_record.h"

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if (isValidGrade(newGrade)) {
        _grade = newGrade;
    }
}

string studentRecord::name() {
    return _name;
}

void studentRecord::setName(string newName) {
    _name = newName;
}
// For key comparators the const is required
int studentRecord::studentID() const {
    return _studentID;
}

void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}

studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord(int newGrade, int newID) {
    setGrade(newGrade);
    setStudentID(newID);
    setName("");
}

studentRecord::studentRecord() {
    setGrade(0);
    setStudentID(-1);
    setName("");
}


string studentRecord::title() {
    return "";
}

int studentRecord::enrollmentYear() {
    return -1;
}

bool studentRecord::isAudit() {
    return false;
}