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
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream stream(argv[1]);
    string line;
    string sub;
    vector<string> v;
    while (getline(stream, line))
    {
        v.clear();
        size_t pos = 0;
        while((pos = line.find(' ')) != string::npos)
        {
            sub = line.substr(0, pos);
            v.push_back(sub);
            line.erase(0, pos + 1);
        }
        v.push_back(line);

        for (vector<string>::const_reverse_iterator i = v.rbegin(); i != v.rend(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl;

    }
    return 0;
}
