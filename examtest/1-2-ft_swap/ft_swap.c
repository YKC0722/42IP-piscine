/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:34:19 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/20 12:57:39 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int	main(void)
{
	int	s = 20;
	int	y = 43;

	printf("before swap s = %d, y = %d\n", s, y);
	ft_swap(&s, &y);
	printf("after swap s = %d, y = %d\n", s, y);
	return (0);
}
