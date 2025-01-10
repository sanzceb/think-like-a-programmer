#include "student_decorator.h"

studentDecorator::studentDecorator(IStudentComponent &sc) {
    _studentPtr = &sc;
}

studentRecordTitle::studentRecordTitle(IStudentComponent & sc,
    string newTitle)
    : studentDecorator(sc) {
    _title = newTitle;
}

studentRecordEnrollmentYear::studentRecordEnrollmentYear(IStudentComponent & sc,
    int newYear) : studentDecorator(sc) {
        _enrollmentYear = newYear;
    }

studentRecordAudit::studentRecordAudit(IStudentComponent & sc, bool isAudit)
    : studentDecorator(sc) {
        _isAudit = isAudit;
    }

string studentDecorator::title() {
    return _studentPtr->title();
}

int studentDecorator::grade() {
    return _studentPtr->grade();
}

int studentDecorator::studentID() const {
    return _studentPtr->studentID();
}

string studentDecorator::name() {
    return _studentPtr->name();
}

int studentDecorator::enrollmentYear() {
    return _studentPtr->enrollmentYear();
}

bool studentDecorator::isAudit() {
    return _studentPtr->isAudit();
}

string studentRecordTitle::title() {
    return _title;
}

int studentRecordEnrollmentYear::enrollmentYear() {
    return _enrollmentYear;
}

bool studentRecordAudit::isAudit() {
    return _isAudit;
}
void studentRecordTitle::setTitle(string newTitle) {
    _title = newTitle;
}

void studentRecordEnrollmentYear::setEnrollmentYear(int newYear) {
    _enrollmentYear = newYear;
}

void studentRecordAudit::setIsAudit(bool isAudit) {
    _isAudit = isAudit;
}