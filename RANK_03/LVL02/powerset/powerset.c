/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:51:02 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/06 11:00:56 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
display all subsets of a set whose sum of its elements is equal to the first argument.
The numbers of the set are from the second argument to the last.
A subset must not be displayed a second time.

exemple1)
./a.out 5 2 3 | cat -e
2 3$

ex2)
./a.out 12 5 7 4 3 2 | cat -e
5 7$
5 4 3$
7 3 2$
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_subset(int *arr, int size, int target)
{
	(void)target;
    int i = 0;

	while (i < size)
	{
		printf("%d", arr[i]);
		if (i + 1 != size)
			printf(" ");
        i++;
	}
	printf("\n");
}

void ft_power_set(int *nums, int *arr, int target, int pos, int nums_size, int size, int sum)
{
    int i = pos;
	if (sum == target)
		print_subset(arr,size, target);
	while (i < nums_size)
	{
		arr[size] = nums[i];
		sum += arr[size]; 
		size++;
		ft_power_set(nums,arr,target,i + 1, nums_size, size, sum);
		size--;
		sum -= arr[size]; 
        i++;
	}
}

int main(int argc, char **argv)
{
	if (argc <= 2)
		return (0);
	int nums[argc - 2];
	int arr[argc - 2];
	int i = 2;
	while (argv[i])
	{
		nums[i - 2] = atoi(argv[i]);
		i++;
	}
	ft_power_set(nums, arr, atoi(argv[1]), 0, argc - 2, 0, 0);
}
