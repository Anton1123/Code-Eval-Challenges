/* prints the sum of all integers from file 
   https://www.codeeval.com/open_challenges/24/
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream myfile;
    myfile.open(argv[1]);
    int num;
    int sum = 0;
    string str;

    while(!myfile.eof()) {
        
        getline(myfile, str);
        if (str.length() == 0) continue;
        else {
            num = stoi(str);
            sum += num;
        }
    }
    cout << sum << endl;
    return 0;
}
    
