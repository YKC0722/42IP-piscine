/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:29:05 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/20 11:44:02 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	printf("%s\n", ft_strcpy(argv[1], argv[2]));
	return (0);
}
