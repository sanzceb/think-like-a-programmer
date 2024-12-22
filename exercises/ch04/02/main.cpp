#include <iostream>

using std::cout;

typedef char * arrayString;

arrayString substring(arrayString str, int initPos, int subStrLen) {
	arrayString subStr = new char[subStrLen + 1];

	// Initial position starts from 1
	for (int i = 0; i < subStrLen; i++) {
		subStr[i] = str[initPos + i - 1];
	}

	subStr[subStrLen] = 0;

	return subStr;
}

void substringTester() {
	arrayString substr;
	arrayString str = new char[8];
	str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
	str[3] = 'd'; str[4] = 'e'; str[5] = 'f';
	str[6] = 'g'; str[7] = 0;
	
	substr = substring(str, 3, 4);
	cout << "String: " << str; 
	cout << "\nSubstring: " << substr << '\n';

	delete[] str;
	delete[] substr;
}

void emptyString() {
	arrayString emptyString = new char[1] {0};
	arrayString emptySubstr = substring(emptyString,0, 0);

	cout << "Empty String Test:" << emptyString
		<< "\nSubstring:" << emptySubstr;

	cout << "\nMemory Addresses:"
		<< "\nEmpty String:" << (void *) emptyString
		<< "\nSubstring :" << (void *) emptySubstr
		<< '\n';

	delete [] emptyString;
	delete [] emptySubstr;
}

int main () {
	substringTester();
	emptyString();
}
