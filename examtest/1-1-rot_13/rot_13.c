#include <unistd.h>

void    rot13(char *a)
{
    int i = 0;
    char letter;
    while(a[i])
    {
        letter = a[i];
        if (a[i] >= 'a' && a[i] <= 'm' || a[i] >= 'A' && a[i] <= 'M')
        letter += 13;
        if (a[i] >= 'N' && a[i] <= 'Z' || a[i] >= 'n' && a[i] <= 'z')
        letter -= 13;
        write(1, &letter, 1);
        i+=1;
    }
    write(1, "\n", 1);
}

 int main(int argc, char **argv)
 {
     if (argc != 2)
     {
         write(1, "\n", 1);
         return (0);
     }
     
     rot13(argv[1]);
     return(0);
 }
