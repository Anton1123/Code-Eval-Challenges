#include <iostream>
#include <fstream>
using namespace std;

int helper (int number)
{
	int counter = 0;
	int token = 0;
	int mask = 1;
	while(number != 0)
	{
		if ((number & mask) == 1)
			++counter;		
		number >>= 1;
		++token;
	}
	return counter;
}


int main(int argc, char *argv[]) {
    ifstream file(argv[1]);
    string line;
    int number;
    while (!file.eof()) 
	{
        file >> number;
        cout << helper(number) << endl;
    }
    return 0;
} 
