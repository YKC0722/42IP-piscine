/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:24:28 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/09 19:25:19 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_str_is_numeric(char *str)
{
	if (str[0] == '\0')
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return (0);
		}
		str++;
	}
	return (1);
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
	char str[] = "19570831";
	char result;

	ft_putstr(str);
	write(1, "\n", 1);
	if (ft_str_is_numeric(str))
	{
		result = '1';
	} else {
		result = '0';
	}
	write(1, &result, 1);
	write(1, "\n", 1);

	char stra[] = "13579a24680b";
        char resulta;

        ft_putstr(stra);
        write(1, "\n", 1);
        if (ft_str_is_numeric(stra))
        {
                resulta = '1';
        } else {
                resulta = '0';
        }
        write(1, &resulta, 1);
        write(1, "\n", 1);

	char strb[] = "";
        char resultb;

        ft_putstr(strb);
        write(1, "\n", 1);
        if (ft_str_is_numeric(strb))
        {
                resultb = '1';
        } else {
                resultb = '0';
        }
        write(1, &resultb, 1);
        write(1, "\n", 1);
	return (0);
}*/
