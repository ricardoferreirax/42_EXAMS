/*
Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}*/

#include "list.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		swap;
	int		sorted;

	if (!lst)
		return (NULL);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = lst;
		while (tmp->next)
		{
			if (!cmp(tmp->data, tmp->next->data))
			{
				swap = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = swap;
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}
