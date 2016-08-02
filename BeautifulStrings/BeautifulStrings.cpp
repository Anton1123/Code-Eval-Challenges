/*
   Given a string s, little Johnny defined the beauty of the string as the sum of the beauty of the letters in it. The beauty of each letter is an integer between 1 and 26, inclusive, and no two letters have the same beauty. Johnny doesn't care about whether letters are uppercase or lowercase, so that doesn't affect the beauty of a letter. (Uppercase 'F' is exactly as beautiful as lowercase 'f', for example.) 
   https://www.codeeval.com/open_challenges/83/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int array1[26];

//for clearing the array and putting only 0's in the slots.
void initialize() {
    for (int i = 0; i < 26; ++i) {
        array1[i] = 0;
    }
}

//for sorting the array in decreasing order.
bool myCompare(int i, int j) {
    if (i > j) return true;
    else return false;
}

//makes the array of frequencies of each letter in descending order
void getArray(string myLine) {
    string::iterator i;
    for(i = myLine.begin(); i != myLine.end(); i++)
    {
        if (*i >= 'a' && *i <= 'z') 
            array1[*i - 'a']++;
        else if(*i >= 'A' && *i <= 'Z')
            array1[*i - 'A']++;
        else continue;
    }
    sort(array1, array1 + 26, myCompare);
}

void findBeauty()
{
    int beauty = 0;
    int counter = 26;
    for(int i = 0; i < 26; ++i)
    {
        beauty += array1[i] * counter;
        --counter;
    }
    cout << beauty <<endl;
}

int main(int argc, char* argv[])
{
    ifstream inputfile;
    string inputline;	
    inputfile.open(argv[1]);

    while(!inputfile.eof())
    {
        getline(inputfile, inputline);
        if(inputline.length() == 0) continue;
        else 
        {
            initialize();
            getArray(inputline);
            findBeauty();
        }
    }
    return 0;
}
