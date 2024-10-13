#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char character)
{
	write(1, &character, 1);
}

void	print_grid(int *grid, int N)
{
	int	i;
	int	j;
	char	character;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			character = grid[i * N + j] + '0';
			ft_putchar(character);
			if (j < N - 1)
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
