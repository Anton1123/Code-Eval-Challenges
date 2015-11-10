#include <iostream>
#include <cmath> // abs()

#define SIZE 600
#define LIMIT 19

using namespace std;

int grid[SIZE][SIZE];

int compute(int x) // adds up the digits of a number.
{
    x = abs(x);
    if (x < 1)
        return 0;
    return ((x % 10) + compute (x /= 10));
}

void walk(int x, int y)
{
    if((compute(x) + compute(y)) > LIMIT)
        return;
    int xx = x + SIZE / 2;
    int yy = y + SIZE / 2;
    if (grid[xx][yy] == 0)
    {
        grid[xx][yy] = 1;
        walk(x, y + 1);
        walk(x, y - 1);
        walk(x + 1, y);
        walk(x - 1, y);
    }
}


int main()
{
    walk(0,0);

    int answer = 0;
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if(grid[i][j] == 1)
                ++answer;
        }

    }
    cout << answer;
    return 0;
}
