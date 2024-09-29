#include <unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_putnbr(int n) {
    if (n >= 10) {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
}

int ft_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char *string = "What is your name?";
    int l = ft_strlen(string);
    write(1, string, l);
    ft_putchar('\n');
    ft_putnbr(l);
    write(1, "\n", 1);
    
    return 0;
}
