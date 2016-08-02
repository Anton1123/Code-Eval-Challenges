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
    
