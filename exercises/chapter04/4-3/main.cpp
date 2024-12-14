#include <iostream>

using std::cout;
using std::vector;

typedef char * arrayString;
typedef vector<int> arrayMatch;


int length(arrayString s) {
    int length = 0;
    while (s[length] != 0) {
        length++;
    }
    return length;
}

bool match(arrayString str, arrayString target, int initPos, int subStrLen) {	
    // Search for a mismatch
    for (int i = 0; i < subStrLen; i++) {
		if (str[initPos + i] != target[i]) {
            return false;
        }
	}

    return true;
}

arrayMatch createArrayMatches(arrayString source, arrayString target
    , int sourceLen, int targetLen) {
    arrayMatch matches;
    matches.reserve(10);

    int searchPos = 0;
    while (searchPos < sourceLen) {
     // if (substring matches target)
        if (match(source, target, searchPos, targetLen)) {
            matches.push_back(searchPos);
            searchPos += targetLen;
        } else {
            searchPos++;
        }
    }
    
    return matches;
}

void replaceString(arrayString& source, arrayString target
, arrayString replaceText){
    int sourceLen = length(source);
    int targetLen = length(target);
    int replaceLen = length(replaceText);

    arrayMatch matches = createArrayMatches(source, target, sourceLen
    , targetLen);
    int mSize = matches.size();

    // COMPUTE the new size based on the number of matches
    int newSourceLen = mSize * (replaceLen - targetLen) + sourceLen;
    arrayString newSource = new char[newSourceLen + 1];

   int newSourcePos = 0, sourcePos = 0, copyLen = 0;
    for(int i = 0; i < mSize; i++) {

        //COPY from source
        copyLen = matches[i] - sourcePos;
        for (int j = 0; j < copyLen; j++) {
            newSource[newSourcePos + j] = source[sourcePos + j];
        }

        newSourcePos += copyLen;
        sourcePos += copyLen;

        //COPY from replaceText
        for (int j = 0; j < replaceLen; j++) {
            newSource[newSourcePos + j] = replaceText[j];
        }
        
        newSourcePos += replaceLen;
        sourcePos += targetLen;
        
    }
    
    // COPY from the remaining source
    copyLen = sourceLen - sourcePos;
    for (int i = 0; i < copyLen; i++) {
        newSource[newSourcePos + i] = source[sourcePos + i];
    }

    delete[] source;
    newSource[newSourceLen] = 0;
    source = newSource;

}

void replaceStringTest() {
    arrayString str = new char[9];
	str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
	str[3] = 'd'; str[4] = 'a'; str[5] = 'b';
	str[6] = 'e'; str[7] = 'e'; str[8] = 0;

    arrayString target = new char[3];
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;

    arrayString replaceText = new char[4];
    replaceText[0] = 'x'; replaceText[1] = 'y'; 
    replaceText[2] = 'z'; replaceText[3] = 0;

    cout << "Source before: ";
    for (int i = 0; i < length(str); i++) {
        cout << str[i];
    }
    
    replaceString(str, target, replaceText);
    
    cout << "\nSource after : ";
    for (int i = 0; i < length(str); i++) {
        cout << str[i];
    }
    
    delete[] str;
    delete[] target;
    delete[] replaceText;
}

int main() {
    replaceStringTest();
}