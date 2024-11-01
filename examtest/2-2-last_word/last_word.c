/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:53:10 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/21 19:54:15 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count = 0;
	while(str[count])
	{
		count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	n = ft_strlen(argv[1]);
	int	i = n - 1;
	int	last = 0;
	while(argv[1][i] == ' ')
	{
		last++;
		i--;
	}
	while (argv[1][i] != ' ')
	{
		last++;
		i--;
	}
	int	c = n - last;
	while (argv[1][c] != '\0')
	{
		if (argv[1][c] != ' ')
			write(1, &argv[1][c], 1);
		c++;
	}
	write(1, "\n", 1);
	return (0);
}
