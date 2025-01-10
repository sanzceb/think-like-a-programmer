#include <iostream>

#include "student_decorator.h"

using std::cout;

int main() {
    studentRecord sr(94, 1230, "John Doe");
    studentRecordTitle srTitle (sr, "This is a tile");
    studentRecordEnrollmentYear srEnrYear (srTitle, 1985);
    studentRecordAudit srAudit(srEnrYear, true);

    cout << "Title Student:"
        << "\nName: " << srTitle.name()
        << "\nID: " << srTitle.studentID()
        << "\nGrade: " << srTitle.grade()
        << "\nTile: " << srTitle.title()
        << "\nEnrollment Year: " << srTitle.enrollmentYear()
        << "\nIs auditing?: " << (srTitle.isAudit() ? "Yes" : "No")
        << '\n';
    
    cout << "\nEnrollment student:"
        << "\nName: " << srEnrYear.name()
        << "\nID: " << srEnrYear.studentID()
        << "\nGrade: " << srEnrYear.grade()
        << "\nTile: " << srEnrYear.title()
        << "\nEnrollment Year: " << srEnrYear.enrollmentYear()
        << "\nIs auditing?: " << (srEnrYear.isAudit() ? "Yes" : "No")
        << '\n';

    cout << "Audit Student:"
        << "\nName: " << srAudit.name()
        << "\nID: " << srAudit.studentID()
        << "\nGrade: " << srAudit.grade()
        << "\nTile: " << srAudit.title()
        << "\nEnrollment Year: " << srAudit.enrollmentYear()
        << "\nIs auditing?: " << (srAudit.isAudit() ? "Yes" : "No")
        << '\n';
}