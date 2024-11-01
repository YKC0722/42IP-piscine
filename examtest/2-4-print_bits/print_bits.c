/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:52:34 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/22 22:15:03 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	int	bits;

	while (i >= 0)
	{
		bits = ((octet >> i) & 1) + '0';
		write(1, &bits, 1);
		if (i == 4)
			write(1, " ", 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	int	i = 0;
	int	atoi = 0;
	while (argv[1][i])
	{
		atoi = atoi * 10 + (argv[1][i] - '0');
		i++;
	}

	print_bits(atoi);
	write(1, "\n", 1);
	return (0);
}
