#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 9
#define EMPTY 10
// Read sudoku 9x9 txt file and turn it into a nested list

bool findEmpty(int sudoku[N][N], int row, int col);
bool isValid(int sudoku[N][N], int row, int col, int num);


bool solve(int sudoku[N][N])
{
	int row, col;

	// check if Sudoku is full
	if (!findEmpty(sudoku, row, col))
	return true;

	for (int num = 1; num <= 9; num++)
	{
		if (isValid(sudoku, row, col, num))
		{
			sudoku[row][col] = num;
			if (solve(sudoku))
				return true;
			sudoku[row][col] = EMPTY;
		}
	}
	return false;
}

/* find if EMPTY or not*/
bool findEmpty(int sudoku[N][N], int row, int col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (sudoku[row][col] == EMPTY)
				return true;
	return false;
}

/* return bool if valid in row */
bool inRow(int sudoku[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}

/* return bool if valid in col */
bool inCol(int sudoku[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}

/* return bool if valid in 3x3 grid */
bool inGrid(int sudoku[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (sudoku[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}

/* return bool whether its okay to put a number there*/
bool isValid(int sudoku[N][N], int row, int col, int num)
{
	return !inRow(sudoku, row, num) &&
		!inCol(sudoku, col, num) &&
		!inGrid(sudoku, row - row%3 , col - col%3, num);
}

/* print */
void printSudoku(int sudoku[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			printf("%2d", sudoku[row][col]);
		printf("\n");
	}
}

int main()
{

	FILE *sudokuTxt;
	char line[1000];
	sudokuTxt = fopen("sudoku001.txt", "r");

	int num, sudoku[N][N], index = 8;
	while (fgets(line, 1000, sudokuTxt)!=NULL) {
		num = atoi(line);
		for(int i = 8; i>=0; i--)
			sudoku[i][index] = num%10;
			num = (num-num%10)/10;
		index--;
    fclose(sudokuTxt);
	}

	if (solve(sudoku) == true)
		printSudoku(sudoku);
	else
		printf("No solution");

	return 0;
}





