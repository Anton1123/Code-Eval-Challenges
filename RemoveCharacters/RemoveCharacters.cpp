/*
Write a program which removes specific characters from a string.
The first argument is a path to a file. The file contains the source strings and the characters that need to be scrubbed. Each source string and characters you need to scrub are delimited by comma.
Print to stdout the scrubbed strings, one per line. Ensure that there are no trailing empty spaces on each line you print.
https://www.codeeval.com/open_challenges/13/
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream myfile(argv[1]);
  string line; //for the entire line
  string str1; //for the string to be modified
  string str2; //for the characters
  string output;
  string delimeter = ",";
  bool flag;
  int pos;

  while(!myfile.eof()) {
    getline(myfile, line);
    if(line.length()==0) continue;
    output = "";
    pos = line.find(delimeter);
    str1 = line.substr(0, pos);
    str2 = line.substr(pos + 2, line.length() - pos);

    for(size_t i = 0; i < str1.length(); ++i) {
       flag = false;
       for(size_t j = 0; j < str2.length(); ++j) {
         if(str1[i]==str2[j]) flag = true;
       }
       if(flag==false) output+= str1[i];
    }
    cout<<output<<endl;
  }
  return 0;
}
