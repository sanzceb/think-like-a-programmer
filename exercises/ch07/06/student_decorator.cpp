#include "student_decorator.h"

studentRecordTitle::studentRecordTitle(studentRecord & sc,
    string newTile)
    : studentDecorator(sc) {
    _tile = newTile;
}

studentRecordEnrollmentYear::studentRecordEnrollmentYear(studentRecord & sc,
    int newYear) : studentDecorator(sc) {
        _enrollmentYear = newYear;
    }

studentRecordAudit::studentRecordAudit(studentRecord & sc, bool isAudit)
    : studentDecorator(sc) {
        _isAudit = isAudit;
    }

int studentDecorator::grade() const {
    return _studentPtr->grade();
}

int studentDecorator::studentID() const {
    return _studentPtr->studentID();
}

string studentDecorator::name() const {
    return _studentPtr->name();
}

string studentRecordTitle::title() const {
    return _tile;
}

int studentRecordEnrollmentYear::enrollmentYear() {
    return _enrollmentYear;
}

bool studentRecordAudit::isAudit() {
    return _isAudit;
}
void studentRecordTitle::setTitle(string newTile) {
    _tile = newTile;
}

void studentRecordEnrollmentYear::setEnrollmentYear(int newYear) {
    _enrollmentYear = newYear;
}

void studentRecordAudit::setIsAudit(bool isAudit) {
    _isAudit = isAudit;
}