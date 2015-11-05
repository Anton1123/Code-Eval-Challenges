//score 97.5

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void tokenize(string& str, vector<string>& tokens)
{
	int pos;
	string token;
	while ((pos = str.find(" ")) != std::string::npos )
	{
		token = str.substr(0,pos);
		tokens.push_back(token); 
		str.erase(0, pos + 1);	
	}		
	tokens.push_back(str.c_str());	
}

bool isOperator(string str)
{
	if((str == "+") || (str == "*") || (str == "/") )
		return true;
	else
		return false;
}

float compute(string oper, float val1, float val2)
{
	if(oper == "+")
		return (val1 + val2);
	else if(oper == "*")
		return (val1 * val2);
	else if(oper == "/")
		return (val1 / val2); 
	else
		return 0;
}

void evalPrefix(vector<string>& expression)
{
	vector<float> numStack;
	float num1;
	float num2;
	
	for (int i = (expression.size() - 1); i >=0; i--)
	{
		if(isOperator(expression[i]))
		{
			num1 = numStack.back();
			numStack.pop_back();
			num2 = numStack.back();
			numStack.pop_back();
			numStack.push_back(compute(expression[i], num1, num2));
		}
		else
		{
			numStack.push_back(atoi(expression[i].c_str()));
		}
	}
	int i = int (numStack[0] + 0.5);
	cout << i << endl;
}



int main(int argc, char *argv[]) 
{
	ifstream file(argv[1]);
    string line;
    string token; 
	vector<string> tokens; 
    
    while (getline(file, line)) //processing the file
	{
		if(line.length() == 0)
			continue;
		else
		{
			tokens.clear();
			tokenize(line, tokens); //tokenizing the file
			if(tokens.size())
				evalPrefix(tokens);
		}
	}
	return 0;
} 



