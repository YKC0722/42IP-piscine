#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	initialize_comb(int comb[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = i;//initiate comb array{0,1,2,3 ...}
		i++;
	}
}

void	convert_char(int comb[], int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		ft_putchar(comb[i] + '0');//convert number to char
		i++;
	}
}

void	generate_comb(int comb[], int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0 && comb[i] == 10 - n + i)//check 7,8,9 true
		i--;
	if (i >= 0)
	{
		comb[i]++;
		j = i + 1;
		while (j < n)
		{
			comb[j] = comb[j - 1] + 1;
			j++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	initialize_comb(comb, n);
	while (1)
	{
		convert_char(comb, n);
		if (comb[0] == 10 - n)
			break;
		write(1, ", ", 2);
		generate_comb(comb, n);
	}
}

/*void    ft_print_combn(int n)
{
    int comb[10];
    int i, j;

    i = 0;
    while (i < n)
    {
        comb[i] = i;
        i++;
    }
    while (comb[0] <= 10 - n)
    {
        i = 0;
        while (i < n)
		ft_putchar(comb[i++] + '0');
	if (comb[0] < 10 - n)
		write(1, ", ", 2);
	i = n - 1;
        while (i >= 0 && comb[i] == 9 - (n - 1 - i))
            i--;
        if (i >= 0)
        {
		comb[i]++;
		j = i + 1;
		while (j < n)
		{
		comb[j] = comb[j - 1] + 1;
		j++;
		}
	}
	else
	{
		break;
	}
    }
}*/

int	main(void)
{
	ft_print_combn(6);
	ft_putchar('\n');
	return (0);
}
