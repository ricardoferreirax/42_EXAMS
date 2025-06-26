/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduza o comportamento da função strdup (man strdup).

Sua função deve ser declarada da seguinte forma:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *dest;
	int len;
	int i;

	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
