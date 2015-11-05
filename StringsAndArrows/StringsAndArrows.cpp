	#include <iostream>
	#include <fstream>
	#include <string>
	
	using namespace std;
	
	bool same_string(std::string a, std::string b) //checks if 2 strings are the same
	{
		if(a.length() != b.length())
			return false;
		else 
		{
			for (int i = 0; i < a.length(); i++)
			{
				if(a.at(i) != b.at(i))
					return false;
			}
			return true;
		}
	}
	
	int is_substring(std::string orig, std::string test) //how many occurances of a string are in another string
	{
		int count = 0;
		std::string token;
		int length_test = test.length();
		for (int i = 0; i < (orig.length() - test.length() + 1); i++)
		{
			token = orig.substr(i, length_test);
			if (same_string(token, test))
				++count;
		}
		return count;
	}
	
	int main(int argc, char *argv[]) 
	{
	
		ifstream file(argv[1]);
	    std::string line;
	    
		int answer;

	    while (!file.eof()) 
		{
			answer = 0;
			getline(file, line);
			if(line.length() == 0)
				continue;
			else
			{	
				answer = is_substring(line, ">>-->") + is_substring(line, "<--<<");
				cout << answer << endl;
			}
		}
		return 0;
	} 
