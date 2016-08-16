/*
A happy number is defined by the following process. Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers.

The first argument is the pathname to a file which contains test data, one test case per line. Each line contains a positive integer.

If the number is a happy number, print out 1. If not, print out 0.
For the curious, here's why 7 is a happy number: 7->49->97->130->10->1. Here's why 22 is NOT a happy number: 22->8->64->52->29->85->89->145->42->20->4->16->37->58->89 ...
https://www.codeeval.com/open_challenges/39/
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int sum_of_squares(int num) {
  int sum;
  int count = 0;
  while(count < 1000) { // will iterate 1000 times. if no success of a 1, then return 0 (not a happy number)
    ++count;
    sum = 0;
    while(num > 0) {
			sum += (num % 10) * (num % 10);
			num /= 10;
    }
    num = sum;
    if(num == 1) return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  ifstream myfile(argv[1]);
	string line;
  int num;
  
  while(!myfile.eof()) {
    getline(myfile, line);
    if(line.length() == 0) continue;
    stringstream sstream(line);
    sstream >> num;   
    cout << sum_of_squares(num) << endl;
  }
	return 0;
}
