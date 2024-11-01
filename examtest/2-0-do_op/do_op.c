/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:03:07 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/21 10:32:04 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return (0);
	}
	char	op = argv[2][0];
	int	result;

	if (op == '+')
		result = atoi(argv[1]) + atoi(argv[3]);
	else if (op == '-')
		result = atoi(argv[1]) - atoi(argv[3]);
	else if (op == '*')
		result = atoi(argv[1]) * atoi(argv[3]);
	else if (op == '/')
		result = atoi(argv[1]) / atoi(argv[3]);
	else if (op == '%')
		result = atoi(argv[1]) % atoi(argv[3]);
	else
	{
		printf("\n");
		return (0);
	}

	printf("%d\n", result);
	return (0);
}
