#include <unistd.h>
#include <stdlib.h>

// Function to print a single character using write
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Function to print the grid dynamically
void print_grid(int **grid, int N)
{
    int i = 0;
    while (i < N)
    {
        int j = 0;
        while (j < N)
        {
            char c = grid[i][j] + '0'; // Convert number to character
            ft_putchar(c);
            if (j != N - 1)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

// Function to parse the input string into clues array
int parse_input(char *input, int **clues_ptr, int *N_ptr)
{
    int clues_capacity = 16; // Initial capacity, will adjust if needed
    int *clues = malloc(clues_capacity * sizeof(int));
    if (!clues)
        return 0; // Memory allocation failure

    int count = 0;
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] >= '1' && input[i] <= '9')
        {
            if (count >= clues_capacity)
            {
                // Increase capacity
                clues_capacity *= 2;
                int *temp = malloc(clues_capacity * sizeof(int));
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
            clues[count++] = input[i] - '0'; // Convert char to int
        }
        else if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
        {
            // Invalid character detected
            free(clues);
            return 0;
        }
        i++;
    }

    // Determine N
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

    // Allocate exact memory for clues
    int *clues_exact = malloc(count * sizeof(int));
    if (!clues_exact)
    {
        free(clues);
        return 0;
    }
    int m = 0;
    while (m < count)
    {
        clues_exact[m] = clues[m];
        m++;
    }
    free(clues);

    *clues_ptr = clues_exact;
    *N_ptr = N;
    return 1; // Success
}

// Function to count visible buildings from one direction
int count_visible(int *line, int N, int reverse)
{
    int max = 0, count = 0;
    int i = 0;
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
    // Left clue is at clues[2*N + row]
    // Right clue is at clues[3*N + row]
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
    // Create a temporary array for the column
    int *column = malloc(N * sizeof(int));
    if (!column)
        return 0; // Memory allocation failure

    int i = 0;
    while (i < N)
    {
        column[i] = grid[i][col];
        i++;
    }

    // Top clue is at clues[col]
    // Bottom clue is at clues[N + col]
    int top_clue = clues[col];
    int bottom_clue = clues[N + col];
    int visible_top = count_visible(column, N, 0);
    int visible_bottom = count_visible(column, N, 1);

    free(column);

    if (visible_top != top_clue || visible_bottom != bottom_clue)
        return 0;
    return 1;
}

// Function to check if a number can be placed in the current row/column
int is_safe(int **grid, int N, int row, int col, int num)
{
    int i = 0;
    while (i < N)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}

// Recursive backtracking solver
int solve(int **grid, int *clues, int N, int row, int col)
{
    if (row == N)
        return 1; // All rows filled, solution found

    if (col == N)
        return solve(grid, clues, N, row + 1, 0); // Move to next row

    int num = 1;
    while (num <= N)
    {
        if (is_safe(grid, N, row, col, num))
        {
            grid[row][col] = num; // Place number

            // If at the end of the row, validate the row
            if (col == N - 1)
            {
                if (!validate_row(grid, clues, N, row))
                {
                    grid[row][col] = 0; // Reset cell
                    num++;
                    continue; // Try next number
                }
            }

            // If at the end of the column, validate the column
            if (row == N - 1)
            {
                if (!validate_column(grid, clues, N, col))
                {
                    grid[row][col] = 0; // Reset cell
                    num++;
                    continue; // Try next number
                }
            }

            // Recurse to next cell
            if (solve(grid, clues, N, row, col + 1))
                return 1; // Solution found

            grid[row][col] = 0; // Backtrack
        }
        num++;
    }
    return 0; // No solution found in this path
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
    int N = 0;
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

        // Initialize grid with zeros
        int col = 0;
        while (col < N)
        {
            grid[row][col] = 0;
            col++;
        }
        row++;
    }

    // Solve the puzzle
    if (solve(grid, clues, N, 0, 0))
        print_grid(grid, N); // Print the solved grid
    else
        write(1, "Error\n", 6); // Print error if no solution exists

    // Free allocated memory
    row = 0;
    while (row < N)
    {
        free(grid[row]);
        row++;
    }
    free(grid);
    free(clues);

    return 0;
}
