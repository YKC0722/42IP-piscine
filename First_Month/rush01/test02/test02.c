#include <unistd.h>
#include <stdlib.h>

// Function to print a single character using write
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Function to print a space
void ft_putspace(void)
{
    ft_putchar(' ');
}

// Function to print a newline
void ft_putnewline(void)
{
    ft_putchar('\n');
}

// Function to print the grid dynamically
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
            ft_putchar(c);
            if (j < N - 1)
                ft_putspace();
            j++;
        }
        ft_putnewline();
        i++;
    }
}

// Function to parse the input string into clues array and determine N
int parse_input(char *input, int **clues_ptr, int *N_ptr)
{
    int *clues = NULL;
    int count = 0, capacity = 16, i = 0;
    clues = malloc(capacity * sizeof(int));
    if (!clues)
        return 0;

    while (input[i] != '\0')
    {
        if (input[i] >= '1' && input[i] <= '9')
        {
            if (count >= capacity)
            {
                capacity *= 2;
                int *temp = malloc(capacity * sizeof(int));
                if (!temp)
                {
                    free(clues);
                    return 0;
                }
                int k = 0;
                while (k < count)
                {
                    temp[k] = clues[k];
                    k++;
                }
                free(clues);
                clues = temp;
            }
            clues[count++] = input[i] - '0';
        }
        else if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
            { free(clues); return 0; }
        i++;
    }

    if (count % 4 != 0)
    {
        free(clues);
        return 0;
    }

    int N = count / 4;
    if (N < 3 || N > 9)
    {
        free(clues);
        return 0;
    }

    // Allocate exact memory
    int *exact_clues = malloc(count * sizeof(int));
    if (!exact_clues)
    {
        free(clues);
        return 0;
    }
    int m = 0;
    while (m < count)
    {
        exact_clues[m] = clues[m];
        m++;
    }
    free(clues);
    *clues_ptr = exact_clues;
    *N_ptr = N;
    return 1;
}

// Function to count visible buildings from one direction
int count_visible(int *line, int N, int reverse)
{
    int max = 0, count = 0, i = 0;
    while (i < N)
    {
        int index = reverse ? (N - i - 1) : i;
        int height = line[index];
        if (height > max)
        {
            max = height;
            count++;
        }
        i++;
    }
    return count;
}

// Function to validate a specific row against its left and right clues
int validate_row(int **grid, int *clues, int N, int row)
{
    int left_clue = clues[2 * N + row];
    int right_clue = clues[3 * N + row];
    int visible_left = count_visible(grid[row], N, 0);
    int visible_right = count_visible(grid[row], N, 1);
    if (visible_left != left_clue || visible_right != right_clue)
        return 0;
    return 1;
}

// Function to validate a specific column against its top and bottom clues
int validate_column(int **grid, int *clues, int N, int col)
{
    int visible_top = 0, visible_bottom = 0, max_top = 0, max_bottom = 0;
    int i = 0;
    while (i < N)
    {
        int height_top = grid[i][col];
        if (height_top > max_top)
        {
            max_top = height_top;
            visible_top++;
        }
        int height_bottom = grid[N - i - 1][col];
        if (height_bottom > max_bottom)
        {
            max_bottom = height_bottom;
            visible_bottom++;
        }
        i++;
    }
    if (visible_top != clues[col] || visible_bottom != clues[N + col])
        return 0;
    return 1;
}

// Function to check if a number can be placed in the current row/column using bitmask
int is_safe(int row, int col, int num, int *row_masks, int *col_masks)
{
    if ((row_masks[row] & (1 << num)) || (col_masks[col] & (1 << num)))
        return 0;
    return 1;
}

// Recursive backtracking solver
int solve(int **grid, int *clues, int N, int row, int col, int *row_masks, int *col_masks)
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
            grid[row][col] = num;
            row_masks[row] |= (1 << num);
            col_masks[col] |= (1 << num);

            // If at end of row, validate row
            if (col == N -1 )
            {
                if (!validate_row(grid, clues, N, row))
                {
                    grid[row][col] = 0;
                    row_masks[row] &= ~(1 << num);
                    col_masks[col] &= ~(1 << num);
                    num++;
                    continue;
                }
            }

            // If at end of column, validate column
            if (row == N -1 )
            {
                if (!validate_column(grid, clues, N, col))
                {
                    grid[row][col] = 0;
                    row_masks[row] &= ~(1 << num);
                    col_masks[col] &= ~(1 << num);
                    num++;
                    continue;
                }
            }

            if (solve(grid, clues, N, row, col + 1, row_masks, col_masks))
                return 1;

            // Backtrack
            grid[row][col] = 0;
            row_masks[row] &= ~(1 << num);
            col_masks[col] &= ~(1 << num);
        }
        num++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    // Parse clues and determine N
    int *clues = NULL;
    int N = 4;
    if (!parse_input(argv[1], &clues, &N))
    {
        write(1, "Error\n", 6);
        return 1;
    }

    // Allocate grid dynamically
    int **grid = malloc(N * sizeof(int *));
    if (!grid)
    {
        write(1, "Error\n", 6);
        free(clues);
        return 1;
    }

    // Initialize grid with zeros
    int row = 0;
    while (row < N)
    {
        grid[row] = malloc(N * sizeof(int));
        if (!grid[row])
        {
            write(1, "Error\n", 6);
            // Free previously allocated rows
            int k = 0;
            while (k < row)
            {
                free(grid[k]);
                k++;
            }
            free(grid);
            free(clues);
            return 1;
        }

        int col = 0;
        while (col < N)
        {
            grid[row][col] = 0;
            col++;
        }
        row++;
    }

    // Allocate and initialize masks
    int *row_masks = malloc(N * sizeof(int));
    int *col_masks = malloc(N * sizeof(int));
    if (!row_masks || !col_masks)
    {
        write(1, "Error\n", 6);
        // Free grid
        row = 0;
        while (row < N)
        {
            free(grid[row]);
            row++;
        }
        free(grid);
        free(clues);
        if (row_masks) free(row_masks);
        if (col_masks) free(col_masks);
        return 1;
    }

    row = 0;
    while (row < N)
    {
        row_masks[row] = 0;
        col_masks[row] = 0;
        row++;
    }

    // Solve the puzzle
    if (solve(grid, clues, N, 0, 0, row_masks, col_masks))
        print_grid(grid, N);
    else
        write(1, "Error\n", 6);

    // Free allocated memory
    row = 0;
    while (row < N)
    {
        free(grid[row]);
        row++;
    }
    free(grid);
    free(clues);
    free(row_masks);
    free(col_masks);

    return 0;
}
