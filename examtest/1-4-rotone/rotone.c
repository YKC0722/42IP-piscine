/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyeu-kan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:28:41 by cyeu-kan          #+#    #+#             */
/*   Updated: 2024/10/20 13:34:10 by cyeu-kan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    rotone(char *a)
{
    int i = 0;
    char letter;
    while(a[i])
    {
        letter = a[i];
        if ((a[i] >= 'a' && a[i] <= 'y') || (a[i] >= 'A' && a[i] <= 'Y'))
        	letter += 1;
	if (a[i] == 'z' || a[i] == 'Z')
		letter -= 25;
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
     
     rotone(argv[1]);
     return(0);
}
