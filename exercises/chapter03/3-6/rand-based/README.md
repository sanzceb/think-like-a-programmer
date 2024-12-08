# Exercise 3.6 [Random Cipher Generator]

## Problem Statement
To make the ciphertext problem even more challenging, have your program   
randomly generate the cipher array instead of a hard-coded one `const` array.  
Effectively, this means placing a random character in each element of the array,  
but remember that you can't substitute a letter for itself. So the first  
element can't be A, and you can't use the same letter for two substitutions.  
That is, if the first element is S, no other element can be S.

## Approach

The problem consists of programming an initializer of the cipher array that   
must store at each step a random character. This initializer will be part of  
a program that executes the following tasks:

1.  Generate random cipher array ➜ Process input plain text ➜ 3. Outputs ciphered text 


Given a basic initializer, we can extend it for adding the required steps.

```cpp
    const int ALPHABET_SIZE = 26;
    char cipherArray[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char charToSubstitute; // GET letter i of the English Alphabet
        char newSubstitute;

        // do newSubstitute = NEW random character
        //while(substitute == charToSubstitute OR substitute already exists)
        cipherArray[i] = newSubstitute;
    }
```


I had issues thinking on how to generate a random character so I broke down the problem in two parts:  

- Generate a new random character. Write a program that generates a random  
 uppercase letter . I learned from the ciphering problems that this can be done  
 with *modulo* to generate the offset and using the character 'A' as base.  
 The base is always constant, so the only part that can be randomized  is  
 the offset. The solution makes use of the standard function `rand()` and the 
 sequence initializer `srand(seed)`
```cpp
    // NEW random sequence. This is key to ensure that each time we run 
    // the program the rand() uses a different sequence! Otherwise
    // The program will be idempotent. The system time ensures that behaviour.
    srand(time(nullptr));
    // newSubstitute = NEW random Uppercase Letter
    char newSubstitute = 'A' + (rand() % ALPHABET_SIZE)
    cout << newSubstitute;
```
- Write a program that returns a `bool` that checks if a target `char` exists
in a `char` array.
```cpp

bool arrayHasTarget(char target, char charArray[], int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // if(target already exists)
        if (charArray[i] == target) { 
            return true;
        }
    }
    return false;
}
```
  with this method we can then conveniently evaluate the existence of the  
  substitute in the part of alphabet that has already been created (from 0 to i):
```cpp 
    while ((newSubstitute == charToSubstitute) || 
        arrayHasTarget(newSubstitute, cipherArray, i));
```

After solving each problem, we can then put everything together along 
with the exercise 3-5 to test the random ciphering:

```cpp
    // NEW random sequence
    srand(time(nullptr));

    for (int i = 0; i < ALPHABET_SIZE; i++) {      
        char charToSubstitute = ('A' + i);        
        char newSubstitute; 

        // newSubstitute = NEW random substitute
        do newSubstitute = 'A' + (rand() % ALPHABET_SIZE);
        while ((newSubstitute == charToSubstitute) || 
            arrayHasTarget(newSubstitute, cipherArray, i));

        cipherArray[i] = newSubstitute;
    }

    cout << "Plain text:    ";
    char character = cin.get();
    cout << "Ciphered text: ";
    while (character != '\n') {
        // if (character IS Uppercase)
        if ('A' <= character && 'Z' >= character) {
            // character = LOOKUP character cipher
            character = cipherArray[character - 'A'];
        }
        cout << character;
        character = cin.get();
    }
    cout << character;
```

### Output
```
Plain text:    THIS IS A BIG MESSAGE THAT YOU CANNOT READ BELOW!
Ciphered text: ZPMH MH Q OMX SAHHQXA ZPQZ TCR BQDDCZ VAQF OANCJ!
```
At the next try:
```
Plain text:    THIS IS A BIG MESSAGE THAT YOU CANNOT READ BELOW!
Ciphered text: ZSBX BX T QBV IJXXTVJ ZSTZ RNL DTPPNZ HJTO QJFNG!
```

## Notes
I tried several approaches to generate the random offset based like using  
 uninitialized values since the random functions of the standard library  
 are not explained in the book at that point. Nothing gave me consistent  
 results so I use the `rand()` approach.

 I limited the processes to uppercase letters (A-Z) for simplicity.