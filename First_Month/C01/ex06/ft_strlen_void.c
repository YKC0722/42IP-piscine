#include<unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_putnbr(int n){
	if(n >= 10){
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

void ft_strlen(char *str){
	int i = 0;

	while(str[i] != '\0'){
		write(1, &str[i], 1);
		i++;
	}
	int r = i;
	ft_putchar('\n');
	ft_putnbr(r);
	ft_putchar('\n');
}

int main(void){
	ft_strlen("How are you?");
	return 0;
}
