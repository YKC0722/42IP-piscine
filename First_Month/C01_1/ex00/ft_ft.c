/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:05:40 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 15:32:59 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*int	main(void)
{
	int	value;

	value = 0;
	ft_ft(&value);
	ft_putnbr(value);
	ft_putchar('\n');
	return (0);
}*/
