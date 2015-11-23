#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string LCS(string string1, string string2)
{
    int m = string1.length();
    int n = string2.length();
    string substring1 = string1.substr(0, (m - 1 < 0) ? 0 : m - 1);
    string substring2 = string2.substr(0, (n - 1 < 0) ? 0 : n - 1);

    if (m == 0 || n == 0)
        return "";
    else if (string1[m - 1] == string2[n - 1])
        return LCS(substring1, substring2) + string1[m - 1];
    else
    {
        string a = LCS(string1, substring2);
        string b = LCS(substring1, string2);
        return (a.length() > b.length()) ? a : b;
    }
}


int main(int argc, char* argv[])
{
    ifstream infile;

    infile.open(argv[1]);

    while(!infile.eof())
    {
        string str1, str2;

        getline(infile, str1, ';');
        if(str1.empty())
            continue;

        getline(infile, str2);
        if(str2.empty())
            continue;

        cout << LCS(str1, str2) << endl;

    }

    return 0;
}
