#include <bits/stdc++.h>
using namespace std;

bool UnassignedLocation(int grid[9][9],
							int& row, int& col);


bool isSafe(int grid[9][9], int row,
			int col, int num);


bool Sudoku(int grid[9][9])
{
	int row, col;

	
	if (!UnassignedLocation(grid, row, col))
	
		return true;

	for (int num = 1; num <= 9; num++) 
	{
		
		if (isSafe(grid, row, col, num)) 
		{
			
			grid[row][col] = num;

		
			if (Sudoku(grid))
				return true;

			grid[row][col] = 0;
		}
	}
	

	return false;
}

bool UnassignedLocation(int grid[9][9],
							int& row, int& col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] ==0 )
				return true;
	return false;
}

bool UsedRow(int grid[9][9], int row, int num)
{
	for (int col = 0; col < 9; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedCol(int grid[9][9], int col, int num)
{
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedBox(int grid[9][9], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return true;
	return false;
}


bool isSafe(int grid[9][9], int row,
			int col, int num)
{

	return !UsedRow(grid, row, num)
		&& !UsedCol(grid, col, num)
		&& !UsedBox(grid, row - row % 3,
						col - col % 3, num)
		&& grid[row][col] == 0;
}

void printGrid(int grid[9][9])
{
	for (int row = 0; row < 9; row++) 
	{
		for (int col = 0; col < 9; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}


int main()
{

	int grid[9][9] = { { 0, 0, 0, 0, 0, 2, 0, 0, 5 },
					{ 8, 0, 0, 7, 0, 0, 0, 0, 0 },
					{ 0, 0, 4, 0, 3, 8, 6, 0, 0 },
					{ 0, 1, 0, 9, 7, 0, 0, 0, 0 },
					{ 0, 2, 0, 0, 0, 0, 0, 5, 0 },
					{ 0, 4, 9, 0, 0, 6, 0, 8, 3 },
					{ 6, 0, 0, 0, 0, 1, 0, 0, 7 },
					{ 0, 0, 3, 0, 0, 0, 0, 9, 4 },
					{ 0, 9, 0, 2, 5, 0, 1, 0, 0 } };
	if (Sudoku(grid) == true)
		printGrid(grid);
	else
		cout << "can't find any solution to this ";

	return 0;
}