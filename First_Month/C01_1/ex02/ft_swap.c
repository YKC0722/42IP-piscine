/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:20:56 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 15:31:40 by cyeu-kan         ###   ########.fr       */
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

void	ft_swap(int *a, int *b)
{
	int	value;

	value = *a;
	*a = *b;
	*b = value;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 96;
	write(1, "Beforeswap a=", 13);
	ft_putnbr(a);
	write(1, " b=", 3);
	ft_putnbr(b);
	ft_putchar('\n');
	ft_swap(&a, &b);
	write(1, "Afterswap a=", 13);
	ft_putnbr(a);
	write(1, " b=", 3);
	ft_putnbr(b);
	ft_putchar('\n');
	return (0);
}*/
