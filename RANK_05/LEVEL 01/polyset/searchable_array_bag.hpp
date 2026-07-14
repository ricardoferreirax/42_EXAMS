/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:34:43 by fvizcaya          #+#    #+#             */
/*   Updated: 2026/06/27 15:27:23 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "given/searchable_bag.hpp"
#include "given/array_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& other);
		~searchable_array_bag();
		
		searchable_array_bag& operator=(const searchable_array_bag& other);
		
		bool has(int) const;
};