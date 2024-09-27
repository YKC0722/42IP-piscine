#include<unistd.h>

void ft_print_numbers(void)
{

       for(int i = '1'; i <= '9'; i++)
       {
	       write(1, &i,1);
       }

}

int main(void)
{
             ft_print_numbers();
}
