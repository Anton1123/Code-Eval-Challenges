/*
Given numbers x and n, where n is a power of 2, print out the smallest multiple of n which is greater than or equal to x. Do not use division or modulo operator.
Input sample:

The first argument will be a path to a filename containing a comma separated list of two integers, one list per line. E.g.

13,8
17,16

Output sample:

Print to stdout, the smallest multiple of n which is greater than or equal to x, one per line. E.g.

16
32
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void foo(int x, int n)
{
    if (n >= x)
    {
        cout << n << endl;
        return;
    }
    int counter = 2;
    int dummy = n;
    while(n < x)
    {
        n = dummy * counter++;
    }
    cout << n << endl;

}

int main(int argc, char *argv[])
{
    ifstream stream(argv[1]);
    string line, sub;
    int x, n;
    while (getline(stream, line))
    {
        if(line.length() == 0) continue;
        int pos = line.find(",");
        sub = line.substr(0, pos);
        x = atoi(sub.c_str());
        sub = line.substr(pos + 1, line.size() - pos);
        n = atoi(sub.c_str());
        foo(x, n);

    }
    return 0;
}
