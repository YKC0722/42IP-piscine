/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrazali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:50:06 by rrazali           #+#    #+#             */
/*   Updated: 2024/10/17 19:26:56 by rrazali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{	
	int	*dest;
	int	range_size;
	int	i;

	i = 0;
	range_size = max - min;
	if (min >= max)
	{
		return (NULL);
	}
	dest = (int *)malloc(sizeof(int) * range_size);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (min < max)
	{
		dest[i++] = min++;
	}
	return (dest);
}
/*
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    // Handle negative numbers
    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    // Convert string to integer
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int	main(int argc, char **argv)
{
	int	*new_str;
	int	i;
	int	min;
	int	max;
	int	range;

	min = 0;
	max = 0;
	i=0;

	if (argc != 3)
	{
		printf ("usage: ./a.out <min> <max>\n");
		return (1);
	}
	
	min = ft_atoi(argv[1]);
	max = ft_atoi(argv[2]);
	range = max - min;

	printf("min = %d, max =%d\n",min,max);
	new_str = ft_range(min, max);

	if (new_str == NULL)
	{
		printf ("Invalid range\n");
		return (1);
	}

	while(i < range)
	{
		printf("%d\n",new_str[i]);
		i++;
	}

	free(new_str);
	return (0);

}*/
