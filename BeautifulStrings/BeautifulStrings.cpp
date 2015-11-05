#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int array1[26];

void initialize() //for clearing the array and putting only 0's in the slots.
{
	for (int i = 0; i < 26; ++i)
	{
		array1[i] = 0;
	}
}

bool myCompare(int i, int j) //for sorting the array in decreasing order.
{
	if (i > j) return true;
	else return false;
}

void getArray(string myLine) //makes the array of frequencies of each letter in descending order
{
	string::iterator i;
	for(i = myLine.begin(); i != myLine.end(); i++)
	{
		if (*i >= 'a' && *i <= 'z') //if lower case letter case
			array1[*i - 'a']++;
		else if(*i >= 'A' && *i <= 'Z')
			array1[*i - 'A']++;
		else continue;
	}
	sort(array1, array1 + 26, myCompare);
}

void findBeauty()
{
	int beauty = 0;
	int counter = 26;
	for(int i = 0; i < 26; ++i)
	{
		beauty += array1[i] * counter;
		--counter;
	}
	cout << beauty <<endl;
}




int main(int argc, char* argv[])
{
		ifstream inputfile;
		string inputline;
		
		inputfile.open(argv[1]);
		
		while(!inputfile.eof())
		{
			getline(inputfile, inputline);
			if(inputline.length() == 0) continue;
			else 
			{
				initialize();
				getArray(inputline);
				findBeauty();
			}
		}
	
	return 0;
}







