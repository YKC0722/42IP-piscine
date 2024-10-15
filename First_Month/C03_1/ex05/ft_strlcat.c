/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:53:56 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/15 19:22:04 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
	{
		dest_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (i < src_len && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
void ft_putnbr(unsigned int n) {
    if (n >= 10) {
        ft_putnbr(n / 10);
    }
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        write(1, "Error\n", 6);
        return (0);
    }

    char dest[50];
    unsigned int size = sizeof(dest);
    unsigned int total_length;
    unsigned int i = 0;
    while (argv[1][i] != '\0' && i < size - 1) {
        dest[i] = argv[1][i];
        i++;
    }
    dest[i] = '\0';

    char *src = argv[2];
    total_length = ft_strlcat(dest, src, size);

    write(1, dest, total_length);
    write(1, "\n", 1);
    write(1, "Total length: ", 14);
    ft_putnbr(total_length);
    write(1, "\n", 1);

    return 0;
}*/
