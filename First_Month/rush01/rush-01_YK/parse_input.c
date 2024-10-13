#include <unistd.h>
#include <stdlib.h>

int	parse_input(char *input, int **clues_ptr, int *N_ptr)
{
	int	*clues;
	int	count;
	int	i;
	int	N;

	clues = malloc(32 * sizeof(int));
	if (clues == NULL)
		return (0);
	count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '1' && input[i] <= '9')
			clues[count++] = input[i] - '0';
		i++;
	}
	N = count / 4;
	if (N < 3 || N > 9)
	{
		free(clues);
		return (0);
	}
	*clues_ptr = clues;
	*N_ptr = N;
	return (1);
}
