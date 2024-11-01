/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:36:44 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 16:33:36 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "puzzle.h"

void	print_grid(t_puzzle *puzzle);
int		parse_input(char *input, int **clues_ptr, int *N_ptr);
int		solve(t_puzzle *puzzle, int row, int col);

void	initialize_masks(t_puzzle *puzzle)
{
	int	i;

	i = 0;
	while (i < puzzle->n)
	{
		puzzle->row_masks[i] = 0;
		puzzle->col_masks[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			*clues;
	int			n;
	t_puzzle	puzzle;

	if (argc != 2 || !parse_input(argv[1], &clues, &n))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	puzzle.n = n;
	puzzle.grid = malloc(n * n * sizeof(int));
	puzzle.row_masks = malloc(n * sizeof(int));
	puzzle.col_masks = malloc(n * sizeof(int));
	puzzle.clues = clues;
	initialize_masks(&puzzle);
	if (solve(&puzzle, 0, 0))
		print_grid(&puzzle);
	else
		write(1, "Error\n", 6);
	free(puzzle.grid);
	free(puzzle.clues);
	free(puzzle.row_masks);
	free(puzzle.col_masks);
}
