/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:34:52 by fvizcaya          #+#    #+#             */
/*   Updated: 2026/06/27 15:35:51 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &b) : bag(b)
{
	
}

set::set(const set &other) : bag(other.bag)
{
	
}

set::~set()
{
	
}

set &set::operator=(const set &other)
{
	(void)other;
	return (*this);
}

void set::insert(int value)
{
	if (!bag.has(value))
		bag.insert(value);
}

void set::insert(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		insert(array[i]);
		i++;
	}
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

bool set::has(int value) const
{
	return (bag.has(value));
}
