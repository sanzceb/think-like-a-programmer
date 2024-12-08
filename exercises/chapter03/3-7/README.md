# Exercise 3.7 [Mode Calculator]
## Problem Statement
Write a program that is given an array of integers and determines the *mode*,
which is the number that appears most frequently in the array.

## Approach
The first thing I did after reading the problem, was making sure that I   
understood what a *mode* means in statistics. Then I built up the solution  
 from there.

### Key Concepts
- The *mode* is the value of the highest frequency of a *histogram*.
- A *histogram* is a distribution of frecuencies.
- A *frequency* is the number of times a sample is found.

### Data Structure Analysis

At this point, my brain started thinking of formulating the problem in the  
 domain of data structures and trying to find analogies with my previous 
 problems, trying to apply the techniques of the book.


- The mode is a retrieved value from a given histogram, so it will be a scalar.
- A histogram is created by tracking the frecuencies of an array of integers.

I have seen so far two different arrays: fixed-size and vectors. Which one do I 
need? If I choose a fixed-size array, then I need a given size, which for a  
histogram is the size of the domain. In other words, the range of integers I  
can possibly read.Is it specified in the problem? Technically "yes", because  
we know they are *integers* but that is an infinite domain. So we don't know  
how much space will we need! So I need to know the domain before building 
the histogram, for that I will also need another vector.

Here are the list of the data structures I think we need:
- A scalar to retrieve the mode
- A vector to store the histogram
- A vector to store the sample domain

The remaining part of the problem is the input processing.  
Do I need to store it? I thought I did not, but at this point I choose to  
put all these thoughts in a plan and start coding. I think that was something  
I would figure out as I go.


### Implementation process

This is my initial list of subproblems:
- Search and Retrieve: Given a fixed histogram, find the mode.
- Store histogram: Given a sample of data and a known domain, store  
 the frecuencies of each value.
- Store domain: Given a fixed sample, store the domain of the sample

Here is how I "found" the mode (notice the problem in my first solution, I mixed the concepts and I missed the operation of looking up the actual mode):

```cpp
// SEARCH problem: find the max value within a fixed array of integers.
    const int HIST_SIZE = 8;
    int histogram[HIST_SIZE] = {5, 7, 8, 89, 3};

    int mode = 0;
    for (int i = 0; i < HIST_SIZE; i++) {
        if (histogram[i] > mode) mode = histogram[i];
    }
    cout << "The mode is: " << mode << '\n';
```

Then I worked on how to store the histogram:

```cpp
   //STORE problem: Create a histogram given the sample and domain in a fixed array
    const int DATA_SIZE = 50, DOMAIN_SIZE = 8;
    int histData[DATA_SIZE] = {...};
    int domain[DOMAIN_SIZE] = {...};
    vector<int> histogram;
    histogram.reserve(DOMAIN_SIZE);
    int histSize = 0;

    // A histogram starts with zeros
    for (int i = 0; i < DOMAIN_SIZE; i++) histogram.push_back(0);
    
    for (int i = 0; i < DATA_SIZE; i++) {
        //LOOKUP sample code in domain
        int domainPos = 0;
        while (domainPos < DOMAIN_SIZE && domain[domainPos] != histData[i]) {
            domainPos++;
        }
        //if(found) STORE sample in HISTOGRAM
        if (domainPos < DOMAIN_SIZE) histogram[domainPos] += 1;
    }
    
    cout << "Histogram view: ";
    histSize = histogram.size();
    for (int i = 0; i < histSize; i++) {
        cout << "\nValue: " << domain[i];
        cout << " frequency: " << histogram[i];
    }    
```

At this point I realized, the domain was something that could be calculated online! (And at the same time was carryng over the problem of the mode!)

```cpp
    //INPUT STORE
    const int DATA_SIZE = 50;
    int histData[DATA_SIZE] = {...};

    vector<int> domain;
    vector<int> histogram;
    int histSize = 0, domainSize = 0;

    //STORE problem: Create the domain and histogram vectors given the input
    domain.reserve(DATA_SIZE);
    for (int i = 0; i < DATA_SIZE; i++) {
        // LOOKUP data sample in domain
        int domainPos = 0;
        while (domainPos < domainSize && domain[domainPos] != histData[i]) {
            domainPos++;
        }
        // if(not found) THEN add it to the domain else count it
        if (domainPos == domainSize) {
            domain.push_back(histData[i]);
            histogram.push_back(1);
            domainSize++;
        } else {
            histogram[domainPos] += 1;
        }
    }
    
    cout << "Histogram view: ";
    histSize = histogram.size();
    for (int i = 0; i < histSize; i++) {
        cout << "\nValue: " << domain[i];
        cout << " frequency: " << histogram[i];
    }    

    // SEARCH problem: find the max value within a fixed array of integers.
    int mode = 0;
    histSize = histogram.size();
    for (int i = 0; i < histSize; i++) {
        if (histogram[i] > mode) mode = histogram[i];
    }
    cout << "\nThe mode is: " << mode << '\n';
    return 0;
}
```

To recap, at this point, the only thing I was left is the input processing, how do I read an array of values? Well, that is a problem that I already know how to solve from
previous exercises, so I just had to put it all together.

After a first solution, I looked at my code and I saw "bad smells" so I decided to refactor it, and the key point of this refactor was to get rid of the double vector and work with a `struct` that represents the frequency.

```cpp
struct frequencyStruct {
    int valueID;
    int frequencyValue;
};
```
And finally at this late stage during the refactor, I realized the big mistake  
at processing the histogram. Now finally, my program prints the actual mode.

There are nice improvements that could be easily implemented such a lookup of  
punctuation marks, but I think I did was the exercise was for and I can spend  
the time better on moving on to the next exercise. 

## Notes
Here is a list of key limitations:

- Assumes valid numeric input
- Requires space separation
- No handling of negative numbers

### Example usage
```
23 12 45 12 78 23 45 56 23

The mode is: 23
```