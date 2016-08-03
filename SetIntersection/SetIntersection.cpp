/*
You are given two sorted list of numbers (ascending order). The lists themselves are comma delimited and the two lists are semicolon delimited. Print out the intersection of these two sets.
File containing two lists of ascending order sorted integers, comma delimited, one per line.
Print out the ascending order sorted intersection of the two lists, one per line. Print empty new line in case the lists have no intersection.
https://www.codeeval.com/open_challenges/30/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream myfile(argv[1]);
  string line; //for the entire line
  string str1; 
  string str2;
  string delimeter = ";";
  auto sep = "";
  int pos, num;
  vector<int> numbers1;
  vector<int> numbers2;
  vector<int> intersection;
  
  while(!myfile.eof()) {
    getline(myfile, line);
    if(line.length()==0) continue;

    numbers1.clear();
    numbers2.clear();
    intersection.clear();
    sep = "";

    pos = line.find(delimeter);
    str1 = line.substr(0, pos);
    str2 = line.substr(pos + 1, line.length() - pos);
    replace(str1.begin(), str1.end(), ',', ' ');
    replace(str2.begin(), str2.end(), ',', ' ');
    stringstream string1(str1);
    stringstream string2(str2);
    
    while(string1 >> num) numbers1.push_back(num);
    while(string2 >> num) numbers2.push_back(num);
    for(int i = 0; i < numbers1.size(); ++i) {
       for(int j = 0; j < numbers2.size(); ++j) {
         if(numbers1[i]==numbers2[j]) intersection.push_back(numbers1[i]);
       }
    }

    
    for(int i = 0; i < intersection.size(); ++i) {
      cout << sep << intersection[i];
      sep = ",";
    }  
    cout << endl;
  }
  return 0;
}
