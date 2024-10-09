#include<unistd.h>

int	ft_str_is_printable(char *str)
{
	if (str[0] == '\0')
		return (1);
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
		{
			return 0;
		}
		str++;
	}
	return (1);
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
	char str[] = "ASDFGHJKL !@#$%^&*()_+";
	char result;

	ft_putstr(str);
	write(1, "\n", 1);
	if (ft_str_is_printable(str))
	{
		result = '1';
	} else {
		result = '0';
	}
	write(1, &result, 1);
	write(1, "\n", 1);

	char stra[] = "ASDFGHJKL;'\nzxcv bnm,./\tQWER";
        char resulta;

        ft_putstr(stra);
        write(1, "\n", 1);
        if (ft_str_is_printable(stra))
        {
                resulta = '1';
        } else {
                resulta = '0';
        }
        write(1, &resulta, 1);
        write(1, "\n", 1);

	char strb[] = "";
        char resultb;

        ft_putstr(strb);
        write(1, "\n", 1);
        if (ft_str_is_printable(strb))
        {
                resultb = '1';
        } else {
                resultb = '0';
        }
        write(1, &resultb, 1);
        write(1, "\n", 1);
	return (0);
}
