#include <iostream>

using std::string;

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

//Constructors
automobile::automobile() {
    setManufacturer("");
    setModel("");
    setModelYear(-1);
}

automobile::automobile(string newManufacturer, string newModelName,
    int newModelYear) {
    setManufacturer(newManufacturer);
    setModel(newModelName);
    setModelYear(newModelYear);
}

// Get / Set pairs
string automobile::manufacturer(){ return _manufacturer;}
void automobile::setManufacturer(string newManufacturer) {
    _manufacturer = newManufacturer;
}

string automobile::model() {return _model;}
void automobile::setModel(string newModel) {
    _model = newModel;
}

int automobile::modelYear() {return _modelYear;}
void automobile::setModelYear(int newModelYear) {
    if (isValidModelYear(newModelYear)) {
        _modelYear = newModelYear;
    }
}

// Validation Support Methods
bool automobile::isValidModelYear(int modelYear) {
    if (modelYear >= 1888) return true;
    else return false;
}
