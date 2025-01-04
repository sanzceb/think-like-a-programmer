#include <string>
using std::string;

#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

class studentRecord {
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);
    studentRecord(int newGrade, int newID);
    int grade();
    void setGrade(int newGrade);
    int studentID() const;
    void setStudentID(int newID);
    string name();
    void setName(string newName);
private:
    int _grade;
    int _studentID;
    string _name;
    bool isValidGrade(int grade);
};

#endif