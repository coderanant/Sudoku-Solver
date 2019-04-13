#include <stdio.h>
#include <fstream>

bool Unassigned_dhund(int grid[9][9], int &row, int &col);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[9][9], int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations*/
bool SolveSudoku(int grid[9][9])
{
    int row, col;

    // If there is no unassigned location, we are done
    if (!Unassigned_dhund(grid, row, col))
       return true; // success!

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;

            // failure
            grid[row][col] = 0;
        }
    }
    return false;
}

/* Searches the grid to find an entry that is still unassigned*/
bool Unassigned_dhund(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether it will be legal to assign*/
bool isSafe(int grid[9][9], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}

/* A utility function to print grid  */
void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main()
{
    // 0 = unassigned cells
    int x,y,z;
    int grid[9][9];
    for(y=0;y<9;y++)
    {
    	for(z=0;z<9;z++)
    	scanf("%d",&grid[y][z]);
	}
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");

    return 0;
}
