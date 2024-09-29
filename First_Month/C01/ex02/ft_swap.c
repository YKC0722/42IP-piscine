#include<unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_putnbr(int n){
	if (n < 0){
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10){
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

void ft_swap(int *a, int *b){
	int value = *a;
	*a = *b;
	*b = value;
}

int main(void){
	int a = 42;
	int b = 96;

	write(1, "Beforeswap a=", 13);
	ft_putnbr(a);
	write(1, " b=", 3);
	ft_putnbr(b);
	ft_putchar('\n');

	ft_swap(&a, &b);

	write(1, "Afterswap a=", 13);
        ft_putnbr(a);                                                                                                          write(1, " b=", 3);
	ft_putnbr(b);
	ft_putchar('\n');
	return 0;
}
