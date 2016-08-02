/*
Players generally sit in a circle. The first player says the number “1”, and each player says next number in turn. However, any number divisible by X (for example, three) is replaced by the word fizz, and any divisible by Y (for example, five) by the word buzz. Numbers divisible by both become fizz buzz. A player who hesitates, or makes a mistake is eliminated from the game.

Write a program that prints out the final series of numbers where those divisible by X, Y and both are replaced by “F” for fizz, “B” for buzz and “FB” for fizz buzz.

Your program should accept a file as its first argument. The file contains multiple separated lines; each line contains 3 numbers that are space delimited. The first number is the first divider (X), the second number is the second divider (Y), and the third number is how far you should count (N). You may assume that the input file is formatted correctly and the numbers are valid positive integers.

Print out the series 1 through N replacing numbers divisible by X with “F”, numbers divisible by Y with “B” and numbers divisible by both with “FB”. Since the input file contains multiple sets of values, your output should print out one line per set. Ensure that there are no trailing empty spaces in each line you print.
https://www.codeeval.com/open_challenges/1/
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream infile;
    infile.open(argv[1]);
    int a, b, c;

    while(infile >> a >> b >> c){
        if(1 % a == 0 && 1 % b == 0)
            cout << "FB";
        else if (1 % a == 0)
            cout << "F";
        else if (1 % b == 0)
            cout << "B";
        else
            cout << 1;

        for (int i = 2; i <=c; ++i) {
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
