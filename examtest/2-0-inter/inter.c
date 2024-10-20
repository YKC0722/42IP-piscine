#include <unistd.h>

void    inter(char *a, char *b)
{
    int i = 0;
    int j = 0;
    int count;
    char letter;
    while(a[i])
    {
        if (a[i] == b[j])
        {
            write(1, &a[i], 1);
	    i++;
	    j = 0;
        }
        else
        j++;
    }
    write(1, "\n", 1);
}

 int main(int argc, char **argv)
 {
     if (argc != 3)
     {
         write(1, "\n", 1);
         return (0);
     }

     inter(argv[1],argv[2]);
     return(0);
 }
