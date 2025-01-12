#include <iostream>
using std::cout;
using std::string;


void replaceString(string& source, string target, string replaceText) {
    size_t targetLen = target.size();
    size_t replaceLen = replaceText.size();

    size_t pos = source.find(target);
    while (pos != string::npos) {
        source.replace(pos, targetLen, replaceText);
        pos = source.find(target, pos + replaceLen);
    }
}

void replaceStringTester() {
    string str = "abcdabee";
    string target = "ab";
    string replaceText = "xyz";

    cout << "Source before: "
        << str.c_str();

    replaceString(str, target, replaceText); 

    cout << "\nSource after: "
        << str.c_str() << std::endl;
}

int main() {
    replaceStringTester();
}