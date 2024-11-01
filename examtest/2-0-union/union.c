/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:44:02 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/25 18:44:09 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	union_strings(char *s1, char *s2)
{
	int	seen[256] = {0};
	int	i = 0;
	
	while (s1[i])
	{
		if (!seen[(unsigned char)s1[i]])
		{
			write(1, &s1[i], 1);
			seen[(unsigned char)s1[i]] = 1;
		}
		i++;
	}	
	i = 0;
	while (s2[i])
	{
		if (!seen[(unsigned char)s2[i]])
		{
			write(1, &s2[i], 1);
			seen[(unsigned char)s2[i]] = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		union_strings(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
