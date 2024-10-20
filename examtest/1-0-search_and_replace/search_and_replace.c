#include <unistd.h>

void    s_r(char *a, char *b, char *c)
{
    int i = 0;
    while(a[i])
    {
        if (a[i] == b[0])
        {
           write(1, &c[0], 1);
        }
        else
        {
            write(1, &a[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
}

 int main(int argc, char **argv)
 {
     if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
     {
         write(1, "\n", 1);
         return (0);
     }
     
     s_r(argv[1],argv[2],argv[3]);
     return(0);
 }
