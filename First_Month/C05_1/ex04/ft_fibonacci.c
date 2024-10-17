/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:14:56 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:59 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	result;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}
/*
int	main(void)
{
	printf("nth6 = %d\n", ft_fibonacci(6));
	printf("nth0 = %d\n", ft_fibonacci(0));
	printf("nth2 = %d\n", ft_fibonacci(2));
	printf("nth15 = %d\n", ft_fibonacci(15));
	return (0);
}*/
