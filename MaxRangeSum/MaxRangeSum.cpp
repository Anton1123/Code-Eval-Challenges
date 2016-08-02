/*
Bob is developing a new strategy to get rich in the stock market. He wishes to invest his portfolio for 1 or more days, then sell it at the right time to maximize his earnings. Bob has painstakingly tracked how much his portfolio would have gained or lost for each of the last N days. Now he has hired you to figure out what would have been the largest total gain his portfolio could have achieved.

The input contains N, the number of days (0 < N < 10000), followed by N (separated by symbol ";") integers D (-10000 < D < 10000) indicating the gain or loss on that day.

Print out the maximum possible gain over the period. If no gain is possible, print 0.

https://www.codeeval.com/open_challenges/186/
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    else return b;
}

int maxSubArray(vector<int> values) {
    int max_so_far = values[0];
    int curr_max = values[0];
    for(int i = 1; i < values.size(); ++i)
    {
        curr_max = max(values[i], curr_max + values[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main(int argc, char *argv[]) {
    std::vector<vector<int> > Values; //to hold the values of the stock price change
    std::vector<int> Periods; //Range values for how long the subarray will be
    ifstream file(argv[1]);
    std::string line; //for the txt file input
    std::string token; //for the subtring that will be converted from char to int
    int value = 0; //for holding the value of stock change
    int period = 0; //for holding the value of the range
    int count = 0;// for holding how many total cases
    
    while (!file.eof()) {
        getline(file, line);
        if(line.length() == 0)
            continue;
        else {
            int pos = line.find(";");
            token = line.substr(0, pos);
            period = atoi(token.c_str());
            Periods.push_back(period); 
            line.erase(0, pos + 1);
			
            std::vector<int> list; // temporary list of values to be pushed back into the 2-d vector
	
            while ((pos = line.find(" ")) != std::string::npos ) {
                token = line.substr(0,pos);
                value = atoi(token.c_str());
                line.erase(0, pos + 1);	
                list.push_back(value);	
            }
            value = atoi(line.c_str());
            list.push_back(value);
			
            Values.push_back(list);
            ++count;
        }
    }

    for(int i = 0; i < Values.size(); ++i) {
        cout << maxSubArray(Values[i]);
        cout << endl;
    }

    return 0;
}
