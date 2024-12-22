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

int arrayMedian(student studentArray[], const int FROM, const int TO) { 
    const int MID = (TO - FROM) / 2;
    if ((TO - FROM) % 2 == 0) {
        return (studentArray[MID - 1 + FROM].grade 
            + studentArray[MID + FROM].grade) / 2;
    } else {
        return studentArray[MID + FROM].grade;
    }
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

    cout << "Quartile | Grade";
    // PROCESS quartiles    
    for (int quartile = 25; quartile <= 75; quartile += 25) {        
        // Store the quartile
        int upperBound, lowerBound;
        int quartileSize;
        // Store the target grade
        int quartileGrade;       
        // LOOKUP upper bound
        upperBound = (ARRAY_SIZE * quartile) / 100;                              
        // SIMPLE SEARCH the first value outside the quartile
        lowerBound = upperBound;        
        while (lowerBound > 0 && 
            (quartile == (lowerBound * 100) / ARRAY_SIZE)) {
            lowerBound--;
        }
    //  if (the quartile is a range) close the range        
        if (lowerBound < upperBound) lowerBound++;        
    // The quartile is the median of the range
        quartileGrade = arrayMedian(studentArray, lowerBound, upperBound);
        
        cout << "\n   " << quartile << "    |   " << quartileGrade;
    }    
    cout << '\n';

    return 0;
}