/*
  Given a number n and two integers p1,p2 determine if the bits in position p1 and p2 are the same or not. Positions p1 and p2 are 1 based.
  Input sample:
  The first argument will be a path to a filename containing a comma separated list of 3 integers, one list per line. E.g.
  86,2,3
  125,1,2
  Output sample:
  true
  false
  https://www.codeeval.com/open_challenges/19/
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void comparebits(int num, int p1, int p2) {
    //subtracting 1 from each position because if p1 = 1 then no need to shift. It is the first element.
    if(((num >> --p1) & 1) == ((num >> --p2) & 1)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int num, p1, p2;

    while (getline(stream, line)) {
        stringstream ss(line);
        ss >> num;
        ss.ignore();
        ss >> p1;
        ss.ignore();
        ss >> p2;
        comparebits(num, p1, p2);
    }
    return 0;
}
