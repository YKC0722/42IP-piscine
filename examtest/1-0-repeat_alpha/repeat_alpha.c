#include <unistd.h>
#include <stdio.h>

void    repeat_alpha(char *str)
{
    char c;
    char t;
    int i = 0;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
           c = (str[i] - 96);
           while (c > 0)
           {
           write(1, &str[i], 1);
           c--;
           }
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            c = (str[i] - 64);
            while (c > 0)
            {
                write(1, &str[i], 1);
                c--;
            }
        }
        i++;
    }
    write(1, "\n", 1);
}
 int main(void)
 {
     char s[6] = "Z";
     
     repeat_alpha(s);
     return(0);
 }
