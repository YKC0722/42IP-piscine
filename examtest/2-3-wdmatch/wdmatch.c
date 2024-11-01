/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:05:03 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/11/01 16:36:06 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = 0;
	
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc ==3)
	{
		int	i = 0;
		int	j = 0;

		while (argv[1][i])
		{
			if (argv[2][j] == '\0')
			{
				write(1, "\n", 1);
				return (0);
			}
			if (argv[1][i] != argv[2][j])
				j++;
			else
			{
				i++;
				j++;
			}
		}
		ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
