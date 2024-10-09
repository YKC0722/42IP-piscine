#include<unistd.h>

char	*ft_strncpy(char	*dest, char	*src, unsigned int	n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
		i++;
	write(1, str, i);
}

int	main(void)
{
	char	src[] = "Happy Halloween!";
	char	dest[] = "Treat or Trick!";
	int	n;

	n = 30;
	ft_putstr(src);
	ft_strncpy(dest, src, n);
	ft_putstr(dest);
	write(1, "\n", 1);

	return (0);
}
