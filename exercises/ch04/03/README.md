# Exercise 4.3 [String Replacer]

## Problem Statement

For our dynamically allocated strings, create a function `replaceString` that
takes three parameters, each of type `arrayString`: `source`, `target`, and
`replaceText`. The function replaces every occurrence of `target` in `source`
with `replaceText`. For example, if source points to an array containing 
`abcdabee`, target points to `ab`, and `replaceText` points to `xyz`, then when
the function ends, source should point to an array containing `xyzcdxyzee`.

## Problem definition and Data Structures

```cpp
typedef char * arrayString;
typedef vector<int> arrayMatch;

void replaceString(arrayString& source, arrayString target
 , arrayString replaceText){
```
I have defined a new type, `arrayMatch` that it will be an array that stores
the search positions of `target`.

## Solution overview

This function has been the most complex so far within this chapter!. I had to
break it down to implement it. The first part is searching and storing the
occurrences of `target`, and the last part is the creation of the new source
with all of the replacements in.

Here is my solution:

```cpp
void replaceString(arrayString& source, arrayString target
, arrayString replaceText){
    int sourceLen = length(source);
    int targetLen = length(target);
    int replaceLen = length(replaceText);

    arrayMatch matches = createArrayMatches(source, target, sourceLen
    , targetLen); //[1]
    int mSize = matches.size();

    // COMPUTE the new size based on the number of matches
    int newSourceLen = mSize * (replaceLen - targetLen) + sourceLen;
    arrayString newSource = new char[newSourceLen + 1]; //[2]

    int newSourcePos = 0, sourcePos = 0, copyLen = 0;
    for(int i = 0; i < mSize; i++) { //[3]

        //COPY from source
        copyLen = matches[i] - sourcePos;
        for (int j = 0; j < copyLen; j++) { //[4]
            newSource[newSourcePos + j] = source[sourcePos + j];
        }

        newSourcePos += copyLen; //[5]
        sourcePos += copyLen;

        //COPY from replaceText
        for (int j = 0; j < replaceLen; j++) { //[6]
            newSource[newSourcePos + j] = replaceText[j];
        }
        
        newSourcePos += replaceLen; //[7]
        sourcePos += targetLen;
        
    }
    
    // COPY from the remaining source
    copyLen = sourceLen - sourcePos;
    for (int i = 0; i < copyLen; i++) { //[8]
        newSource[newSourcePos + i] = source[sourcePos + i];
    }

    delete[] source;
    newSource[newSourceLen] = 0;
    source = newSource;

}
```

[1] The first step is to search and store the positions of `target` in `source`
in a vector. This will allow us to know exactly how much memory we need for our
new string. [2] With the length of the new `string`, the program is now ready to
allocate the memory. Depending on the size difference between `replace` and
`target`, `newSource` will grow or shrink compared to `source`.[3]. In the final
loop at step [4], we count the length of the substring and do an array copy with
range translation. Then at step [5] we do a simple array copy of `replaceText`.
In [5] and [7] we update the pointers accordingly after each copy. Once we are
out of replacements, in [8] we can copy whatever remains in `source`.

### Final thoughts

The difficulty increased significantly from [exercise 2][4-2]. However, by
methodically applying the techniques taught in the book (writing the function
shell and a test, breaking down the problem, drawing diagrams to follow the
references, etc) I have been capable of writing the program with confidence. I
barely spent a fraction of the time debugging.

<!-- Links -->
[4-2]: (https://github.com/SanzCeb/think-like-a-programmer/tree/main/exercises/ch04/4-2)