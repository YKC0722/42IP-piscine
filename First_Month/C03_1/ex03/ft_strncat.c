/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:35:05 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/15 17:06:18 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (nb && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
		nb--;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
    int	n = 0;
    if (argc != 4)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    int total_length = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1;

    char dest[total_length];

    n = n * 10 + (argv[3][0] - '0');
    dest[0] = '\0';

    ft_strncat(dest, argv[1],ft_strlen(argv[1]));
    ft_strncat(dest, argv[2], n);
    ft_putstr(dest);
    write(1, "\n", 1);
    return (0);
}*/