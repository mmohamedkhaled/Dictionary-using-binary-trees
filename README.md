
Dictionary Application Readme
Overview
This C++ program implements a dictionary using a Binary Search Tree (BST) data structure. It provides functionalities such as dictionary generation, saving and updating, word count, spell checking, and suggesting similar words based on a given input.

Files
Dictionary.h: Header file containing the Dictionary class declaration.
BST.h: Header file containing the BST class declaration.
main.cpp: Main program file demonstrating the usage of the dictionary.
Compilation and Execution
To compile and run the program:

Ensure you have a C++ compiler installed (e.g., g++).
Compile the program using the command:
css
Copy code
g++ main.cpp -o dictionary
Run the compiled executable:
bash
Copy code
./dictionary
Functionality
1. Dictionary Generation
The Dictionary_generation function reads a list of words from a file and populates the dictionary.

2. Dictionary Save
The Dictionary_save function saves the contents of the dictionary to a specified output file.

3. Dictionary Update
The Dictionary_update function updates the dictionary by either adding or removing a word.

4. Word Count
The wordCount function calculates the total number of words in the dictionary.

5. Spell Check and Suggestions
The check function checks if a word is spelled correctly. If not, it suggests similar words using a Hamming distance algorithm.

Usage Example
cpp
Copy code
#include "Dictionary.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a Dictionary object
    Dictionary<string, bool> dic1;
    
    // File containing word list
    string file = "wordlist.txt";

    // Generate and save the dictionary
    dic1.Dictionary_generation_save(file);

    // Update the dictionary (remove "aaaa")
    dic1.Dictionary_update("ex1", 2);

    // Check a word and get suggestions
    vector<string> suggestions;
    dic1.check("ex2", suggestions);

    // Display the count of words in the dictionary
    cout << "Word count: " << dic1.wordCount() << endl;

    return 0;
}
Dependencies
Standard C++ libraries (<iostream>, <string>, <fstream>, <sstream>, <cctype>, <vector>, <algorithm>).
Notes
Make sure to provide a valid word list file (wordlist.txt) for dictionary generation.
The program demonstrates basic functionalities. You can extend it as needed for more advanced features.
