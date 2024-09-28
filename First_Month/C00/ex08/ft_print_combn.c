#include<unistd.h>

void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_print_combn(int n){
	if (n == 2){
	for(int i = 0; i <= 8; i++){
                for(int j = i+1; j <= 9; j++){
		ft_putchar(i + '0');
		ft_putchar(j + '0');
                   if(!(i==8 && j==9)){
			   ft_putchar(',');
                           ft_putchar(' ');
	}}}} else if (n==3){
		for(int i = 0; i <= 7; i++){
		for(int j = i+1; j <= 8; j++){
			for(int k = j+1; k <= 9; k++){
				ft_putchar(i + '0');
				ft_putchar(j + '0');
				ft_putchar(k + '0');
				if(!(i==7 && j==8 && k==9)){
					ft_putchar(',');
					ft_putchar(' ');		
}}}}}
else if (n==4){
	for(int i = 0; i <= 6; i++){
                for(int j = i+1; j <= 7; j++){
                        for(int k = j+1; k <= 8; k++){
				for(int l = k+1; l<=9; l++){

                                ft_putchar(i + '0');
                                ft_putchar(j + '0');
                                ft_putchar(k + '0');
				ft_putchar(l + '0');

                                if(!(i==6 && j==7 && k==8 && l==9)){
                                        ft_putchar(',');
                                        ft_putchar(' ');
}}}}}}}

int main(void){
	ft_print_combn(4);
	ft_putchar('\n');
	return 0;
}

