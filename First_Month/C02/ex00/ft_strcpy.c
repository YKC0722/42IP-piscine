#include<unistd.h>

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;
	
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int	main(void)
{
	char	src[] = "How are you?";
	char	dest[] = "I'm Fine, Thank you!";

	ft_putstr(src);
	ft_strcpy(dest, src);
	ft_putstr(dest);
	write(1, "\n", 1);
	return (0);
}
