/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:14:19 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:20 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Factorial 5: %d\n", ft_recursive_factorial(5));
	printf("Factorial 0: %d\n", ft_recursive_factorial(0));
	printf("Factorial -5: %d\n", ft_recursive_factorial(-5));
	return (0);
}*/
