/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:11:13 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 16:29:30 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// puzzle.h
#ifndef PUZZLE_H
# define PUZZLE_H

typedef struct s_puzzle
{
	int	*grid;
	int	*clues;
	int	*row_masks;
	int	*col_masks;
	int	n;
}	t_puzzle;

void	initialize_masks(t_puzzle *puzzle);
int		validate_column(t_puzzle *puzzle, int col);
void	print_grid(t_puzzle *puzzle);
int		solve(t_puzzle *puzzle, int row, int col);
int		valid_row_col(t_puzzle *puzzle, int row, int col, int num);
int		is_safe(t_puzzle *puzzle, int row, int col, int num);
int		validate_row(t_puzzle *puzzle, int row);

#endif
