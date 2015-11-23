#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    int a, b, c;

    while(infile >> a >> b >> c)
    {
        if(1 % a == 0 && 1 % b == 0) //first case just to take care of trailing space
            cout << "FB";
        else if (1 % a == 0)
            cout << "F";
        else if (1 % b == 0)
            cout << "B";
        else
            cout << 1;

        for (int i = 2; i <=c; ++i)
        {
            if(i % a == 0 && i % b == 0)
                cout << " FB";
            else if (i % a == 0)
                cout << " F";
            else if (i % b == 0)
                cout << " B";
            else
                cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
