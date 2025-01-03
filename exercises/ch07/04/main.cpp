#include <iostream>
#include <cassert>
#include <random>
#include <set>

struct studentRecord {
    int grade;
    int studentNum;
};

class symbolTable {
public:
    // Constructors
    symbolTable();
    symbolTable(const symbolTable& original);
    // Destructor
    ~symbolTable();
    // Operators
    symbolTable & operator=(const symbolTable & rhs);
    // Support Methods
    addRecord(int stuNum, int grade);
    studentRecord record(int stuNum);
private:
    typedef studentRecord * studentArray;
    const double LOAD_FACTOR = 0.7;
    const int RESIZE_FACTOR = 2;
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

symbolTable::addRecord(int stuNum, int grade) {
    studentRecord newSr;
    newSr.grade = grade;
    newSr.studentNum = stuNum;
    int stuPos = hash(stuNum);
    _studentArray[stuPos] = newSr;
}

studentRecord symbolTable::record(int stuNum) {
    return _studentArray[hash(stuNum)];
}

int symbolTable::hash(int stuNum) {
    return stuNum % _size;
}

studentArray symbolTable::copiedArray(const studentArray & original) {
    if (original._size <= 0) return NULL;
    studentArray newStuArray = new studentRecord[original._size];
    for (int i = 0; i < original._size; i++) {
        newStuArray[i] = original[i];
    }
    return newStuArray;
}

void symbolTableBasicTester();

int main() {
    symbolTableBasicTester();
}

// Helper code for testing
int studentNumCompar(const void *voidA, const void *voidB) {
    studentRecord *studentA = (studentRecord *)voidA;
    studentRecord *studentB = (studentRecord *)voidB;
    return (*studentA).studentNum - (*studentB).studentNum;
}

void symbolTableBasicTester() {
    studentCollection sc;
    std::random_device rd, rd2;
    std::uniform_int_distribution<> stuNumDist(1, 30000);
    std::uniform_int_distribution<> gradeDist(0, 100);

    // Resources to perform the search
    const int STUDENTS_NUM = 10;
    int stuNum = 0;

    // Random Students evenly distributed
    for (int i = 0; i < STUDENTS_NUM; i++) {
        int newStuNum = stuNumDist(rd);
        int newGrade = gradeDist(rd2);
        addRecord(sc, newStuNum, newGrade);    
    }

    // First student with number
    assert((sc.record(stuNum) == 0 
        && "Student at pos 0 search failed"));

    stuNum -= 10;
    // Student below range with number
    assert((sc.record(stuNum) == -1)
         && "Student out of range should not be found");

    // Last student with number
    stuNum = scSorted[STUDENTS_NUM - 1].studentNum;
    assert(((sc.record(stuNum) 
        == STUDENTS_NUM - 1) && "Last student search"));

    stuNum += 10;
    // Student above range with number "
    assert((sc.record(stuNum) == -1) 
        && "Student out of range should not be found");

    stuNum = scSorted[STUDENTS_NUM / 2].studentNum;
    assert(((sc.record(stuNum) 
        == STUDENTS_NUM / 2) && "Student search failed"));

    cout << "All Test Passed!";
}