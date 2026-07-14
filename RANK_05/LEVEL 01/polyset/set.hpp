/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:34:55 by fvizcaya          #+#    #+#             */
/*   Updated: 2026/06/27 18:39:17 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "given/searchable_bag.hpp"

class set
{
	private:
		searchable_bag &bag;
		
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		
		set& operator=(const set& other);
		
		void insert(int value);
		void insert(int *array, int size);
		void print() const;
		void clear();
		bool has(int value) const;
};