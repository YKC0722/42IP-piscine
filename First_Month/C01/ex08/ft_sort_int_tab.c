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

void ft_sort_int_tab(int *tab, int size) {
    int temp;
        for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++){
	int k = j + 1;
	if (tab[j] > tab[k]) {

	    temp = tab[j];
	    tab[j] = tab[k];
	    tab[k] = temp;
            }
        }
	}
}

int main() {
    int array[] = {2, 99, -4, 66, -23, 3, 55};
    int size = sizeof(array) / sizeof(array[0]);

    ft_putstr("Before reversing:");
    for (int i = 0; i < size; i++) {
        ft_putnbr(array[i]);
            ft_putchar(' ');
    }

    ft_sort_int_tab(array, size);

    ft_putstr("\nAfter reversing:");
    for (int i = 0; i < size; i++) {
        ft_putnbr(array[i]);
            ft_putchar(' ');
    }
    ft_putchar('\n');
    return 0;
}

