#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_grid(int *grid, int N)
{
    int i = 0, j;
    char c;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            c = grid[i * N + j] + '0';
            ft_putchar(c);
            if (j < N - 1)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int count_visible(int *line, int N, int reverse)
{
    int max = 0, count = 0, i = 0;
    while (i < N)
    {
        int index = reverse ? (N - i - 1) : i;
        if (line[index] > max)
        {
            max = line[index];
            count++;
        }
        i++;
    }
    return count;
}

int validate_row(int *grid, int *clues, int N, int row)
{
    int left_clue = clues[2 * N + row];
    int right_clue = clues[3 * N + row];
    int visible_left = count_visible(&grid[row * N], N, 0);
    int visible_right = count_visible(&grid[row * N], N, 1);
    return (visible_left == left_clue && visible_right == right_clue);
}

int validate_column(int *grid, int *clues, int N, int col)
{
    int visible_top = 0, visible_bottom = 0, max_top = 0, max_bottom = 0;
    int i = 0;
    while (i < N)
    {
        int height_top = grid[i * N + col];
        if (height_top > max_top)
        {
            max_top = height_top;
            visible_top++;
        }
        int height_bottom = grid[(N - i - 1) * N + col];
        if (height_bottom > max_bottom)
        {
            max_bottom = height_bottom;
            visible_bottom++;
        }
        i++;
    }
    return (visible_top == clues[col] && visible_bottom == clues[N + col]);
}

int is_safe(int row, int col, int num, int *row_masks, int *col_masks)
{
    return !(row_masks[row] & (1 << num)) && !(col_masks[col] & (1 << num));
}

int solve(int *grid, int *clues, int N, int row, int col, int *row_masks, int *col_masks)
{
    if (row == N)
        return 1;

    if (col == N)
        return solve(grid, clues, N, row + 1, 0, row_masks, col_masks);

    int num = 1;
    while (num <= N)
    {
        if (is_safe(row, col, num, row_masks, col_masks))
        {
            grid[row * N + col] = num;
            row_masks[row] |= (1 << num);
            col_masks[col] |= (1 << num);

            int valid_row = (col == N - 1) ? validate_row(grid, clues, N, row) : 1;
            int valid_col = (row == N - 1) ? validate_column(grid, clues, N, col) : 1;

            if (valid_row && valid_col)
                if (solve(grid, clues, N, row, col + 1, row_masks, col_masks))
                    return 1;

            grid[row * N + col] = 0;
            row_masks[row] &= ~(1 << num);
            col_masks[col] &= ~(1 << num);
        }
        num++;
    }
    return 0;
}

int parse_input(char *input, int **clues_ptr, int *N_ptr)
{
    int *clues = malloc(32 * sizeof(int));
    int count = 0, i = 0;

    while (input[i] != '\0')
    {
        if (input[i] >= '1' && input[i] <= '9')
            clues[count++] = input[i] - '0';
        i++;
    }

    int N = count / 4;
    if (N < 4 || N > 9)
    {
        free(clues);
        return 0;
    }

    *clues_ptr = clues;
    *N_ptr = N;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    int *clues, N;
    if (!parse_input(argv[1], &clues, &N))
    {
        write(1, "Error\n", 6);
        return 1;
    }

    int *grid = malloc(N * N * sizeof(int));
    int *row_masks = malloc(N * sizeof(int));
    int *col_masks = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        row_masks[i] = col_masks[i] = 0;

    if (solve(grid, clues, N, 0, 0, row_masks, col_masks))
        print_grid(grid, N);
    else
        write(1, "Error\n", 6);

    free(grid);
    free(clues);
    free(row_masks);
    free(col_masks);
    return 0;
}
