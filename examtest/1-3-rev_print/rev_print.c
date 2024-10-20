/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:01:39 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/20 13:20:43 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	i = ft_strlen(argv[1]) - 1;
	while (i >= 0)
	{
		write(1, &argv[1][i], 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
