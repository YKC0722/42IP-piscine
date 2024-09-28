#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_print_combn(int n) {
    int comb[n];  // Array to store current combination
    int i;

    // Initialize the first combination (0, 1, 2, ..., n-1)
    for (i = 0; i < n; i++) {
        comb[i] = i;
    }

    while (comb[0] <= 10 - n) {
        // Print the current combination
        for (i = 0; i < n; i++) {
            ft_putchar(comb[i] + '0');
        }

        // Check if it's the last combination
        if (comb[0] != 10 - n) {
            ft_putchar(',');
            ft_putchar(' ');
        }

        // Update the combination to the next one
        i = n - 1;
        while (i >= 0 && comb[i] == 9 - (n - 1 - i)) {
            i--;  // Move to the previous digit
        }

        if (i >= 0) {
            comb[i]++;
            for (int j = i + 1; j < n; j++) {
                comb[j] = comb[j - 1] + 1;
            }
        } else {
            break;  // Exit if no more valid combinations
        }
    }
}

int main(void) {
	{    ft_print_combn(6);  // Example: Print all combinations for n = 5
	}
	ft_putchar('\n');
    return 0;
}

