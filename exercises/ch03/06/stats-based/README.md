# Exercise 3.6 [Random Cipher Generator based on Text Analysis]

## Problem Statement  
To make the ciphertext problem even more challenging, have your program   
randomly generate the cipher array instead of a hard-coded one `const` array.  
Effectively, this means placing a random character in each element of the array,  
but remember that you can't substitute a letter for itself. So the first element  
can't be A, and you can't use the same letter for two substitutions. That is,  
if the first element is S, no other element can be S.

## Approach
When I was about to give up with the random problem and move on to the next  
 exercise, I had a complete creative moment. Is not the plain-text something  
 that is unknown for the program and can be considered random? Wait! I have  
 written a [program](https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/chapter02/2-9)
                     that performs text analysis. I can use those statistics  
 as a seed! I felt that I had to give it a try before moving on to the  
 next exercise, so I started "fresh" on the problem again. Here was my new plan:

- Take the program 2-9 and:  
    - Store the plain-text in a vector.
    - Sum the three statistics to create the seed.
- Replace the Uppercase alphabet by  26 random characters by:
    - Increasing the seed to create the next random character
    - Keep increasing the seed while the random character does not pass  
    the checks

- Retrieve the plain-text and Print its ciphers.

Here are the final program steps:
1. Store plain-text while computing the seed 
2. Retrieve the uppercase alphabet and Store the cipher alphabet
3. Retrieve the plain and cipher texts 

## Refactoring
After doing all the work, I noticed "bad smells" as the book calls them. The   
program was looking too complex, so I decided to spend a good bunch of time  
doing some refactoring actions:

- Replace lookups based on switch by constant arrays
- New boolean functions that make the if statements more readable.
- Now there are a lot of variables, so I structured them and reorganized them.

## Final notes
If you have read some of my previous solutions, you will have noticed that the  
documents are quite technical. I think from now on these READMEs will have more  
the style of a blog of my thought process, and my experience doing the  
exercise. This reflects better the intention of this repository and the purpose  
of the book , which is about creativity in problem solving. I am not a C++  
professional, and I do not want by any means to try to convey that my  
programs are good examples of C++ programming.
