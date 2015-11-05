#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputfile;
    string line;
    
    inputfile.open(argv[1]);
    
    int answer = 0;
    while (!inputfile.eof()) 
    {
    	getline(inputfile, line);
    	if(line.length() == 0) continue;
    	else
    	{
        int key = atoi(line.c_str());
        while(key != 0)
        {
            if(key >= 5)
            {
                key = key - 5;
                ++answer;
            }
            else if(key >= 3)
            {
                key = key - 3;
                ++answer;
            }
            else
            {
                key = key - 1;
                answer++;
            }
        }
    	}
        cout << answer << endl;
        answer = 0;
    }
    return 0;
} 
