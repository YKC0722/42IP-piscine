#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
		if (nb >= 10) {
		ft_putnbr(nb / 10);
		}
	ft_putchar((nb % 10) + '0');
}

int main(void){
	ft_putnbr(42);
        ft_putchar('\n');
	return 0;
}
