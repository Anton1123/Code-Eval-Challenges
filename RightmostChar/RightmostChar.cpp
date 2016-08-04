/*
You are given a string 'S' and a character 't'. Print out the position of the rightmost occurrence of 't' (case matters) in 'S' or -1 if there is none. The position to be printed out is zero based.
The first argument will ba a path to a filename, containing a string and a character, comma delimited, one per line. Ignore all empty lines in the input file. 
Print out the zero based position of the character 't' in string 'S', one per line. Do NOT print out empty lines between your output. 
https://www.codeeval.com/open_challenges/31/
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream myfile(argv[1]);
  string line;
  string str;
  string letter;
  int result;
  int pos;
  char delimiter = ',';

  while(!myfile.eof()) {
    getline(myfile, line);
    if(line.length()==0) continue;
    result = -1;

    pos = line.find(delimiter);
    str = line.substr(0, pos);
    letter = line.substr(pos + 1, line.length()-pos);
    for(int i = 0; i < str.length(); ++i) {
      if(str[i] == letter[0]) result = i;
    }
    cout << result << endl;
  }
  return 0;
}
