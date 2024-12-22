#include <iostream>
#include <sstream>
#include <format>

using std::cout;
using std::string;
using std::ostringstream;

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
    // Support Methods
    string description();
    int age();
private:
    // Data members
    string _manufacturer;
    string _model;
    int _modelYear;
    
    // Function members
    // Validation Support methods
    bool isValidModelYear(int modelYear);
    // Other support methods
    string modelYearString();
    int currentYear();
};

//Constructors
automobile::automobile() {
    setManufacturer("");
    setModel("");
    setModelYear(-1);
}

automobile::automobile(string newManufacturer, string newModelName
, int newModelYear) {
    setManufacturer(newManufacturer);
    setModel(newModelName);
    setModelYear(newModelYear);
}

// Returns a complete description of the automobile object
// as a formatted string. Ex: "1957 Chevrolet Impala"
string automobile::description() {    
    // we can work with ostringstream
    // like we work with the object cout
    ostringstream desc;
    desc << modelYearString()
        << ' ' << _manufacturer
        << ' ' << _model;
    return desc.str();
}

// Returns the age of the automobile in years
// If there is no valid model year, the age 
// returned will be -1
int automobile::age() {
    if (!isValidModelYear(_modelYear)) {
        return -1;
    } else {
        return currentYear() - _modelYear;
    }
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

// Private support methods
int automobile::currentYear() {
   // get Current Time since EPOCH
   // transforms it into local time
   // and gets the current year from
   // the yearspan since 1900
   time_t now = time(NULL);
   tm* ltm = localtime(&now);
   int year = 1900 + ltm->tm_year;
   return year;
}

string automobile::modelYearString() {
    if(!isValidModelYear(_modelYear)) 
        return "ERROR";
    else 
        return std::to_string(_modelYear);
}

int main() {
    automobile chevy("Chevrolet", "Impala", 1957);
    cout << "Chevy Description: " << chevy.description();
    cout << "\nChevy Age: " << chevy.age();
    automobile badAuto;
    cout << "\nDefault Description: " << badAuto.description();
    cout << "\nDefault Age: " << badAuto.age() << '\n';
} 
