/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:14:32 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:34 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("3^8: %d\n", ft_iterative_power(3, 8));
	printf("6^0: %d\n", ft_iterative_power(5, 0));
	printf("0^0: %d\n", ft_iterative_power(0, 0));
	printf("4^-4: %d\n", ft_iterative_power(2, -2)); 
	return 0;
}*/
