/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

/*It checks if there are two arguments or not and if not, it writes a newline 
and returns 0. Then it loops through the string and checks if the character 
is in upper case. If it is, it writes an underscore and changes the character 
to lower case. It then writes the character to the output. Finally, it writes 
a newline and returns 0.*/

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	char c;

	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			c = av[1][i];
			if (c >= 'A' && c <= 'Z')
			{
				write(1, "_", 1);
				c += 32;
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
