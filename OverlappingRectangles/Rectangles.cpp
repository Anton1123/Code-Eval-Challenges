#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void anyOverlap(int array[]) //Will solve by contradiction
{
	if((array[0] > array[6]) || (array[2] < array[4]) 
		|| (array[1] < array[7]) || (array[3] > array[5]))
	cout << "False";
	else 
	cout << "True";
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	//aUpLeftX (0), aUpLeftY (1), aLoRightX (2), aLoRightY (3);
	//bUpLeftX (4), bUpLeftY (5), bLoRightX (6), bLoRightY (7), 
	int array[8]; //index 0 is aUpLeftX, and so on, as ordered above ^
	
    ifstream file(argv[1]);
    std::string line;
    std::string token;
    int value;
    while (!file.eof()) 
	{
		getline(file, line);
		int pos = 0;
		int index = 0;
		//initialize array of points
		while ((pos = line.find(",")) != std::string::npos )
		{
			token = line.substr(0,pos);
			value = atoi(token.c_str());
			line.erase(0, pos + 1);	
			array[index] = value;
			++index;	
		}
		value =  atoi(line.c_str());
		array[index] = value;
		//end initialization
		anyOverlap(array); // Computation and Result Output
    }
    return 0;
} 
