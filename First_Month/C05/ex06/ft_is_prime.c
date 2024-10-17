#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	printf("5 is prime? %d\n", ft_is_prime(5));
	printf("10 is prime? %d\n", ft_is_prime(10));
	printf("0 is prime? %d\n", ft_is_prime(0));
	return (0);
}*/
