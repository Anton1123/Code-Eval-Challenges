/*
You are given two sequences. Write a program to determine the longest common subsequence between the two strings.
https://www.codeeval.com/open_challenges/6/
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void LCS(string string1, string string2) {
    int m = string1.length() + 1; 
    int n = string2.length() + 1;

    int c[m][n]; //c[m-1][n-1] contains the answer (i.e. bottom-right cell)

    for (int x = 1; x < m; ++x)
        c[x][0] = 0;
    for (int y = 0; y < n; ++y)
        c[0][y] = 0;

    for (int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if (string1[i-1] == string2[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else if (c[i-1][j] >= c[i][j-1])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = c[i][j-1];
        }
    }

    int length = c[m-1][n-1];
    char answer[length+1];
    answer[length] = '\0';
    int i = m - 1;
    int j = n - 1;

    while(i > 0 && j > 0) {
        if(string1[i-1]==string2[j-1]) {
            answer[length-1] = string1[i-1];
            --i;
            --j;
            --length;
        }
        else if(c[i-1][j] > c[i][j-1])
            --i;
        else
            --j;
    }
    cout << answer << endl;
}

int main(int argc, char* argv[]) {
    ifstream infile;
    infile.open(argv[1]);

    while(!infile.eof()) {
        string str1, str2;

        getline(infile, str1, ';');
        if(str1.empty())
            continue;

        getline(infile, str2);
        if(str2.empty())
            continue;

        LCS(str1, str2);
    }
    return 0;
}
