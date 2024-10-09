/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:12:08 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 15:19:49 by cyeu-kan         ###   ########.fr       */
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

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*int	main(void)
{
	int	value = 0;
	int	*value1 = &value;
	int	**value2 = &value1;
	int	***value3 = &value2;
	int	****value4 = &value3;
	int	*****value5 = &value4;
	int	******value6 = &value5;
	int	*******value7 = &value6;
	int	********value8 = &value7;

	ft_ultimate_ft(&value8);
	ft_putnbr(value);
	ft_putchar('\n');
	return (0);
}*/
