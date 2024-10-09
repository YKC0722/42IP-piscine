/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:36 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 16:06:18 by cyeu-kan         ###   ########.fr       */
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

void	ft_div_mod(int a, int b, int *div, int*mod)
{
	*div = a / b;
	*mod = a - ((a / b) * b);
}

/*int	main(void)
{
	int	d;
	int	m;
	int	a;
	int	b;

	d = 0;
	m = 0;
	a = 123;
	b = 6;
	ft_div_mod(a, b, &d, &m);
	write(1, "a=", 2);
	ft_putnbr(a);
	write(1, "b=", 2);
	ft_putnbr(b);
	ft_putchar('\n');
	write(1, "div=", 4);
	ft_putnbr(d);
	write(1, "mod=", 4);
	ft_putnbr(m);
	ft_putchar('\n');
	return (0);
}*/
