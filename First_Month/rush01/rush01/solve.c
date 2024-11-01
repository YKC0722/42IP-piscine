/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:03:57 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 16:38:46 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	valid_row_col(t_puzzle *puzzle, int row, int col, int num);
int	is_safe(t_puzzle *puzzle, int row, int col, int num);

int	solve(t_puzzle *puzzle, int row, int col)
{
	int	num;

	if (row == puzzle->n)
		return (1);
	if (col == puzzle->n)
		return (solve(puzzle, row + 1, 0));
	num = 1;
	while (num <= puzzle->n)
	{
		if (is_safe(puzzle, row, col, num))
		{
			if (valid_row_col(puzzle, row, col, num))
				if (solve(puzzle, row, col + 1))
					return (1);
			puzzle->grid[row * puzzle->n + col] = 0;
			puzzle->row_masks[row] &= ~(1 << num);
			puzzle->col_masks[col] &= ~(1 << num);
		}
		num++;
	}
	return (0);
}
