/*
* - program a hash table of object pointers
* - Extend the student_record definition
* - Using the unordered_map API
*   - Implement addExtraField 
*   - Implement retrieveField
*/
#include <iostream>
using std::cout;
using std::string;
#include <unordered_map>
using std::unordered_map;
using std::pair;


template <typename T> 
T * retrieveField(string name, unordered_map<string, void*> hashTable) {
    return (T *)hashTable.at(name);
}

int main() {
    unordered_map<string, void *> hashTable;
    string value = "Problems of Unconditional Branching";
    bool audit = false;

    hashTable.insert(pair<string, string*>("title", &value));
    hashTable.insert(pair<string, bool*>("isAudit", &audit));
    cout << retrieveField<string>("title", hashTable)->c_str()
        << '\n'
        << ((*retrieveField<bool>("isAudit", hashTable)) ? "Yes" : "No");
}