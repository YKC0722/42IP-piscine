/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:52:28 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 17:18:23 by cyeu-kan         ###   ########.fr       */
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
	if (n > 9)
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			k = j + 1;
			if (tab[j] > tab[k])
			{
				temp = tab[j];
				tab[j] = tab[k];
				tab[k] = temp;
			}
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	int	array[] = {2, 99, -4, 66, -23, 3, 55};
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
	ft_sort_int_tab(array, size);
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
