#include <iostream>
using std::cout;
using std::string;

#include <unordered_map>
#include <cassert>

class studentRecord {
public:
void addExtraField(string name, string value);
string retrieveField(string name);
private:
typedef std::pair<string, string> extraField;
typedef std::unordered_map<string, string> extraFieldsMap;

extraFieldsMap _extraFields;

};

void studentRecord::addExtraField(string name, string value) {
    // The operator [] always inserts the key does not exists
    // so it is more fit for insertion than for trying access
    if (!value.empty()) _extraFields[name] = value;
}

string studentRecord::retrieveField(string name) {
    extraFieldsMap::iterator fieldIt = _extraFields.find(name);
    if (fieldIt != _extraFields.end()) {
        return fieldIt->second;
    } else {
        return "";
    }
}

void emptyFieldsTester() {
    studentRecord sr1;
    assert(sr1.retrieveField("empty") == "");
}

void validFieldTester() {
    studentRecord sr1;
    string value = "Problems of Unconditional Branching";
    sr1.addExtraField("title", value);
    assert(sr1.retrieveField("title") == value);
}

void wrongKeyTester() {
    studentRecord sr1;
    string value = "Problems of Unconditional Branching";
    sr1.addExtraField("title", value);
    assert(sr1.retrieveField("Title") == "");
}

int main() {
   emptyFieldsTester(); 
   validFieldTester();
   wrongKeyTester();
}
