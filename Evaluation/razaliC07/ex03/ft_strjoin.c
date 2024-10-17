/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrazali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:56:51 by rrazali           #+#    #+#             */
/*   Updated: 2024/10/17 19:24:18 by rrazali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;
	int	str_len;
	int	sep_len;

	total_len = 0;
	sep_len = 0;
	while (sep[sep_len] != '\0')
	{
		sep_len++;
	}
	i = 0;
	while (i < size)
	{
		str_len = 0;
		while (strs[i][str_len] != '\0')
			str_len++;
		total_len += str_len + sep_len;
		i++;
	}
	return (total_len - sep_len);
}

void	join_strings(char *s, int size, char **strs, char *sep)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		if (i < size - 1)
			while (sep[j] != '\0')
				s[c++] = sep[j++];
		i++;
	}
	s[c] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*s;

	if (size == 0)
		return (malloc(1));
	total_len = get_total_length(size, strs, sep);
	s = (char *)malloc(sizeof(char) * (total_len + 1));
	if (s == NULL)
		return (NULL);
	join_strings(s, size, strs, sep);
	return (s);
}
/*
#include <stdio.h>

int main(void) {
    char *tab[4];
    tab[0] = "Hello";
    tab[1] = "world";
    tab[2] = "this";
    tab[3] = "is C!";
    char *result = ft_strjoin(4, tab, " ^^");
    if (result) {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}*/
