/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	int tab[256] = {};
	
	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			if (tab[(int)av[2][i]] == 0)
				tab[(int)av[2][i]] = 1;
			i++;
		}
		while (av[1][j] != '\0')
		{
			if (tab[(int)av[1][j]] == 1)
			{
				tab[(int)av[1][j]] = 2;
				write (1, &av[1][j], 1);
			}
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
