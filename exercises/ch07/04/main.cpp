#include <iostream>
#include <cassert>
#include <random>

#include "../shared/student_record.h"

using std::cout;

class symbolTable {
public:
    // Constructors
    symbolTable();
    symbolTable(int size);
    symbolTable(const symbolTable& original);
    // Destructor
    ~symbolTable();
    // Operators
    symbolTable & operator=(const symbolTable & rhs);
    // Support Methods
    void addRecord(int stuNum, int grade);
    studentRecord record(int stuNum);
private:
    typedef studentRecord * studentArray;
    const static int LOAD_FACTOR = 7;
    const static int RESIZE_FACTOR = 2;
    int _count;
    int _size;
    studentArray _studentMap;
    
    bool requiresResize();
    int hash(int stuNum);
    studentArray copiedArray(const studentArray & original);
};

typedef symbolTable studentCollection;

symbolTable::symbolTable() {
    _size = 10;
    _count = 0;
    _studentMap = new studentRecord[_size];
}

symbolTable::symbolTable(int size) {
    _size = size;
    _count = 0;
    _studentMap = new studentRecord[_size];
}

symbolTable::symbolTable(const symbolTable &original) {
    _size = original._size;
    _count = original._count;
    _studentMap = copiedArray(original._studentMap);
}

symbolTable::~symbolTable() {
    delete[] _studentMap;
}

symbolTable &symbolTable::operator=(const symbolTable &rhs) {
    if (this != &rhs) {
        delete[] _studentMap;
        _studentMap = copiedArray(rhs._studentMap);
        _size = rhs._size;
        _count = rhs._count;
    }
    return *this;
}

void symbolTable::addRecord(int stuNum, int grade) {
    if (requiresResize()) {
        // rehash
        int oldSize = _size;
        _size *= RESIZE_FACTOR;
        studentArray newArray = new studentRecord[_size];    
        for (int i = 0; i < oldSize; i++) {
            int stuID = _studentMap[i].studentID();
            if (stuID != -1) {
                int newPos = hash(stuID);
                newArray[newPos] = _studentMap[i];
            }
        }
        delete[] _studentMap;
        _studentMap = newArray;
    }
    int stuPos = hash(stuNum);
    _studentMap[stuPos] = studentRecord(grade, stuNum);
    _count++;
}

studentRecord symbolTable::record(int stuNum) {
    studentRecord retrieved = _studentMap[hash(stuNum)];
    if (retrieved.studentID() == stuNum) {
        return retrieved;
    } else {
        studentRecord dummy;
        return dummy;
    }
}

int symbolTable::hash(int stuNum) {
    return stuNum % _size;
}

symbolTable::studentArray symbolTable::copiedArray(
    const symbolTable::studentArray & original) {
    if (_size <= 0) return NULL;
    studentArray newStuArray = new studentRecord[_size];
    for (int i = 0; i < _size; i++) {
        newStuArray[i] = original[i];
    }
    return newStuArray;
}

bool symbolTable::requiresResize() {
    return ((_count * 10) / _size) >= LOAD_FACTOR;
}

void symbolTableBasicTester() {
    const int STUDENTS_NUM = 10;
    studentCollection sc(STUDENTS_NUM);

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
    // Structures to create the random students
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
        assert(sr.studentID() == stuNum);
    }
}

void symbolTableCopyTester() {
    studentCollection original(5);
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
