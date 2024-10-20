/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yk_laptop <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:32:05 by yk_laptop         #+#    #+#             */
/*   Updated: 2024/10/20 10:32:42 by yk_laptop        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ulstr(char *a)
{
    int i = 0;
    while(a[i])
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
		char upper = a[i] - 32;
           write(1, &upper, 1);
        }
        else if (a[i] >= 'A' && a[i] <= 'Z')
        {
		char lower = a[i] + 32;
            write(1, &lower, 1);
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
     if (argc != 2)
     {
         write(1, "\n", 1);
         return (0);
     }
     
     ulstr(argv[1]);
     return(0);
 }
