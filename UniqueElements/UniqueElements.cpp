/*
You are given a sorted list of numbers with duplicates. Print out the sorted list with duplicates removed.
Input is a file containing a list of sorted integers, comma delimited, one per line. 
Print out the sorted list with duplicates removed, one per line.
 
https://www.codeeval.com/open_challenges/29/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    string str;
    string line;
    int num, i;
    auto sep = "";

    while (!infile.eof()) {
        getline(infile, line);
        if (line.length() == 0) continue;
        num = -1;
        sep = "";
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
            while(ss >> str) {
                if (stoi(str) != num) {
                    num = stoi(str);
                    cout << sep << num;
                    sep = ",";
                } 
            }
        cout << endl;        
    }
    infile.close();
    return 0;
}

