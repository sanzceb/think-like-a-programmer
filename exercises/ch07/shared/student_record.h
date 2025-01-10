#include <string>
using std::string;

#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

class IStudentComponent {
public:
    virtual int grade() = 0;
    virtual int studentID() const = 0;
    virtual string name() = 0;
    virtual string title() = 0;
    virtual int enrollmentYear() = 0;
    virtual bool isAudit() = 0;
};

class studentRecord  : public IStudentComponent {
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);
    studentRecord(int newGrade, int newID);

    int grade(); 
    int studentID() const;
    int enrollmentYear();
    string name();
    string title();
    bool isAudit();

    void setGrade(int newGrade);
    void setStudentID(int newID);
    void setName(string newName);
private:
    int _grade;
    int _studentID;
    string _name;
    bool isValidGrade(int grade);
};

#endif