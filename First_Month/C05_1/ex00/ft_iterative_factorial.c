/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:14:04 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:06 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Factorial 5: %d\n", ft_iterative_factorial(5));
	printf("Factorial 0: %d\n", ft_iterative_factorial(0));
	printf("Factorial -5: %d\n", ft_iterative_factorial(-5));
	return (0);
}*/
