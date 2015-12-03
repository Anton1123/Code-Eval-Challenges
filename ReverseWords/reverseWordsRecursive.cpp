/*
Link to challenge: https://www.codeeval.com/open_challenges/8/
Description:
Write a program which reverses the words in an input sentence.

Input sample:
The first argument is a file that contains multiple sentences, one per line. Empty lines are also possible.

For example:

Hello World
Hello CodeEval

Output sample:

Print to stdout each sentence with the reversed words in it, one per line. Empty lines in the input should be ignored. Ensure that there are no trailing empty spaces in each line you print.

For example:

World Hello
CodeEval Hello
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void foo(string s)
{
    size_t pos = s.find(' ');            // declare-and-use in one line
    string out = s.substr( 0, pos );     // saving the substring
    if ( pos != string::npos )
    {
        foo( s.erase( 0, pos + 1 ) );    // recurse, skipping the space...
        cout << " ";                     // ...but *print* the space
    }
    cout << out;                         // print the saved substring
}


int main(int argc, char *argv[])
{
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line))
    {
        foo(line);
        cout << endl;
    }
    return 0;
}
