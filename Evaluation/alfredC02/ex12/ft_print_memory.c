/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:34:29 by akerk             #+#    #+#             */
/*   Updated: 2024/10/17 17:53:30 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	xy_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long int	i;
	char		*cursor;
	char		*hex_symbols;

	cursor = (char *)addr;
	hex_symbols = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		xy_putchar(hex_symbols[cursor[i] / 16]);
		xy_putchar(hex_symbols[cursor[i] % 16]);
		if ((i + 1) % 2 == 0)
			xy_putchar(' ');
		i++;
	}
	return (addr);
}
