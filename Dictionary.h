#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<string>
#include<vector>
#include"BST.h"

template <typename Key, typename Data>

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();
    void Dictionary_generation( string &filename);
    void Dictionary_update(Key word,int i);
    void Dictionary_save( std::string&file);
    void Dictionary_read(string & file);
   void Dictionary_generation_save( string &filename);
    int wordCount();
    bool check(const Key& word, vector<string>& suggestions);
   std:: vector<std::string> suggest(const string & wrongword);
     BST<Key, Data>* operator[](int index) {
        if (index >= 1 && index <= 27) {
            return dictionary[index];
        }
         return nullptr; 
    }

private:
    BST< Key,  Data> *dictionary[28];
};

#include "Dictionary.cpp"
#endif // DICTIONARY_H
