// A better solution to the robot problem using arrays.
// This solution works faster, and uses less memory.

#include <iostream>
#define SIZE 4

int step(int grid[][SIZE], int i, int j)
{
    if (i < 0 || j < 0 || i > 3 || j > 3)
        return 0;
    if (grid[i][j] == 1)
        return 0;
    if ( i == 3 && j == 3)
        return 1;

    grid[i][j] = 1;
    int answer = 0;

	answer += step(grid, i - 1, j);
	answer += step(grid, i + 1, j);
	answer += step(grid, i, j - 1);
	answer += step(grid, i, j + 1);

	grid[i][j] = 0;
	return answer;

}

int main()
{
    int grid[][SIZE] = {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    std::cout<<step(grid, 0, 0)<<std::endl;
    return 0;
}
