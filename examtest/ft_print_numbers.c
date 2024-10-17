#include<unistd.h>

void ft_print_numbers(void)
{
	char	c;
	int i = 48;

	while (i >= 48 && i <= 57)
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
}

int main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}
