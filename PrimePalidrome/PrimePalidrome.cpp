//Write a program which determines the largest prime palindrome less than 1000.
//https://www.codeeval.com/open_challenges/3/

#include <iostream>

#define NUM 1000

bool isprime(int n)
{
    for(int i = 2; i < n; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool ispalidrome(int n)
{
    if(n < 10) // single digit is palidrome
    {
        return true;
    }
    else if (n < 100) //2-digit is palidrome if both digits are same
    {
        if((n % 10) == (n / 10))
            return true;
    }
    else
    {
        if((n % 10) == (n / 100)) //3-diit is palidrome if 1st and 3rd digit are the same. middle digit doesn't matter
            return true;
    }
    return false;
}

int main()
{
    for(int i = NUM - 1; i > 0; --i)
    {
        if(ispalidrome(i) && isprime(i))
        {
            std::cout << i;
            break;
        }
    }
    return 0;
}
