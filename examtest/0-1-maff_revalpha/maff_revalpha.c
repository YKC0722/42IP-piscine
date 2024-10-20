#include <unistd.h>

int	main(void)
{
	int	i = 'z';

	while ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
	{
		write(1, &i, 1);
		i -= 33;
		write(1, &i, 1);
		i += 31;
	}
	write(1, "\n", 1);
	return (0);
}
