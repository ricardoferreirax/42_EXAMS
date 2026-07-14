/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:49:16 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/21 17:44:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$*/

#include <stdio.h>
#include <stdlib.h>

void ft_swap(char *c, char *d)
{
    char temp = *c;
    *c = *d;
    *d = temp;
}

void ft_sort(char *str)
{
    int i = 0;
    int j = 0;

    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if (str[i] > str[j])
                ft_swap(str + j, str + i);
            j++;
        }
        i++;
    }
}

void    permutations (char *str, int pos)
{
    int i;

    if (!str[pos])
        puts(str);
    i = pos;
    while(str[i])
    {
        ft_sort(str + pos);
        ft_swap(str + i, str + pos);
        permutations(str, pos + 1);
        ft_swap(str + i, str + pos);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
        return (1);
    permutations(argv[1], 0);
}