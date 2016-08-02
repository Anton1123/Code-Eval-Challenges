/*
There is a monkey which can walk around on a planar grid. The monkey can move one space at a time left, right, up or down. That is, from (x, y) the monkey can go to (x+1, y), (x-1, y), (x, y+1), and (x, y-1).

Points where the sum of the digits of the absolute value of the x coordinate plus the sum of the digits of the absolute value of the y coordinate are lesser than or equal to 19 are accessible to the monkey. For example, the point (59, 79) is inaccessible because 5 + 9 + 7 + 9 = 30, which is greater than 19. Another example: the point (-5, -7) is accessible because abs(-5) + abs(-7) = 5 + 7 = 12, which is less than 19. How many points can the monkey access if it starts at (0, 0), including (0, 0) itself?
https://www.codeeval.com/open_challenges/60/
*/

#include <iostream>
#include <cmath>

#define SIZE 600
#define LIMIT 19

using namespace std;

int grid[SIZE][SIZE];

// adds up the digits of a number.
int compute(int x) {
    x = abs(x);
    if (x < 1)
        return 0;
    return ((x % 10) + compute (x /= 10));
}

void walk(int x, int y) {
    if((compute(x) + compute(y)) > LIMIT)
        return;
    int xx = x + SIZE / 2;
    int yy = y + SIZE / 2;
    if (grid[xx][yy] == 0) {
        grid[xx][yy] = 1;
        walk(x, y + 1);
        walk(x, y - 1);
        walk(x + 1, y);
        walk(x - 1, y);
    }
}

int main() {
    walk(0,0);

    int answer = 0;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(grid[i][j] == 1)
                ++answer;
        }
    }
    cout << answer;
    return 0;
}
