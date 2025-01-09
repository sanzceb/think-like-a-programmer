#include "../shared/student_record.h"

#ifndef STUDENT_DECORATOR_H
#define STUDENT_DECORATOR_H

class studentDecorator {
public:
    int grade() const;
    int studentID() const;
    string name() const;
protected:
    studentDecorator(studentRecord & sc) {
        _studentPtr = &sc;
    }
private:
    studentRecord * _studentPtr;
};

class studentRecordTitle : public studentDecorator {
public:
    studentRecordTitle(studentRecord & sc, string newTitle);

    string title() const;
    void setTitle(string newTitle);

private:
    string _tile;
};

class studentRecordEnrollmentYear : public studentDecorator {
public:
    studentRecordEnrollmentYear(studentRecord & sc, int newYear);

    int enrollmentYear();
    void setEnrollmentYear(int newYear);
private:
    int _enrollmentYear;    
};

class studentRecordAudit : public studentDecorator {
public:
    studentRecordAudit(studentRecord & sc, bool isAudit);

    bool isAudit();
    void setIsAudit(bool newIsAudit);
private:
    bool _isAudit;
};

#endif