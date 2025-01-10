#include "../shared/student_record.h"

#ifndef STUDENT_DECORATOR_H
#define STUDENT_DECORATOR_H

class studentDecorator : public IStudentComponent {
public:
    int grade(); 
    int studentID() const;
    string name();

    virtual string title();
    virtual int enrollmentYear();
    virtual bool isAudit();
protected:
    studentDecorator(IStudentComponent &); 
private:
    IStudentComponent * _studentPtr;
};

class studentRecordTitle : public studentDecorator {
public:
    studentRecordTitle(IStudentComponent &, string newTitle);

    string title();
    void setTitle(string newTitle);

private:
    string _title;
};

class studentRecordEnrollmentYear : public studentDecorator {
public:
    studentRecordEnrollmentYear(IStudentComponent &, int newYear);

    int enrollmentYear();
    void setEnrollmentYear(int newYear);
private:
    int _enrollmentYear;    
};

class studentRecordAudit : public studentDecorator {
public:
    studentRecordAudit(IStudentComponent &, bool isAudit);

    bool isAudit();
    void setIsAudit(bool newIsAudit);
private:
    bool _isAudit;
};

#endif