#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i <= nb)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int     main(void)
{
	printf("Sqrt of 9 = %d\n", ft_sqrt(9));
	printf("Sqrt of 144 = %d\n", ft_sqrt(144));
	printf("Sqrt of 110 = %d\n", ft_sqrt(110));
	return (0);
}*/
