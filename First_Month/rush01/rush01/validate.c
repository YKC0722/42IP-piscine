/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:37:35 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 16:39:35 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "puzzle.h"

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
			index = N - i - 1;
		else
			index = i;
		if (line[index] > max)
		{
			max = line[index];
			count++;
		}
		i++;
	}
	return (count);
}

int	validate_row(t_puzzle *puzzle, int row)
{
	int	left_clue;
	int	right_clue;
	int	visible_left;
	int	visible_right;

	left_clue = puzzle->clues[2 * puzzle->n + row];
	right_clue = puzzle->clues[3 * puzzle->n + row];
	visible_left = count_visible(&puzzle->grid[row * puzzle->n], puzzle->n, 0);
	visible_right = count_visible(&puzzle->grid[row * puzzle->n], puzzle->n, 1);
	return (visible_left == left_clue && visible_right == right_clue);
}

int	validate_column(t_puzzle *puzzle, int col)
{
	int	*column;
	int	i;
	int	visible_top;
	int	visible_bottom;

	column = malloc(puzzle->n * sizeof(int));
	i = 0;
	while (i < puzzle->n)
	{
		column[i] = puzzle->grid[i * puzzle->n + col];
		i++;
	}
	visible_top = count_visible(column, puzzle->n, 0);
	visible_bottom = count_visible(column, puzzle->n, 1);
	free(column);
	if (visible_top == puzzle->clues[col])
	{
		if (visible_bottom == puzzle->clues[puzzle->n + col])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	is_safe(t_puzzle *puzzle, int row, int col, int num)
{
	if (!(puzzle->row_masks[row] & (1 << num)))
	{
		if (!(puzzle->col_masks[col] & (1 << num)))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	valid_row_col(t_puzzle *puzzle, int row, int col, int num)
{
	int	valid_row;
	int	valid_col;

	puzzle->grid[row * puzzle->n + col] = num;
	puzzle->row_masks[row] |= (1 << num);
	puzzle->col_masks[col] |= (1 << num);
	if (col == puzzle->n - 1)
		valid_row = validate_row(puzzle, row);
	else
		valid_row = 1;
	if (row == puzzle->n - 1)
		valid_col = validate_column(puzzle, col);
	else
		valid_col = 1;
	return (valid_row && valid_col);
}
