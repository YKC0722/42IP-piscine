/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:12:19 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/21 23:29:05 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result = 0;
	int	i = 8;

	while (i--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}

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

int	main(void)
{
	unsigned char	octet = 38;

	printf("Original byte: ");
	print_bits(octet);

	unsigned char	reversed = reverse_bits(octet);

	printf("Reversed byte: ");
	print_bits(reversed);
	return(0);
}
