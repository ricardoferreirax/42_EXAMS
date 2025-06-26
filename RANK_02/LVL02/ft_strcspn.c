/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject); */

#include <stddef.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t count = 0;

	while (*s)
	{
		const char *p = reject;

		while (*p)
		{
			if (*p == *s)
				return count;
			p++;
		}
		count++;
		s++;
	}
	return count;
}
