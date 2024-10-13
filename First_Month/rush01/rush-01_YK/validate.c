#include <unistd.h>
#include <stdlib.h>

int	count_visible(int *line, int N, int reverse)
{
	int	max;
	int	count;
	int	i;
	int	index;

	max = 0;
	count = 0;
	i = 0;
	while (i < N)
	{
		if (reverse)
		{
			index = N - i - 1;
		}
		else
		{
			index = i;
		}
		if (line[index] > max)
		{
			max = line[index];
			count++;
		}
		i++;
	}
	return (count);
}

int validate_row(int *grid, int *clues, int N, int row)
{
	int left_clue;
	int right_clue;
	int visible_left;
	int visible_right;
	
	left_clue = clues[2 * N + row];
	right_clue = clues[3 * N + row];
	visible_left = count_visible(&grid[row * N], N, 0);
	visible_right = count_visible(&grid[row * N], N, 1);
	return (visible_left == left_clue && visible_right == right_clue);
}

int	validate_column(int *grid, int *clues, int N, int col)
{
	int	*column;
	int	i;
	int	visible_top;
	int	visible_bottom;

	column = malloc(N * sizeof(int));
	i = 0;
	while (i < N)
	{
		column[i] = grid[i * N + col];
		i++;
	}
	visible_top = count_visible(column, N, 0);
	visible_bottom = count_visible(column, N, 1);
	free(column);
	return (visible_top == clues[col] && visible_bottom == clues[N + col]);
}

int	is_safe(int row, int col, int num, int *row_masks, int *col_masks)
{
	return (!(row_masks[row] & (1 << num)) && !(col_masks[col] & (1 << num)));
}

int	valid_row_col(int *grid, int *clues, int N, int row, int col, int num, int *row_masks, int *col_masks)
{
	int	valid_row;
	int	valid_col;
	
	grid[row * N + col] = num;
	row_masks[row] |= (1 << num);
	col_masks[col] |= (1 << num);
	if (col == N - 1)
		valid_row = validate_row(grid, clues, N, row);
	else
		valid_row = 1;
	if (row == N - 1)
		valid_col = validate_column(grid, clues, N, col);
	else
		valid_col = 1;
	return (valid_row && valid_col);
}

int	solve(int *grid, int *clues, int N, int row, int col, int *row_masks, int *col_masks)
{
	int	num;

	if (row == N)
		return (1);
	if (col == N)
		return (solve(grid, clues, N, row + 1, 0, row_masks, col_masks));
	num = 1;
	while (num <= N)
	{
		if (is_safe(row, col, num, row_masks, col_masks))
		{
			if (valid_row_col(grid, clues, N, row, col, num, row_masks, col_masks))
				if (solve(grid, clues, N, row, col + 1, row_masks, col_masks))
					return 1;
			grid[row * N + col] = 0;
			row_masks[row] &= ~(1 << num);
			col_masks[col] &= ~(1 << num);
		}
		num++;
	}
	return 0;
}
