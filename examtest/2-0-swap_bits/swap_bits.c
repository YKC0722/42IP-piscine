/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:18:53 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/23 10:36:52 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	int	i = 7;

	printf("Original: ");
	while (i >= 0)
	{
		printf("%d", (octet >> i) & 1);
		if (i == 4)
			printf(" ");
		i--;
	}
	unsigned char	swapped = (octet >> 4) | (octet << 4);
	printf("\nSwapped: ");
	i = 7;
	while (i >= 0)
	{
		printf("%d", (swapped >> i) & 1);
		if (i == 4)
			printf(" ");
		i--;
	}
	printf("\n");
	return (swapped);
}

int	main()
{
	unsigned char	num = 88;
	
	swap_bits(num);
	return(0);
}
