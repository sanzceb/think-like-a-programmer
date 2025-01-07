#include <iostream>
#include <cassert>
#include <random>
#include <unordered_map>

#include "../shared/student_record.h"

using std::cout;

class symbolTable {
public:
    symbolTable();
    symbolTable(const symbolTable& original);

    symbolTable & operator=(const symbolTable & rhs);

    void addRecord(int stuNum, int grade);
    studentRecord record(int stuNum);
private:
    typedef std::unordered_map<int, studentRecord> studentMap;
    typedef std::pair<int, studentRecord> studentPair;
    studentMap _studentMap;
    
};

typedef symbolTable studentCollection;

symbolTable::symbolTable() {
    _studentMap.reserve(10);
}

symbolTable::symbolTable(const symbolTable &original) {
    _studentMap = original._studentMap;
}

symbolTable &symbolTable::operator=(const symbolTable &rhs) {
    if (this != &rhs) {
        _studentMap = rhs._studentMap;
    }
    return *this;
}

void symbolTable::addRecord(int stuNum, int grade) {
    studentRecord dummy;
    if ((stuNum != dummy.studentID()) && (grade != dummy.grade())) {
        studentRecord sr(grade, stuNum);
        _studentMap.insert(studentPair(stuNum, sr));
    }
}

studentRecord symbolTable::record(int stuNum) {
    studentMap::iterator retrieved = _studentMap.find(stuNum);
    if (retrieved != _studentMap.end()) {
        return retrieved->second;
    } else {
        studentRecord dummy;
        return dummy;
    }
}

void symbolTableBasicTester() {
    const int STUDENTS_NUM = 10;
    studentCollection sc;

    sc.addRecord(10000, 87);
    sc.addRecord(10001, 87);
    sc.addRecord(10002, 28);
    sc.addRecord(10003, 100);
    sc.addRecord(10004, 78);
    sc.addRecord(10005, 84);
    sc.addRecord(10006, 98);
    sc.addRecord(10007, 75);
    sc.addRecord(10008, 70);
    sc.addRecord(10009, 81);

   for (int i = 0; i < STUDENTS_NUM; i++) {
        int stuNum = 10000 + i;
        studentRecord sr = sc.record(stuNum);
        assert(sr.studentID() == stuNum);
   }
}

void symbolTableManyStudentsTester() {
    // Structures to create the random grades
    studentCollection sc;
    std::random_device rd;
    std::uniform_int_distribution<> gradeDist(1, 100);

    // Resources to perform the search
    const int STUDENTS_NUM = 100;

    // Random Students evenly distributed
    for (int i = 0; i < STUDENTS_NUM; i++) {
        int newGrade = gradeDist(rd);
        sc.addRecord(50000 + i, newGrade);
    }

    for (int i = 0; i < STUDENTS_NUM; i++) {
        int stuNum = 50000 + i;
        studentRecord sr = sc.record(stuNum);
        assert((sr.studentID() == stuNum));
    }
}

void symbolTableCopyTester() {
    studentCollection original;
    original.addRecord(4001, 90);
    original.addRecord(4002, 85);
    
    // Test copy constructor
    studentCollection copied(original);
    assert(copied.record(4001).grade() == 90);
    
    // Test assignment operator
    studentCollection assigned = original;
    assert(assigned.record(4002).grade() == 85);
    
    // Modify original and verify copies are independent
    original.addRecord(4001, 95);
    assert(copied.record(4001).grade() == 90);
}

int main() {
    symbolTableBasicTester();
    symbolTableManyStudentsTester();
    symbolTableCopyTester();
    cout << "All test passed!" <<  '\n';
}
