/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:34:46 by fvizcaya          #+#    #+#             */
/*   Updated: 2026/06/27 15:33:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
	
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{
	
}

searchable_tree_bag::~searchable_tree_bag()
{
	
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return (*this);
}

bool searchable_tree_bag::has(int value) const
{
	node *cur = tree;
	while (cur)
	{
		if (value == cur->value)
			return (true);
		if (value < cur->value)
			cur = cur->l;
		else
			cur = cur->r;
	}
	return (false);
}
