#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
/*
#include <stdio.h>

int     main(void)
{
	printf("3^8: %d\n", ft_recursive_power(3, 8));
	printf("6^0: %d\n", ft_recursive_power(5, 0));
	printf("0^0: %d\n", ft_recursive_power(0, 0));
	printf("4^-4: %d\n", ft_recursive_power(2, -2));
	return 0;
}*/
