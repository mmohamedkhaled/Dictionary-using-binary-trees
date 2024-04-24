#include <iostream>
#include "dictionary.h"
#include <string>
using namespace std;

int main()
{
   Dictionary<string, bool> dic1;
   string file = "wordlist.txt";
   dic1.Dictionary_generation_save(file);
   dic1.Dictionary_update("ex1", 2);
   vector<string> mo1;
   dic1.check("ex2", mo1);
   cout << "the count is:" << dic1.wordCount();

   return 0;
}