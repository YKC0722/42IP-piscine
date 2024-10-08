#include<unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;

		}
		i++;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int	main(void)
{
	char str[] = "Today Is My Birthday!";

	ft_putstr(str);
	write(1, "\n", 1);
	ft_strlowcase(str);
	ft_putstr(str);
        write(1, "\n", 1);
	return (0);
}
