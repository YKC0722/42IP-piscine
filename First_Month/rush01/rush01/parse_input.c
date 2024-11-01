/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:37:02 by akerk             #+#    #+#             */
/*   Updated: 2024/10/13 14:37:08 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	parse_input(char *input, int **clues_ptr, int *n_ptr)
{
	int	*clues;
	int	count;
	int	i;
	int	n;

	clues = malloc(36 * sizeof(int));
	if (clues == NULL)
		return (0);
	count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '1' && input[i] <= '9')
			clues[count++] = input[i] - '0';
		i++;
	}
	n = count / 4;
	if (n < 3 || n > 9)
	{
		free(clues);
		return (0);
	}
	*clues_ptr = clues;
	*n_ptr = n;
	return (1);
}
