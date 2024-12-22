# Exercise 5.1 Basic Class Automobile

## Problem Statement
Let’s try implementing a class using the basic framework. Consider a class to
store the data for an automobile. We’ll have three pieces of data: a
manufacturer name and model name, both strings, and a model year, an integer.
Create a class with get/set methods for each data member. Make sure you make
good decisions concerning details like member names. It’s not important that
you follow my particular naming convention. What’s important is that you think
about the choices you make and are consistent in your decisions.

## Class definition
The `automobile` class have been design following the pattern of the [basic
class framework][ref1]. It is made of private data members and public function
members. The function members provide indirect access to the data members to
class client. Here is a solution based on that framework:

```cpp
class automobile {
public:
    // Constructors
    automobile();
    automobile(string newManufacturer, string newModel, int newModelYear);
    // Get / Set
    string manufacturer();
    void setManufacturer(string newManufacturer);
    string model();
    void setModel(string newModel);
    int modelYear();
    void setModelYear(int newModelYear);
private:
    // Data members
    string _manufacturer;
    string _model;
    int _modelYear;
    // Function members
    bool isValidModelYear(int modelYear);
};
```
Regarding the naming convention, I decided to stick to the book's convention.
As an extra I have added a validation support method that is a *gatekeeper* of
the model year set method which establishes the oldest model year, the year in
which Karl Benz commercialized its *Benz Patent-Motorwagen*.

[ref1]:(https://github.com/SanzCeb/think-like-a-programmer/blob/main/exercises/ch05/book-notes.md#the-basic-class-framework)