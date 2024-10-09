/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:33:35 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 21:36:07 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (str[i] != '\0')
	{
		j = (str[i - 1] >= '0' && str[i - 1] <= '9');
		k = (str[i - 1] >= 'A' && str[i - 1] <= 'Z');
		l = (str[i - 1] >= 'a' && str[i - 1] <= 'z');
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (!(j || k || l))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_putstr(str);
	write(1, "\n", 1);
	ft_strcapitalize(str);
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}*/
