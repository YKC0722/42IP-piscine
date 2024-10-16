/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:57:25 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/16 18:11:57 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return (output * sign);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	str;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	str = ft_atoi(argv[1]);
	printf("%d\n", str);
	return (0);
}
*/
