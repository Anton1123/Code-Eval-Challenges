#include <iostream>

#define N 100000

using namespace std;

bool isprime(int k)
{
    int i = 2;
    while(i < k)
    {
        if(k % i == 0)
            return false;
        ++i;
    }
    return true;
}


int main()
{
    long int sum = 0;
    int counter = 0;
    for(int i = 2; i < N; ++i)
    {
        if(isprime(i))
        {
            sum += i;
            counter += 1;
        }
        if (counter == 1000)
            break;
    }
    cout << sum;
    return 0;
}
