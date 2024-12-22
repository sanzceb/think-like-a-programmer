# Exercise 3.1: [Sorting Students]

## Problem Statement

Are you disappointed we didn't do more with sorting? I'm here to help. To make  
sure you are comfortable with `qsort` write code that uses the function to sort  
to sort an array of our student struct. First have it sort by grade, and then  
try it again using the student ID.

## Approach
This is the definition of a student (add the book reference):  
```cpp
struct student {
    int grade;
    int studentID:
    std::string name;
};
```
Fortunately, the `grade` and the `studentID` are both integers, so this means  
that by solving one the first sorting problem, we just need to repeat the  
solution using the other property instead. Both problems can be reduced to the   
sorting of an array of integers an array of integers.

Here is my plan:
### Sorting Integers
Create a simple code that sorts an array of integers and makes a basic use  
of `qsort`:

```cpp
    int main() {
        const int ARRAY_SIZE = 5;
        int grades[ARRAY_SIZE] = {87, 28, 100, 78, 84};

        cout << "Grades before: ";
        for (int i = 0; i < ARRAY_SIZE; i++) cout << grades[i] << " ";
        cout << '\n';  
        
        qsort(grades, ARRAY_SIZE, sizeof(int), compareFunc);
        
        cout << "Grades after: ";
        for(int i = 0; i < ARRAY_SIZE; i++) cout << grades[i] << " ";
        cout << '\n';
    }
```

#### Output
```
Grades before: 87 28 100 78 84   
Grades after: 28 78 84 87 100
```

### Sorting students grades
Create another code that sorts an array of students by grade

```cpp
int main() {
    ...
    cout << "Students grades before: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << studentArray[i].grade << " ";
    }
    cout << '\n';  
    
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareFunc);
    
    cout << "Student grades sorted: ";
    for(int i = 0; i < ARRAY_SIZE; i++) {
        cout << studentArray[i].grade << " ";
    }
    cout << '\n';
}
```

#### Output
```
    Students grades before: 87 28 100 78 84 98 75 70 81 68 
    Students grades sorted: 28 68 70 75 78 81 84 87 98 100 
```  


### Sorting students ID

From the previous solution, repeat the approach to sort then by studentID.  
When the data used is the array provided by the book, we can see how sorting by  
 studentID restores the array.
    
#### Output
```
Students sorted by grade: Tom Veronica Candy Leslie Sasha ...
Students sorted by ID: Fred Tom Alistair Sasha ...
```