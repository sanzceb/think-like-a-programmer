# Exercise 3.4: [Cipher Encoder]

## Problem Statement
Here's a variation of the array of `const` values. Write a program for creating  
a substitution cipher problem. In a substitution cipher problem, all letters  
are created of uppercase letters and punctuation. The original message is  
called the plain text and you create the ciphertext by substituting each letter  
with another letter (for example each C could become and X). For this problem,  
hard-code a `const` array of 26 `char` elements for the cipher and have your  
program read a plaintext message and output the equivalent ciphertext.  

## Approach
I have divided the problem into three subproblems that I have already solved in
some way in the past.

1. Define the hard-code array
```cpp
    const char CIPHER_ALPHABET[] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
        'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'
    };
```
2. Process the *plaintext* from the user input as done in chapter 2
```cpp
    char character = cin.get();
    while (character != '\n') {
        character = cin.get();
    }
```
3. Output online each cipher character, skipping the ciphering of only the  
 blanks for simplicity.
```cpp
    char character = cin.get();
    while (character != '\n') {
        if (character != ' ') {
            character = CIPHER_ALPHABET[character - 'A'];
        }
        cout << character;
        character = cin.get();
    }
```
4. The final step was to implement the condition check for the uppercase.
```cpp
    char character = cin.get();
    while (character != '\n') {
        // if (character is an UPPERCASE letter)
        if ('A' <= character && 'Z' >= character) {
            character = CIPHER_ALPHABET[character - 'A'];
        }
        cout << character;
        character = cin.get();
    }
```
### Output example
```
Input a plaintext, I will cipher it!: ABCDEF-UVWXYZ
QWERTY-XCVBNM
```
## Final Notes
The final step was the one which was I could not remember easily and I had to  
go back to the deciphering problem, I left the pseudocode as a comment. This  
technique that is taught in the book is quite useful for me.