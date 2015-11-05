	#include <iostream>
	#include <fstream>
	#include <cstdlib>
	#include <vector>
	
	using namespace std;
	
	int max(int a, int b)
	{
		if (a > b)
			return a;
		else return b;
	}
	
	
	int maxSubArray(vector<int> values)
	{
		int max_so_far = values[0];
		int curr_max = values[0];

		for(int i = 1; i < values.size(); ++i)
		{
			curr_max = max(values[i], curr_max + values[i]);
			max_so_far = max(max_so_far, curr_max);
		}
		return max_so_far;
	}
	
	int main(int argc, char *argv[]) 
	{
		std::vector<vector<int> > Values; //to hold the values of the stock price change
		ifstream file(argv[1]);
	    std::string line; //for the txt file input
	    std::string token; //for the subtring that will be converted from char to int
	    int value = 0; //for holding the value of stock change
	    
	    while (!file.eof()) 
		{
			int pos = 0;
			getline(file, line);
			if(line.length() == 0)
				continue;
			else
			{
				
				std::vector<int> list; // temporary list of values to be pushed back into the 2-d vector
		
				while ((pos = line.find(",")) != std::string::npos )
				{
					token = line.substr(0,pos);
					value = atoi(token.c_str());
					line.erase(0, pos + 1);	
					list.push_back(value);	
				}
				value = atoi(line.c_str());
				list.push_back(value);
				
				Values.push_back(list);
			}
		}
		
		for(int i = 0; i < Values.size(); ++i)
		{
			cout << maxSubArray(Values[i]);
			cout << endl;
		}
	
		return 0;
	} 
