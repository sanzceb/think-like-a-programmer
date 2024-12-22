# Exercise 3.8 [Grade Quartiles]

## Problem Statement
Write a program that processes an array of student objects and determines
the grade quartiles—that is, the grade one would need to score as well as or
better than 25% of the students, 50% of the students, and 75% of the students.

## Introduction
From the moment I finished reading the exercise, I had the intuition that this  
problem was not going to be so easy for me, because I didn't have a clear  
understanding of the statistical concept, and this is a problem focused on
statistical computation.

The reason for this is that the logic concerning the array manipulation was  
already built at exercise 3-1 when we were told to sort the array by students
grades first.

I will explain the data structures and the plan I tried to follow.

## Data Structures

For this exercise we will process an array of non-scalar. This time we are given  
an array called `studentArray` fixed at 10 `student` values.
```cpp
struct student {
    int grade;
    int studentID;
    std::string name;
};

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
```

On the other hand the target values, the *grade quartiles*, are three scalar values that we are told to *determine* through processing the array. Each quartile is represented by its percentage value are: `25, 50, 75`.

Since these values are in sequence, we can work with a scalar value that starts at quartile `25` and we add two times 25 to retrieve the other two quartiles.

 As I advanced during the introduction, I sensed that this part was going to be difficult, so my plan was created based on isolating from that part of the logic and then deal with it at the end.


The first problem is how to sort the students so that we have the students with the highest grades at the beginning and the students with the lowest grades at the end. This is achievied by sorting the array of students through `qsort`, technique which is taught in the book and that if we did the exercise [3.1](https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch03/01/), we should already have stored in a program. I did so to solve this part I had only to reuse that program and adapt it a bit and voilá:

```cpp
int gradeCompar(const void * voidA, const void * voidB) {
    student * studentA = (student *) voidA;
    student * studentB = (student *) voidB;
    return (*studentA).grade - (*studentB).grade;
}

int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {...};

    qsort(studentArray, ARRAY_SIZE, sizeof(student), gradeCompar);    
```

At this point, the array of students has already been processed. The next part is to write the logic that process each quartile and transforms it into a student position that we then can retrieve. I like the modulo to use as a search function because it guarantees we are given a valid result that is within the array bounds.

```cpp
    for (int i = 25; i <= 75; i+= 25) {
        int quartilePos = i % ARRAY_SIZE; // Dummy search        
        grade = studentArray[quartilePos].grade;
        cout << "\n   " << i << "    |   " << grade;
    }    
```

This was the output:

    Quartile  | Grade
        25    |   70
        50    |   81
        75    |   87

This was surprisingly a first good approximation, because for **quartile 25** we got 69, the grade that performs as well as or better than 30% of the students. Then for **quartile 50**, we got 81, representing the grade that performs as well as or better than 60% of students. For **quartile 75**, we got 87, performing as well as or better than 80% of students.

At this point, I was ready to start tackling the problem of the lookup function. I decided to try this simple problem myself first, and from there try to find the function. The result is in the below example:

```
[28 68 | 70 75 78 | 81 84 87 | 98 100]
      25%        50%        75%
       Q1         Q2         Q3
      (69)       (79)       (85)
```

In case of an array of n = 10 , there is no exact position that matches a student with a grade that is as well as or better than 25% percent of the students. The solution is in *the average* of the students at both sides of the quartile, which is known as the **median**.

However, if we extend the solution to an array of 100 elements, we intuitively can understand that the 25th student is the one that performs as well as or better than the 25% of students, the 50th student better than the 50% percent, etc.

In summary, the quartile is a statistical value that sometimes can be obtained by a direct lookup or by searching two array positions that define a *quartile range* and the calculate the median. This is my proposed solution.

```cpp
    for (int quartile = 25; quartile <= 75; quartile += 25) {        
        // Store the quartile
        int upperBound, lowerBound;
        int quartileSize;
        // Store the target grade
        int quartileGrade;       
        // LOOKUP upper bound
        upperBound = (ARRAY_SIZE * quartile) / 100; //[1]                             
        // SIMPLE SEARCH the first value outside the quartile
        lowerBound = upperBound; //[2]        
        while (lowerBound > 0 && 
            (quartile == (lowerBound * 100) / ARRAY_SIZE)) {
            lowerBound--;
        }
    //  if (the quartile is a range) close the range        
        if (lowerBound < upperBound) lowerBound++;        
    // The quartile is the median of the range
        quartileGrade = arrayMedian(studentArray, lowerBound, upperBound); //[3]
        
        cout << "\n   " << quartile << "    |   " << quartileGrade;
    }  
```
[1]. This function looks for the upper bound of the quartile within the range of the size of the sample.

[2]. Now that we get the upper bound of the quartile, we need to search the beginning of the quartile, if the quartile is a unique value, the lower and upper bound will be **the same**.

[3]. `arrayMedian` is an array function I programed previously and that I readapted to work within array subranges.


## Final thoughts 
That was it! It was one of the hardest exercise I solved within the book so far. It really pushed me hard into thinking how to compute the quartile. I loved statistics at college, but I am not well grounded these days on it, so I had to reapproach the problem multiple times until I arrived at the solution.

This time the final solution was a bit far from my initial plan, although I benefited a lot from isolating quartile calculation from the rest of the problem and dealing with it as a subproblem.

This problem has helped me point out my current weaknesses, which are mainly dealing with complex scalar calculations and going beyong the happy path and thinking of edge cases that can break my solution.