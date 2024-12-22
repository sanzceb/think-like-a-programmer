#include <iostream>

using std::cin;
using std::cout;
using std::vector;

struct frequencyStruct {
    int valueID;
    int frequencyValue;
};

int main() {
    // Input reading
    char digit;
    int histData;

    // Input Storage
    int frecuencySize = 0;
    vector<frequencyStruct> histogram;
    histogram.reserve(20);

    // The mode is the value of the max frecuency
    frequencyStruct maxFrecuency;

// do {
//    online input reading and processing
// } while(still in the line)
    do {
        // READ Decimal Integer
        histData = 0;
        digit = cin.get();
        while (digit != ' ' && digit != 10) {
            histData *= 10;
            histData += (digit - '0');
            digit = cin.get();
        }
        
        // if(smth read) PROCESS
        if (digit != 10) {
            // value SEARCH
            int frecuencyPos = 0;
            while (frecuencyPos < frecuencySize && 
                histogram[frecuencyPos].valueID != histData) {
                frecuencyPos++;
            }

            //if(value found) STORE frecuency else STORE NEW frecuency
            if (frecuencyPos < frecuencySize) {
                histogram[frecuencyPos].frequencyValue += 1;
            } else {
                frequencyStruct newFrecuency = {histData, 1};
                histogram.push_back(newFrecuency);
                frecuencySize++;
            }
        }
    } while(digit != 10);
    
    // SEARCH the mode
    frecuencySize = histogram.size();
    for (int i = 0; i < frecuencySize; i++) {
        if (histogram[i].frequencyValue > maxFrecuency.frequencyValue) {
            maxFrecuency = histogram[i];
        }
    }
    
    cout << "\nThe mode is: " << maxFrecuency.valueID << '\n';

    return 0;
}

