#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
		ft_putchar(comb[i] + '0');	
	}

	if(comb[0] == 10 - n){
	       break ;
	}
	        
	ft_putchar(',');
	ft_putchar(' ');
	i = n - 1;
	
	while(i>=0 && comb[i] == 9 - (n -1 -i)){
		i--;
	}

	if(i >=0){
		comb[i]++;
		for(j = i + 1; j < n; j++){
			comb[j] = comb[j - 1] + 1;
		}
	}
}

int	main(void)
{
	ft_print_combn(7);
	ft_putchar('\n');
	return (0);
}


