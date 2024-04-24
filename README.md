# Dictionary Application

## Overview

This C++ program implements a dictionary using a Binary Search Tree (BST) data structure. It provides functionalities such as dictionary generation, saving and updating, word count, spell checking, and suggesting similar words based on a given input.

## Files

- `Dictionary.h`: Header file containing the `Dictionary` class declaration.
- `Dictionary.cpp`: Source file containing the implementation of the `Dictionary` class.
- `BST.h`: Header file containing the `BST` class declaration.
- `BST.cpp`: Source file containing the implementation of the `BST` class.
- `main.cpp`: Main program file demonstrating the usage of the dictionary.

## Compilation and Execution

### Prerequisites
- C++ compiler (e.g., g++)
- Standard C++ libraries

### Compilation
```sh
g++ main.cpp Dictionary.cpp BST.cpp -o dictionary

#### Functionality

- **Dictionary Generation**: Reads a list of words from a file and populates the dictionary.
- **Dictionary Save**: Saves the contents of the dictionary to a specified output file.
- **Dictionary Update**: Updates the dictionary by adding or removing a word.
- **Word Count**: Calculates the total number of words in the dictionary.
- **Spell Check and Suggestions**: Checks if a word is spelled correctly and suggests similar words using a Hamming distance algorithm.

##### Note
-Make sure to provide a valid word list file (wordlist.txt) for dictionary generation.
