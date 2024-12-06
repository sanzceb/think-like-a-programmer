#include <iostream>

using std::cout;

struct student {
    int grade;
    int studentID;
    std::string name;
};

int gradeCompar(const void * voidA, const void * voidB) {
    student * studentA = (student *) voidA;
    student * studentB = (student *) voidB;
    return (*studentA).grade - (*studentB).grade;
}

int studentIDCompar(const void * voidA, const void * voidB) {
    student * studentA = (student *) voidA;
    student * studentB = (student *) voidB;
    return (*studentA).studentID - (*studentB).studentID;
}

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    qsort(studentArray, ARRAY_SIZE, sizeof(student), gradeCompar);   
    cout << "Students sorted by grade: ";
    for(int i = 0; i < ARRAY_SIZE; i++) cout << studentArray[i].name << " ";
    cout << '\n';

    qsort(studentArray, ARRAY_SIZE, sizeof(student), studentIDCompar);
    cout << "Students sorted by ID: ";
    for(int i = 0; i < ARRAY_SIZE; i++) cout << studentArray[i].name << " ";
    cout << '\n';
}