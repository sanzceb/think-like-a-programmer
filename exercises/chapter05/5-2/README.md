# Exercise 5.2 Automobile Description

## Problem Statement

For our automobile class from the previous exercise, add a support method
that returns a complete description of the automobile object as a formatted
string, such as, "1957 Chevrolet Impala". Add a second support method that
returns the age of the automobile in years.

## Class definition
I have added to the [previous class definition][link] the definition of the
following support methods:

```cpp
// Support Methods

// Returns a complete description of the automobile object
// as a formatted string. Ex: "1957 Chevrolet Impala"
string description();
// Returns the age in years
int age();
```

To implement the support method `description`, I have thought on appending
the three data members between spaces. But before that, I need to know how to
transform from integer to string. I am not familiar with the string class in
C++ so I will start with what I know first, and I will encapsulate this part in
another support method:

```cpp
string automobile::description() {
    string desc;
    string modelYearStr = modelYearString();
    desc.append(modelYearStr);
    desc.append(" ");
    desc.append(_manufacturer);
    desc.append(" ");
    desc.append(_model);
    return desc;
}
```

For the method `age` I have a similar situation. I do not know how to obtain
the current year before sutracting the `_modelYear`, so I will encapsulate the
logic to obtain the current year, to deal with that in the implementation:

```cpp
int automobile::age() {
    return currentYear() - _modelYear;
}
```

## Solution Overview

The final solution has diverged of what I had planned during the preliminary
analysis. Let's look at the code:
```cpp
string automobile::description() {    
    ostringstream desc; //[1]
    desc << modelYearString()
        << ' ' << _manufacturer
        << ' ' << _model;
    return desc.str();
}

int automobile::age() {
    if (!isValidModelYear(_modelYear)) {
        return -1;
    } else {
        return currentYear() - _modelYear;
    }
}

int automobile::currentYear() {
   // transforms it into local time
   // and gets the current year from
   // the yearspan since 1900
   time_t now = time(NULL); //[2]
   tm* ltm = localtime(&now); //[3]
   int year = 1900 + ltm->tm_year; //[4]
   return year;
}

string automobile::modelYearString() {
    if(!isValidModelYear(_modelYear)) 
        return "ERROR";
    else 
        return std::to_string(_modelYear);
}
```

[1] Instead of using the `string` api, I have decided to dig a little bit into
the C++ standard library and I found a class specialized in creating output
strings that shares implemention with the output stream object `cout`.

For the age, as we identified during the analysis, the key point of the method
implementation is about how to calculate the current year at runtime. Since
there is no guidance in the book about this topic, I have also looked into the 
C++ standard library.

[2] Get Current Time since *epoch*. *Epoch* is a reference point in time that is
used as a standard to start counting dates.

[3] The standard function `localtime`, reads a timestamp and returns a struct
that contains different data members of the current time.

[4] We are interested in the year, so we get the member `tm_year` which is the
years elapsed since 1900. This means that in order to get the current year, which in these terms represents the years lapsed since the year 0, we
must add 1900.

<!-- Links-->
[link]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/chapter05/5-1/README.md#class-definition)
