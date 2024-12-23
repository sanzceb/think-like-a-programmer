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
    studentCollection recordsWithinRange(const int begin, const int end);
    void output(); // Included for testing
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

studentCollection studentCollection::recordsWithinRange(
    const int begin, const int end) {
    if (begin > end) return studentCollection();
    studentCollection records;
    node* loopPtr = _listHead;
    while (loopPtr != NULL) {
        int grade = loopPtr->value.grade();
        if ((grade >= begin) && (grade <= end)) {
            records.addRecord(loopPtr->value);
        }
        loopPtr = loopPtr->next;
    }
    return records;
}

void studentCollection::output() {
    node* loopPtr = _listHead;
    while (loopPtr != NULL) {
        int grade = loopPtr->value.grade();
        if (grade < 10) cout << "   ";
        if (grade < 100) cout << "  ";
        else cout << ' ';
        cout << loopPtr->value.grade();
        loopPtr = loopPtr->next;
    }
}

int main() {
    studentCollection sc;
    sc.addRecord(studentRecord(87, 10001, "Fred"));
    sc.addRecord(studentRecord(28, 10002, "Tom"));
    sc.addRecord(studentRecord(100, 10003, "Alistair"));
    sc.addRecord(studentRecord(78, 10004, "Sasha"));
    sc.addRecord(studentRecord(84, 10005, "Erin"));
    sc.addRecord(studentRecord(98, 10006, "Belinda"));
    sc.addRecord(studentRecord(75, 10007, "Leslie"));
    sc.addRecord(studentRecord(70, 10008, "Candy"));
    sc.addRecord(studentRecord(81, 10009, "Aretha"));
    sc.addRecord(studentRecord(68, 10010, "Veronica"));

    studentCollection result1 = sc.recordsWithinRange(75, 80);
    cout << "Result 1:";
    result1.output();
    /* Returns:
    {78, 10004, "Sasha"}
    {75, 10007, "Leslie"}
    */

    cout << "\nResult 2:";
    studentCollection result2 = sc.recordsWithinRange(80, 90);
    result2.output();
    /* Returns:
    {87, 10001, "Fred"}
    {84, 10005, "Erin"}
    {81, 10009, "Aretha"}
    */

    cout << "\nResult 3:";
    studentCollection result3 = sc.recordsWithinRange(95, 100);
    result3.output();
    /* Returns:
    {100, 10003, "Alistair"}
    {98, 10006, "Belinda"}
    */

    cout << "\nResult 4:";
    studentCollection result4 = sc.recordsWithinRange(0, 70);
    result4.output();
    /* Returns:
    {28, 10002, "Tom"}
    {70, 10008, "Candy"}
    {68, 10010, "Veronica"}
    */
   
    cout << "\nResult 5:";
    studentCollection result5 = sc.recordsWithinRange(70, 0);
    result5.output(); cout << '\n';
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
