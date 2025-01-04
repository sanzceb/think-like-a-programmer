#include <iostream>
#include <forward_list>

#include "../shared/student_record.h"

using std::cout;

typedef std::forward_list<studentRecord> studentCollection;
typedef studentCollection::iterator studentIterator;

void addRecord(studentCollection & sc, int stuNum, int gr) {
    studentRecord newStudent(gr, stuNum, "");
    sc.push_front(newStudent);
}

double averageRecord(studentCollection & sc) {
    if (sc.empty()) return 0;
    int stuSum = 0; int count = 0;
    for (studentIterator iter = sc.begin(); iter != sc.end(); iter++) {
        stuSum += (*iter).grade();
        count++;
    }
    return (double) stuSum / count;
}

int main () {
    studentCollection sc;
    
    addRecord(sc, 1274, 91);
    addRecord(sc, 1001, 78);
    addRecord(sc, 1012, 93);
    addRecord(sc, 1076, 85);

    cout << "Average Record: " << averageRecord(sc) << '\n';
}
