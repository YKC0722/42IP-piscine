/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:44:35 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/25 18:57:49 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	first_appear(char *str, char c, int limit)
{
	int	i = 0;

	while (i < limit)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	union_strings(char *s1, char *s2)
{
	int	i = 0;
	
	while (s1[i])
	{
		if (first_appear(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		int	j = 0;
		int	found = 0;

		while (s1[j])
		{
			if (s1[j] == s2[i])
				found = 1;
			j++;
		}

		if (!found && first_appear(s2, s2[i], i))
			write(1, &s2[i], 1);
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
