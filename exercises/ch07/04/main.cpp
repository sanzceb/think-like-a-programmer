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
    // static const double LOAD_FACTOR = 0.7;
    // static const int RESIZE_FACTOR = 2;
    int _size;
    studentArray _studentArray;
    
    int hash(int stuNum);
    studentArray copiedArray(const studentArray & original);
};

typedef symbolTable studentCollection;

symbolTable::symbolTable() {
    _size = 10;
    _studentArray = new studentRecord[_size];
}

symbolTable::symbolTable(int size) {
    _size = size;
    _studentArray = new studentRecord[_size];
}

symbolTable::symbolTable(const symbolTable &original) {
    _size = original._size;
    _studentArray = copiedArray(original._studentArray);
}

symbolTable::~symbolTable() {
    delete[] _studentArray;
}

symbolTable &symbolTable::operator=(const symbolTable &rhs) {
    if (this != &rhs) {
        delete[] _studentArray;
        _studentArray = copiedArray(rhs._studentArray);
        _size = rhs._size;
    }
    return *this;
}

void symbolTable::addRecord(int stuNum, int grade) {
    studentRecord newSr(grade, stuNum);
    int stuPos = hash(stuNum);
    _studentArray[stuPos] = newSr;
}

studentRecord symbolTable::record(int stuNum) {
    studentRecord retrieved = _studentArray[hash(stuNum)];
    cout << "\nretrieved: " << retrieved.studentID() 
    << " " << retrieved.grade();
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

void symbolTableBasicTester() {
    const int STUDENTS_NUM = 10;
    studentCollection sc(STUDENTS_NUM);

    sc.addRecord(10001, 87);
    sc.addRecord(10002, 28);
    sc.addRecord(10003, 100);
    sc.addRecord(10004, 78);
    sc.addRecord(10005, 84);
    sc.addRecord(10006, 98);
    sc.addRecord(10007, 75);
    sc.addRecord(10008, 70);
    sc.addRecord(10009, 81);
    sc.addRecord(10010, 68);

    cout << "Students:\n";
   for (int i = 1; i <= STUDENTS_NUM; i++) {
        sc.record(10000 + i);
   }
   
}

int main() {
    symbolTableBasicTester();
}