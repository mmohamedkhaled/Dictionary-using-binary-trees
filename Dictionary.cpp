#include <iostream>
#include "Dictionary.h"
#include "BST.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Key, typename Data>

Dictionary<Key, Data>::Dictionary()
{
    for (int i = 0; i < 28; i++)
    {
        dictionary[i] = new BST<Key, Data>();
    }
}
template <typename Key, typename Data>

Dictionary<Key, Data>::~Dictionary()
{
    for (int i = 0; i < 28; ++i)
    {
        delete dictionary[i];
    }
}
template <typename Key, typename Data>
void Dictionary<Key, Data>::Dictionary_generation_save(string &filename)
{
    string output = "output.txt";

    Dictionary_generation(filename);
    Dictionary_save(output);
}
template <typename Key, typename Data>
void Dictionary<Key, Data>::Dictionary_generation(string &filename)
{
    ifstream dic(filename);
    if (!dic.is_open())
    {
        cout << "unable to open the file\n";
        exit(1);
    }
    string line;
    while (getline(dic, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            char first = tolower(word[0]);
            string temp_word = word;
            temp_word[0] = first;
            string temp_word2 = word;
            temp_word2[0] = toupper(word[0]);
            int index = first - 'a' + 1;
            if (index >= 1 && index <= 26)
            {
                if (!(dictionary[index]->search(temp_word)) && !(dictionary[index]->search(temp_word2)))
                {
                    dictionary[index]->insert(word, 1);
                }
            }
            else
            {
                dictionary[27]->insert(word, 1);
            }
        }
    }
    dic.close();
}

template <typename Key, typename Data>
void Dictionary<Key, Data>::Dictionary_update(Key word, int i)
{
    char first = tolower(word[0]);
    int index = first - 'a' + 1;
    if (i == 1)
    {
        dictionary[index]->remove(word);
    }
    else
    {
        dictionary[index]->insert(word, 1);
    }
}

template <typename Key, typename Data>
void Dictionary<Key, Data>::Dictionary_save(string &file)
{
    ofstream dic(file);

    if (!dic.is_open())
    {
        cout << "unaable to save the file\n";
    }
    else
    {
        for (int i = 1; i < 27; i++)
        {
            if (dictionary[i] != nullptr)
            {
                dictionary[i]->levelorder_to_screen(dic);
                // we can use other function
                // dictionary[i]->traverse_to_screen(dic);
            }
        }
    }
    dic.close();
}

// we can use this to read and reverse
template <typename Key, typename Data>
void Dictionary<Key, Data>::Dictionary_read(string &file)
{
    ofstream dic(file);

    if (!dic.is_open())
    {
        cout << "unaable to save the file\n";
    }
    else
    {
        for (int i = 1; i < 27; i++)
        {
            if (dictionary[i] != nullptr)
            {
                dictionary[i]->reverse_traverse_to_screen(dic);
            }
        }
    }
    dic.close();
}

template <typename Key, typename Data>
int Dictionary<Key, Data>::wordCount()
{
    int count[27] = {0};
    int sum = 0;
    int d = 0;
    for (int i = 1; i < 28; i++)
    {
        if (dictionary[i] != nullptr)
        {
            if (dictionary[i] != nullptr)
            {
                sum = sum + dictionary[i]->traverse(1);
            }
        }
    }
    return sum - 1;
}

int hammingDistance(const string &word1, const string &word2)
{
    int distance = 0;
    int determine;
    int max = 0;
    int min = 0;
    if (word1.length() < word2.length())
    {
        min = word1.length();
        max = word2.length();
    }
    else
    {
        min = word2.length();
        max = word1.length();
    }
    for (int i = 0; i < min; i++)
    {
        if (word1[i] != word2[i])
        {
            distance = distance + 1;
        }
    }
    distance = distance + max - min;

    return distance;
}

bool compareDistance(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename Key, typename Data>

vector<string> Dictionary<Key, Data>::suggest(const string &wrongword)
{
    vector<string> words;
    int count = 0;
    char first = tolower(wrongword[0]);
    string temp_word = wrongword;
    temp_word[0] = first;
    string temp_word2 = wrongword;
    temp_word2[0] = toupper(wrongword[0]);
    int index = first - 'a' + 1;
    if (index >= 1 && index <= 26)
    {
        if (dictionary[index] != nullptr)
        {
            typename BST<Key, Data>::TreeNode<Key, Data> *temp;
            temp = dictionary[index]->getroot();

            vector<pair<string, int>> distances;

            while (temp != nullptr)
            {
                if (count < 5)
                {
                    int x = hammingDistance(wrongword, temp->key);
                    distances.push_back({temp->key, x});
                    count = count + 1;
                    if (wrongword > temp->key && temp->left != nullptr)
                    {
                        temp = temp->left;
                    }
                    else if (wrongword < temp->key && temp->right != nullptr)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            sort(distances.begin(), distances.end(), compareDistance);
            int size = 0;
            if (5 > distances.size())
            {
                size = distances.size();
            }
            else
            {
                size = 5;
            }

            for (int i = 0; i < size; ++i)
            {
                words.push_back(distances[i].first);
            }
        }
    }

    return words;
}

template <typename Key, typename Data>
bool Dictionary<Key, Data>::check(const Key &word, vector<string> &words)
{
    char first = tolower(word[0]);
    string temp_word = word;
    temp_word[0] = first;
    string temp_word2 = word;
    temp_word2[0] = toupper(word[0]);
    int index = first - 'a' + 1;
    if (index >= 1 && index < 27)
    {
        if ((dictionary[index]->search(temp_word)) || (dictionary[index]->search(temp_word2)))
        {
            cout << "the word is spelled right\n";
            return true;
        }
        else
        {
            words = suggest(word);

            if (words.empty())
            {
                cout << "No suggestions found." << endl;
            }
            else
            {
                cout << "Suggestions for \"" << word << "\":" << endl;
                for (int i = 0; i < words.size(); i++)
                {
                    cout << words[i] << endl;
                }
            }
            return false;
        }
    }
    else if (dictionary[27]->search(word))
    {
        cout << "the word spelled right\n";
        return true;
    }
    else
    {
        words = suggest(word);
        if (words.empty())
        {
            cout << "No suggestions found." << endl;
        }
        else
        {
            cout << "Suggestions for \"" << word << "\":" << endl;
            for (int i = 0; i < words.size(); i++)
            {
                cout << words[i] << endl;
            }
        }
        return false;
    }

    return false;
}