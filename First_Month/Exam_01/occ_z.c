#include<unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int occ_z(char *str)
{
	int i;
	int a;

	i=0;
	a=0;
	while (str[i] != '\0')
	{
		if(str[i] == 'Z')
		{
			a++;
		}
		i++;
	}
	return (a);
}

void ft_putnbr(int n)  // Helper function to print numbers
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);  // Recursively print digits
    }
    ft_putchar((n % 10) + '0');  // Print the current digit
}

int main(void)
{
	char str[] = "ZuxnklsdkjdXklZknaskjfbkjZajksbjkZuxxhszZ";
	int count;
	count = occ_z(str);
	ft_putnbr(count);
	ft_putchar('\n');
	return 0;
}
