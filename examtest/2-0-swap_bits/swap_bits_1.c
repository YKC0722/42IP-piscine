/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:38:18 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/23 10:41:31 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	while (i >= 0)
	{
		printf("%d", (octet >> i) & 1);
		if (i == 4)
			printf(" ");
		i--;
	}
	printf("\n");
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4) | (octet << 4);
}

int	main()
{
	unsigned char num = 38;

	printf("Original: ");
	print_bits(num);

	unsigned char swapped = swap_bits(num);

	printf("Swapped:  ");
	print_bits(swapped);
	return 0;
}

