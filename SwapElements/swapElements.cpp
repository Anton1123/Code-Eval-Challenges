#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print_vector(vector<T> v) {
    for(typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void swap(vector<int> &v, int i, int j) {
    int foo;
    foo = v[i];
    v[i] = v[j];
    v[j] = foo;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        string inputs = "";
        string swaps = "";
        inputs = line.substr(0, line.find(":") - 1);
        swaps = line.substr(line.find(":") + 2, line.length() - 1);

        stringstream sstream(inputs);
        int num;
        vector<int> numbers;

        while(sstream >> num) {
            numbers.push_back(num);
        }

        vector<int> myswaps;
        replace(swaps.begin(), swaps.end(), ',', ' ');
        stringstream swapstream(swaps);
        while(swapstream >> num) {
            myswaps.push_back(num);
        }

        for(int i = 0; i < myswaps.size(); i += 2) {
            swap(numbers, myswaps[i], myswaps[i+1]*(-1));
        }

        print_vector(numbers);
    }
    return 0;
}
