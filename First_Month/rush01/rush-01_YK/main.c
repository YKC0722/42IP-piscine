#include <unistd.h>
#include <stdlib.h>

int	parse_input(char *input, int **clues_ptr, int *N_ptr);
void	print_grid(int *grid, int N);
int	solve(int *grid, int *clues, int N, int row, int col, int *row_masks, int *col_masks);

void	initialize_masks(int *row_masks, int *col_masks, int N)
{
	int	i;

	i = 0;
	while (i < N)
	{
		row_masks[i] = col_masks[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	N;
	int	*grid;
	int	*row_masks;
	int	*col_masks;

	if (argc != 2 || !parse_input(argv[1], &clues, &N))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = malloc(N * N * sizeof(int));
	row_masks = malloc(N * sizeof(int));
	col_masks = malloc(N * sizeof(int));
	initialize_masks(row_masks, col_masks, N);
	if (solve(grid, clues, N, 0, 0, row_masks, col_masks))
		print_grid(grid, N);
	else
		write(1, "Error\n", 6);

	free(grid);
	free(clues);
	free(row_masks);
	free(col_masks);
	return (0);
}
