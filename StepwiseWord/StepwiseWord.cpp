#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	ifstream file;
	std::string line;
	std::string token;
	std::string answer = "";
	
	file.open(argv[1]);
		
	while(!file.eof())
	{
		getline(file, line);
		if(line.length() == 0) continue;
		else 
		{
			int pos = 0;
			while((pos = line.find(" ")) != std::string::npos)
			{
				token = line.substr(0, pos);
				line.erase(0, pos + 1);
				if(token.length() > answer.length())
					answer = token;
			}
			if(line.length() > answer.length())
				answer = line;
			
			cout << answer[0];
			
			std::string dummy = " *";
			
			for (pos = 1; pos != answer.length(); ++pos)
			{
				cout << dummy << answer[pos];
				dummy.append("*");
			}
			cout << endl;
			
			answer = "";
		}
	}
	
return 0;
} 
