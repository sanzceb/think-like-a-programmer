#include <iostream>

using std::cout;
using std::string;

class studentRecord {
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    string name();
    void setName(string newName);
private:
    int _grade;
    int _studentID;
    string _name;
    bool isValidGrade(int grade);
};

class studentCollection {
public:
    studentCollection();
    studentCollection(const studentCollection& original);
    ~studentCollection();

    studentCollection& operator=(const studentCollection& rhs);

    void addRecord(studentRecord newStudent);
    double averageRecord();

private:
    struct node {
        studentRecord value;
        node* next;
    };
    
    typedef node* listPtr;
    listPtr _listHead;

    bool isEmpty() const;

    node* lastNode();
    node* newNode(studentRecord value);
    void deleteList(listPtr& listPtr);
    listPtr copiedList(const listPtr& original);
};

void studentCollection::addRecord(studentRecord newStudent) {
    if (isEmpty()) {
        _listHead = newNode(newStudent);
    } else {
        lastNode()->next = newNode(newStudent);
    }
}

double studentCollection::averageRecord() {
    if (isEmpty()) return 0;
    int count = 0;
    double sum = 0;
    node * loopPtr = _listHead;
    while (loopPtr != NULL) {
        studentRecord record = loopPtr->value;
        sum += record.grade();
        count++;
        loopPtr = loopPtr->next;
    }
    return sum / count;
}

int main() {
    studentCollection sc;
    cout << "Empty average: " << sc.averageRecord();

    sc.addRecord({87, 10001, "Fred"});
    cout << "\nOne student average: " << sc.averageRecord();

    sc.addRecord({28, 10002, "Tom"});
    sc.addRecord({100, 10003, "Alistair"});
    sc.addRecord({78, 10004, "Sasha"});
    sc.addRecord({84, 10005, "Erin"});
    sc.addRecord({98, 10006, "Belinda"});
    sc.addRecord({75, 10007, "Leslie"});
    sc.addRecord({70, 10008, "Candy"});
    sc.addRecord({81, 10009, "Aretha"});
    sc.addRecord({68, 10010, "Veronica"});

    cout << "\nTen student average: " << sc.averageRecord();
}

// studentRecord Implementation

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if (isValidGrade(newGrade)) {
        _grade = newGrade;
    }
}

string studentRecord::name() {
    return _name;
}

void studentRecord::setName(string newName) {
    _name = newName;
}

int studentRecord::studentID() {
    return _studentID;
}

void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}

// studentCollection Implementation

studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord() {
    setGrade(0);
    setStudentID(-1);
    setName("");
}

studentCollection::studentCollection() {
    _listHead = NULL;
}

studentCollection::studentCollection(const studentCollection& original) {
    _listHead = copiedList(original._listHead);
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

studentCollection& studentCollection::operator=(const studentCollection& rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

bool studentCollection::isEmpty() const {
    return _listHead == NULL;
}

studentCollection::node* studentCollection::lastNode() {
    node * lastPtr = _listHead;
    node * loopPtr = _listHead;
    while(loopPtr != NULL) {
        lastPtr = loopPtr;
        loopPtr = loopPtr->next;
    }
    return lastPtr;
}

studentCollection::node* studentCollection::newNode(studentRecord value) {
    node * newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void studentCollection::deleteList(listPtr& listPtr) {
    while (listPtr != NULL) {
        node * tmpPtr = listPtr->next;
        delete listPtr;
        listPtr = tmpPtr;
    }
}

studentCollection::listPtr studentCollection::copiedList(
    const listPtr& original) {
    if (original == NULL) return NULL;
    listPtr newList = newNode(original->value);
    node * loopPtr = original->next;
    node * lastPtr = newList;
    while (loopPtr != NULL) {
        lastPtr->next = newNode(loopPtr->value);
        lastPtr = lastPtr->next;
        loopPtr = loopPtr->next;
    }
    return newList;
}
