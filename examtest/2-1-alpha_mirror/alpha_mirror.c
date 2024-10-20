/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:31:04 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/21 01:43:47 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	i = 0;
	char	letter;
	while (argv[1][i])
	{
		letter = argv[1][i];
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			letter = 219 - argv[1][i];
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			letter = 155 - argv[1][i];
		write(1, &letter, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
