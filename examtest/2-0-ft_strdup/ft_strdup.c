/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:49:29 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/21 22:59:05 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	len = 0;
	char	*dup;

	while (src[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return NULL;
	int	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

#include <stdio.h>

int	main(void)
{
	char	*src = "hello world!";
	char	*dup = ft_strdup(src);

	if (dup)
	{
		printf("Original = %s\n", src);
		printf("Duplicate = %s\n", dup);
		free(dup);
	}
	return (0);
}
