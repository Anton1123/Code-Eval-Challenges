/*
C++11
Write a program which reads a file and prints to stdout the specified number of the longest lines that are sorted based on their length in descending order.
Your program should accept a path to a file as its first argument. The file contains multiple lines. The first line indicates the number of lines you should output, the other lines are of different length and are presented randomly. You may assume that the input file is formatted correctly and the number in the first line is a valid positive integer.
Print out the longest lines limited by specified number and sorted by their length in descending order.
https://www.codeeval.com/open_challenges/2/
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

using namespace std;

struct Pair {
  int length;
  int line_number;
};

int main(int argc, char *argv[]) {
  ifstream myfile(argv[1]);
  string line;
  int N;
  getline(myfile, line);
  N = stoi(line);

  Pair p;
  vector<Pair> pairs;
  vector<int> results;
  int currentline = 1;
  
  // store the line number and length of each line from file
  while(!myfile.eof()) {
    getline(myfile, line);
    if(line.length()==0) continue;
    p.length = line.length();
    p.line_number = currentline++;
    pairs.push_back(p);
  }


  // find the N longest lines
  int longestline;
  int longestlength; 
  for(int i = 0; i < N; ++i) {
    longestlength = 0;
    for(int j = 0; j < pairs.size(); ++j) {
       if(pairs[j].length > longestlength) {
         longestlength = pairs[j].length;
         longestline = pairs[j].line_number;
       }
    }
    results.push_back(longestline);
    
    // remove line from pairs after adding to results
    vector<Pair> :: iterator it;
    for(it = pairs.begin(); it != pairs.end(); ++it) {
      if(it->line_number == longestline) {
          pairs.erase(it);
          break;
      }
    }
  }

  // print the results from file
  for(int k = 0; k < N; ++k) {
    // reset reading of file to the beginning. 
    myfile.clear();
    myfile.seekg(0, ios::beg);

    // get line number
    int printline = results.front();
    results.erase(results.begin());

    // iterate through text file correct number of lines
    int count = 0;
    while(count <= printline) {
      getline(myfile, line);
      ++count;
    }
    cout << line << endl;
  }
  return 0;
}















