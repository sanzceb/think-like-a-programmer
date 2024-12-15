# include <iostream>

using std::cout;

typedef char * arrayString;

int length(arrayString s) {
    return s[0] - '0';
}

void output(arrayString s) {
    int sLen = length(s);
    for (int i = 1; i <= sLen; i++) {
        cout << s[i];
    }
}

char characterAt(arrayString s, int position) {
    int sLen = length(s);
    //if (position out of bounds) return 0;
    if (0 > position || position >= sLen) return 0;
    return s[position + 1];
}

void append(arrayString& s, char c) {
    int oldLen = length(s);   
    // COPY s
    arrayString newS = new char[oldLen + 2];
    for (int i = 1; i <= oldLen; i++) {
        newS[i] = s[i];
    }    
    // STORE c and length
    newS[oldLen] = c;
    newS[0] = (oldLen + 1) + '0';

    delete[] s;
    s = newS;
}

void concatenate(arrayString& s1, arrayString s2) {
    int s1Len = length(s1);
    int s2_Len = length(s2);
    int newS1_Len = s1Len + s2_Len + 1;
    // COPY s1
    arrayString newS1 = new char[newS1_Len];  
    for (int i = 1; i <= s1Len; i++) {
        newS1[i] = s1[i];
    }
    //COPY s2 next to s1
    for (int i = 1; i <= s2_Len; i++) {
        newS1[s1Len + i] = s2[i];
    }
    //STORE new length
    newS1[0] = newS1_Len + '0';
    
    delete[] s1;
    s1 = newS1;
}

void lengthTester() {
    int stringSize = 5;
    arrayString s = new char[stringSize + 1];
    
    s[0] = stringSize + '0';
    s[1] = 'h'; s[2] = 'e'; s[3] = 'l'; s[4] = 'l'; s[5] = 'o';
    
    cout << length(s) << '\n';
    
    delete[] s;
}

void outputTester() {
    int stringSize = 5;
    arrayString s = new char[stringSize + 1];
    
    s[0] = stringSize + '0';
    s[1] = 'h'; s[2] = 'e'; s[3] = 'l'; s[4] = 'l'; s[5] = 'o';
    
    output(s); cout << '\n';
    
    delete[] s;
}

void characterAtTester() {
    int stringSize = 5;
    arrayString s = new char[stringSize + 1];
    
    s[0] = stringSize + '0';
    s[1] = 'h'; s[2] = 'e'; s[3] = 'l'; s[4] = 'l'; s[5] = 'o';

    for (int i = -1; i <= stringSize; i++) {
        cout << "\nChar " << i << ':' << characterAt(s, i);
    }
    cout << '\n';
}

void appendTester() {
    int strLen = 5;
    arrayString a = new char[strLen];
    a[0] = (strLen + '0'); a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    append(a, '!'); append(a, '\n');
    output(a);
    delete[] a ;
}

void concatenateTester() {
    arrayString a = new char[5];
    a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't'; a[0] = (4 + '0');
    arrayString b = new char[4];
    b[1] = 'b'; b[2] = 'e'; b[3] = 'd'; b[0] = (3 + '0');
    output(a); cout << '\n';
    output(b); cout << '\n';
    concatenate(a, b);
    output(a); cout << '\n';
    cout << (void *) a << '|' << (void * ) b << '\n';

    delete[] a;
    delete[] b;
}

int main() {
    concatenateTester();
}