/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:31:07 by akerk             #+#    #+#             */
/*   Updated: 2024/10/17 17:43:56 by akerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalnum(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	if (str >= 'A' && str <= 'Z')
		return (1);
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	capitalize_next = 1;
	while (str[i] != '\0')
	{
		if (isalnum(str[i]) == 1)
		{
			if (capitalize_next && str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			else if (!capitalize_next && str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
			capitalize_next = 0;
		}
		else
			capitalize_next = 1;
		i++;
	}
	return (str);
}
