#include <iostream>

#include "student_decorator.h"

using std::cout;

int main() {
    studentRecord sr(94, 1230, "John Doe");
    studentRecordTitle srTitle (sr, "This is a tile");
    studentRecordEnrollmentYear srEnrYear (sr, 1985);
    studentRecordAudit srAudit(sr, true);

    cout << "Student:"
        << "\nName: " << srTitle.name()
        << "\nID: " << srTitle.studentID()
        << "\nGrade: " << srTitle.grade()
        << "\nTile: " << srTitle.title()
        << "\nEnrollment Year: " << srEnrYear.enrollmentYear()
        << "\nIs auditing?: " << (srAudit.isAudit() ? "Yes" : "No")
        << '\n';

}