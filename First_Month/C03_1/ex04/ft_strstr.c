/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:13:28 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/15 18:05:25 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*t;

	while (*str != '\0')
	{
		s = str;
		t = to_find;
		while (*s && *t && (*s == *t))
		{
			s++;
			t++;
		}
		if (*t == '\0')
		{
			return (str);
		}
		str++;
	}
	return (0);
}
/*
void ft_putstr(char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(1, "Error\n", 6);
        return 1;
    }

    char *haystack = argv[1];
    char *needle = argv[2];
    char *result = ft_strstr(haystack, needle);

    if (result) {
        write(1, "Substring found: ", 17);
        ft_putstr(result);
        write(1, "\n", 1);
    } else {
        write(1, "Error\n", 6);
    }
    return 0;
}*/
