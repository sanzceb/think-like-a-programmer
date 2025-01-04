#include <iostream>
#include <cassert>
#include <random>
#include <set>

#include "../shared/student_record.h"

using std::cout;

struct studentCompar {
    bool operator()(const studentRecord& a, const studentRecord& b) const {
        return a.studentID() < b.studentID();
    }
};

typedef std::set<studentRecord, studentCompar> studentCollection;
typedef studentCollection::iterator studentIterator;

// Helper functions for testing
void addRecord(studentCollection &sc, int stuNum, int gr);

void studentWithNumberTester();

int studentNumCompar(const void *voidA, const void *voidB) {
    studentRecord *studentA = (studentRecord *)voidA;
    studentRecord *studentB = (studentRecord *)voidB;
    return (*studentA).studentID() - (*studentB).studentID();
}

int studentWithNumber(studentRecord sc[], const int STUDENTS_NUM, int stuNum) {
    int begin = 0, end = STUDENTS_NUM - 1;
    // if(stuNum out of range)
    if (sc[begin].studentID() > stuNum || stuNum > sc[end].studentID()) {
        return -1;
    }
    while (begin <= end) {
        int valueDist = stuNum - sc[begin].studentID();
        int valueRange = sc[end].studentID() - sc[begin].studentID();
        int posRange = end - begin;
        int searchPos = begin + (valueDist * posRange) / valueRange;
        if (sc[searchPos].studentID() == stuNum) {
            return searchPos;
        }
        else if (sc[searchPos].studentID() < stuNum) {
            begin = searchPos + 1;
        } else {
            end = searchPos - 1;
        }
    }
    return -1;
}

void addRecord(studentCollection &sc, int stuNum, int gr) {
    studentRecord newStudent(gr, stuNum, "");
    sc.insert(newStudent);
}

void runBigInterpolation();

int main() {

    studentWithNumberTester(); 
    cout << '\n'; 
    runBigInterpolation();
    cout << '\n'; 
}

void studentWithNumberTester() {
    // Structures to create the random students
    studentCollection sc;
    std::random_device rd, rd2;
    std::uniform_int_distribution<> stuNumDist(1, 30000);
    std::uniform_int_distribution<> gradeDist(0, 100);
    // Resources to perform the search
    const int STUDENTS_NUM = 100;
    studentRecord scSorted[STUDENTS_NUM];
    int stuNum = 0;

    // Random Students evenly distributed
    while (sc.size() < STUDENTS_NUM) {
        int newStuNum = stuNumDist(rd);
        int newGrade = gradeDist(rd2);
        addRecord(sc, newStuNum, newGrade);
    }

    studentIterator it = sc.begin();
    for (int i = 0; i < STUDENTS_NUM; i++) {
        scSorted[i] = *it++;
    }

    // Students sorted by student number
    qsort(scSorted, STUDENTS_NUM, sizeof(studentRecord), studentNumCompar);
    stuNum = scSorted[0].studentID();

    // First student with number
    assert((studentWithNumber(scSorted, STUDENTS_NUM, stuNum) == 0 
        && "Student at pos 0 search failed"));

    stuNum -= 10;
    // Student below range with number
    assert((studentWithNumber(scSorted, STUDENTS_NUM, stuNum) == -1)
         && "Student out of range should not be found");

    // Last student with number
    stuNum = scSorted[STUDENTS_NUM - 1].studentID();
    assert(((studentWithNumber(scSorted, STUDENTS_NUM, stuNum) 
        == STUDENTS_NUM - 1) && "Last student search"));

    stuNum += 10;
    // Student above range with number "
    assert((studentWithNumber(scSorted, STUDENTS_NUM, stuNum) == -1) 
        && "Student out of range should not be found");

    stuNum = scSorted[STUDENTS_NUM / 2].studentID();
    assert(((studentWithNumber(scSorted, STUDENTS_NUM, stuNum) 
        == STUDENTS_NUM / 2) && "Student search failed"));

    cout << "All Test Passed!";
}

void runBigInterpolation() {
    // Setup the collection of students
    studentCollection sc;
    std::random_device rd, rd2;
    std::uniform_int_distribution<> stuNumDist(1, 100000);
    std::uniform_int_distribution<> gradeDist(0, 100);
    
    // Resources to perform the search
    const int STUDENTS_NUM = 20000;
    studentRecord  * scSorted = new studentRecord[STUDENTS_NUM]; 
    int stuNum = 0;

    // Performance metrics
    std::chrono::time_point<std::chrono::high_resolution_clock> t1, t2;
    
    while (sc.size() < STUDENTS_NUM) {
        int newStuNum = stuNumDist(rd);
        int newGrade = gradeDist(rd2);
        addRecord(sc, newStuNum, newGrade);
    }

    cout << "Students generated";
    studentIterator it = sc.begin();
    for (int i = 0; i < STUDENTS_NUM; i++) {
        scSorted[i] = *it++;
    }

    // Students sorted by student number
    qsort(scSorted, STUDENTS_NUM, sizeof(studentRecord), studentNumCompar);

    cout << "\nStudents sorted";
    studentRecord stu = scSorted[(3 * STUDENTS_NUM) / 4];
    cout << "\nSearching student " << stu.studentID();
    
    // Interpolation Search
    t1 = std::chrono::high_resolution_clock::now();
    int pos = studentWithNumber(scSorted, STUDENTS_NUM, stu.studentID());
    t2 = std::chrono::high_resolution_clock::now();
    
    assert(pos == (3 * STUDENTS_NUM) / 4);

    cout << "\nSample Size: " << sc.size()
    << "\nInterpolation Time: " 
    << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    // Linear Search
    t1 = std::chrono::high_resolution_clock::now();
    pos = 0;
    while (pos < STUDENTS_NUM && scSorted[pos].studentID() != stu.studentID()) {
        pos++;
    }
    t2 = std::chrono::high_resolution_clock::now();
    
    assert(pos == (3 * STUDENTS_NUM) / 4);
    
    cout << "\nLinear Search Time: "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    delete[] scSorted;
}
