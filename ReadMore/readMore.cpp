#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    string str;

    while(getline(infile, str))
    {
        if(str.length() > 55)
        {
            str = str.substr(0, 40);
            int i = str.rfind(' '); // reverse find
            if(i != string::npos)
                str = str.substr(0, i);
            str += "... <Read More>";
        }
        cout << str << endl;
    }
    return 0;
}
