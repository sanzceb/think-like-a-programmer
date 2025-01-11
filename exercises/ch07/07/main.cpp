#include <iostream>
using std::cout;
using std::string;

#include <unordered_map>

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
    _extraFields[name] = value;
}

string studentRecord::retrieveField(string name) {
    extraFieldsMap::iterator fieldIt = _extraFields.find(name);
    if (fieldIt != _extraFields.end()) {
        return fieldIt->second;
    } else {
        return "";
    }
}

int main() {

}