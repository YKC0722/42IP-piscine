/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:19:58 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 17:28:41 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

/*int	main(void)
{
	int	array[] = {22, 1, 48, -4, 55};
	int	size = sizeof(array) / sizeof(array[0]);
	int	i;

	ft_putstr("Before reversing:");
	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		ft_putchar(' ');
		i++;
	}
	ft_rev_int_tab(array, size);
	ft_putstr("\nAfter reversing:");
	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}*/
