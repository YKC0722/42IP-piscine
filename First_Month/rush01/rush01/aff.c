/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:34:21 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 16:37:30 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "puzzle.h"

void	ft_putchar(char character)
{
	write(1, &character, 1);
}

void	print_grid(t_puzzle *puzzle)
{
	long int	i;
	long int	j;
	char		character;

	i = 0;
	while (i < puzzle->n)
	{
		j = 0;
		while (j < puzzle->n)
		{
			character = puzzle->grid[i * puzzle->n + j] + '0';
			ft_putchar(character);
			if (j < puzzle->n - 1)
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
