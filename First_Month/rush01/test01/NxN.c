#include <unistd.h>
#include <stdlib.h>

int **allocate_matrix(int N)
{
    int **matrix;
    int i;

    matrix = malloc(N * sizeof(int *));
    i = 0;
    while (i < N)
    {
        matrix[i] = malloc(N * sizeof(int));
        i++;
    }
    return matrix;
}

void free_matrix(int **matrix, int N)
{
    int i = 0;
    while (i < N)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

int find_grid_size(char *input)
{
    int i = 0, count = 0;
    while (input[i])
    {
        if (input[i] >= '1' && input[i] <= '9')
            count++;
        i++;
    }
    return count / 4; // Each row and column has two clues
}

int parse_clues(char *input, int *clues, int size)
{
    int i = 0, idx = 0;
    while (input[i] && idx < size * 4)
    {
        if (input[i] >= '1' && input[i] <= '9')
            clues[idx++] = input[i] - '0';
        i++;
    }
    return idx == size * 4;
}

void print_grid(int **grid, int N)
{
    int i = 0, j;
    char c;

    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < N - 1)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int count_visible(int *line, int size, int reverse)
{
    int max = 0, count = 0, i = 0;
    while (i < size)
    {
        int height = line[reverse ? size - i - 1 : i];
        if (height > max)
        {
            max = height;
            count++;
        }
        i++;
    }
    return count;
}

int validate_row(int **grid, int *clues, int size, int row)
{
    if (count_visible(grid[row], size, 0) != clues[size * 2 + row])
        return 0;
    if (count_visible(grid[row], size, 1) != clues[size * 3 + row])
        return 0;
    return 1;
}

int validate_column(int **grid, int *clues, int size, int col)
{
    int column[size];
    int i = 0;

    while (i < size)
    {
        column[i] = grid[i][col];
        i++;
    }
    if (count_visible(column, size, 0) != clues[col])
        return 0;
    if (count_visible(column, size, 1) != clues[size + col])
        return 0;
    return 1;
}

int is_safe(int **grid, int row, int col, int num, int size)
{
    int i = 0;

    while (i < size)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}

int solve(int **grid, int *clues, int size, int row, int col)
{
    int num = 1, i;

    if (row == size)
        return 1;
    if (col == size)
        return solve(grid, clues, size, row + 1, 0);

    while (num <= size)
    {
        if (is_safe(grid, row, col, num, size))
        {
            grid[row][col] = num;
            if (col == size - 1 && !validate_row(grid, clues, size, row))
                grid[row][col] = 0;
            else
            {
                i = 0;
                while (i < size && grid[i][col] != 0)
                    i++;
                if (i == size && !validate_column(grid, clues, size, col))
                    grid[row][col] = 0;
                else if (solve(grid, clues, size, row, col + 1))
                    return 1;
            }
        }
        num++;
    }
    grid[row][col] = 0;
    return 0;
}

int main(int argc, char **argv)
{
    int **grid, size, clues[36]; // Max clues for 9x9 grid

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    size = find_grid_size(argv[1]);
    if (size < 3 || size > 9 || !parse_clues(argv[1], clues, size))
    {
        write(1, "Error\n", 6);
        return 1;
    }

    grid = allocate_matrix(size);
    if (solve(grid, clues, size, 0, 0))
        print_grid(grid, size);
    else
        write(1, "Error\n", 6);

    free_matrix(grid, size);
    return 0;
}
