/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:26:23 by akerk             #+#    #+#             */
/*   Updated: 2024/10/17 17:47:48 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	temp;
	char	*cursor;
	char	*hex_symbols;

	hex_symbols = "0123456789abcdef";
	cursor = (char *)str;
	while (*cursor != '\0')
	{
		if (*cursor >= ' ' && *cursor <= '~')
			write(1, cursor, 1);
		else
		{
			ft_putchar('\\');
			temp = *cursor / 16;
			ft_putchar(hex_symbols[temp]);
			temp = *cursor % 16;
			ft_putchar(hex_symbols[temp]);
		}
		cursor++;
	}
}
