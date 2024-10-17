/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:13:28 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/17 17:56:06 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[1] != '\0')
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}
/*
void ft_putstr(char *str)
{
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
    char *String = argv[1];
    char *find = argv[2];
    char *result = ft_strstr(String, find);

    if (result) {
        write(1, "Substring found: ", 17);
        ft_putstr(result);
        write(1, "\n", 1);
    } else {
        write(1, "Error\n", 6);
    }
    return 0;
}*/
