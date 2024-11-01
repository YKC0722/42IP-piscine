/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:47:08 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/27 02:45:08 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if(*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);

	unsigned int	i = 0;
	int	max = tab[0];

	while(i < len)
	{
		if (tab[i] >= max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	unsigned int	i = 0;
	unsigned int	len = ft_atoi(argv[2]);
	int	m[len];
	const char *ptr = argv[1];

	if (argc == 3)
	{
		while (i < len)
		{
			m[i] = ft_atoi(ptr);
			while (*ptr != ' ' && *ptr != '\0')
				ptr++;
			while(*ptr == ' ')
				ptr++;
			i++;
		}
	}
	printf("%d", max(m,len));
	return (0);
}
