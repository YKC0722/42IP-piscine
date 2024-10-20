#include <unistd.h>

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if(*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

#include<stdio.h>
#include<stdlib.h>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n" ,6);
		return (0);
	}
	printf("%d\n", ft_atoi(argv[1]));
	printf("%d\n", atoi(argv[1]));
}
