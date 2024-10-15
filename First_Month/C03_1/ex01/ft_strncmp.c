/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:35:05 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/15 15:47:15 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

/*
void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	res;
	int	n;

	if (argc != 4)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	n = argv[3][0] - '0';

	res = ft_strncmp(argv[1], argv[2], n);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}*/
