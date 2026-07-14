/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:48:15 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/06 16:16:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Assignment name: rip
Expected files: *.c *.h
Allowed functions: puts, write
--------------------------------------------------------------------------------
Write a program that will take as argument a string containing only parenthesis.
If parenthesis are unbalanced (for example "())") your program shall remove the
minimum number of parenthesis for the expression to be balanced.
By removing we mean replacing by spaces.
You will print all the solutions (can be more than one).
The order of the solutions is not important.
For example this should work:
(For readability reasons the '_' means space and the spaces are for readability only.)
$> ./rip '( ( )' | cat -e
_ ( ) $
( _ ) $
$> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
( ( ( ) ( ) ( ) ) ( ) ) $
$> ./rip '( ) ( ) ) ( )' | cat -e
( ) ( ) _ ( ) $
( ) ( _ ) ( ) $
( _ ( ) ) ( ) $
$> ./rip '( ( ) ( ( ) (' | cat -e
( ( ) _ _ ) _ $
( _ ) ( _ ) _ $
( _ ) _ ( ) _ $
_ ( ) ( _ ) _ $
_ ( ) _ ( ) _ $
 */

 #include <stdio.h>
 #include <string.h>
 
int difference(char *str)
{
    int i = 0;
    int open = 0;
    int close = 0;

    while(str[i])
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
        i++;
    }
    return (open + close);
}

int   is_valid(char *str)
{
    int i = 0;
    int balance = 0;

    while(str[i])
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
        {
            if (balance == 0)
                return (0);
            balance--;
        }
        i++;
    }
    return (balance == 0);
}

void    rip(char *str, int must_fix, int fixed, int position)
{
    int i = position;

    if (is_valid(str) && must_fix == fixed)
    {
        puts(str);
        return ;
    }
    while(str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            char temp = str[i];
            str[i] = ' ';
            rip(str, must_fix, fixed + 1, i + 1);
            str[i] = temp;
        }
        i++;
    }
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int   main(int argc, char **argv)
{
    int must_fix;
    char str[1000];

    if (argc != 2 || !argv[1][0])
        return (1);
    ft_strcpy(str, argv[1]);
    must_fix = difference(str);
    rip(str, must_fix, 0, 0);
}
