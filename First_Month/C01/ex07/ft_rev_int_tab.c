#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putnbr(int n) {
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10){
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
}

void ft_putstr(char *str){
	int i = 0;
	while (str[i] != '\0'){
		write(1, &str[i], 1);
		i++;
	}
}

void ft_rev_int_tab(int *tab, int size) {
    int temp;
    int i = 0;
    int j = size - 1;

    while (i < j) {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;

        i++;
        j--;
    }
}

int main() {
    int array[] = {22, 1, 48, -4, 55};
    int size = sizeof(array) / sizeof(array[0]);

    ft_putstr("Before reversing:");
    for (int i = 0; i < size; i++) {
        ft_putnbr(array[i]);
            ft_putchar(' ');
    }

    ft_rev_int_tab(array, size);

    ft_putstr("\nAfter reversing:");
    for (int i = 0; i < size; i++) {
        ft_putnbr(array[i]);
            ft_putchar(' ');
    }
    ft_putchar('\n');
    return 0;
}

