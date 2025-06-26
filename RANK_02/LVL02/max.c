/*Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0. */

int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int max_value;

	if (len == 0)
		return (0);
	
	max_value = tab[0];
	while (i < len)
	{
		if (tab[i] > max_value)
			max_value = tab[i];
		i++;
	}
	return (max_value);
}
