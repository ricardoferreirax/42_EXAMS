/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:34:49 by fvizcaya          #+#    #+#             */
/*   Updated: 2026/06/27 15:31:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "given/searchable_bag.hpp"
#include "given/tree_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag
{
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& other);
		~searchable_tree_bag();
		
		searchable_tree_bag& operator=(const searchable_tree_bag& other);

		bool has(int) const;
};