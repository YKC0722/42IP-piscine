#include <unistd.h>

int	ft_strlen(char *str)
{
    int i = 0;
    
    while(str[i])
    {
        i++;
    }
    return(i);
}

#include <stdio.h>
int main(void)
{
    char *str = "hejhhjllo";
    
    printf("%d\n", ft_strlen(str));
}
