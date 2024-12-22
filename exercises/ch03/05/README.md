# Exercise 3.5: [Cipher Decoder]
## Problem Statement
Have the previous program convert the ciphertext back to the plaintext to  
verify the encoding and decoding.

## Approach
Although at this point the online processing of characters is a problem I have  
already solved repeteadely, I worked first with a fixed-size array and I left  
the input processing aside thinking that I was required to store the input. 
Later I discovered I was wrong!

```cpp
const int VECTOR_SIZE = 28;
char cipheredVector[VECTOR_SIZE] = "HSTQLT, RG FGZ RTEGRT ZIOL!";

// TODO implement the input processing

for (int i = 0; i < VECTOR_SIZE; i++) {
    // if (character is UPPERCASE) decipher it
    if ('A' <= cipheredVector[i] && 'Z' >= cipheredVector[i]) {
        // Search the cipher code
        int cipherCode = 0;
        while (cipherCode < CIPHER_ALPHABET_SIZE && 
            CIPHER_ALPHABET[cipherCode] != cipheredVector[i]) {
            cipherCode++;        
        }
        cout << (char)('A' + cipherCode);
    } else cout << cipheredVector[i]; 
}

cout << '\n';
```
### Output: 
`PLEASE, DO NOT DECODE THIS!`

After solving the decoding subproblem, I then focused on how to decipher the  
input while processing it.
```cpp
cout << "Input a cipher text. I will decipher it!: ";
char character = cin.get();
while (character != '\n') {
    // if (character is UPPERCASE) decipher it
    if ('A' <= character && 'Z' >= character) {
        // Basic Array OP: Search the cipher code
        int cipherCode = 0;
        while (cipherCode < CIPHER_ALPHABET_SIZE && 
            CIPHER_ALPHABET[cipherCode] != character) {
            cipherCode++;        
        }
        character = ('A' + cipherCode);
    }
    cout << character; 
    character = cin.get();
}
cout << character;
```

### Output: 
```
Input a cipher text. I will decipher it!: HSTQLT, RG FGZ RTEGRT ZIOL!
PLEASE, DO NOT DECODE THIS!
```

## Notes
If you pay attention to the name of the array in the first sub problem, you  
will notice that I called it vector. That is because I thought at the beginning  
I was required to store the input and then processing it. But when I tackled  
the input processing storing the input in a vector, then I realized I could  
have done it online easily from the beginning!.