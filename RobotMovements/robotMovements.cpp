#include <iostream>
#include <vector>

#define SIZE 4

int step(std::vector<std::vector<int> > grid, int i, int j)
{
    if (i < 0 || j < 0 || i > 3 || j > 3)
        return 0;
    if (grid[i][j] == 1)
        return 0;
    if ( i == 3 && j == 3)
        return 1;

    grid[i][j] = 1;

    return step(grid, i - 1, j) + step(grid, i + 1, j) + step(grid, i, j - 1) + step(grid, i, j + 1);
}


int main()
{
    std::vector<std::vector<int> > grid;
	std::vector<int> column1(4,0);
	for (int i = 0; i < SIZE; ++i)
		grid.push_back(column1);
    std::cout<<step(grid, 0, 0)<<std::endl;
    return 0;
}
