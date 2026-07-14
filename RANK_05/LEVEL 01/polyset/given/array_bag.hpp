/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:22:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/06/27 15:22:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class array_bag : virtual public bag
{
 protected:
	int *data;
	int size;

 public:
	array_bag();
	array_bag(const array_bag &);
	array_bag &operator=(const array_bag &other);
	~array_bag();

	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
};