/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 22:52:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/06/24 23:06:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public:
		vect2(int x = 0, int y = 0);
		vect2(const vect2& other);
		~vect2();

		vect2& operator=(const vect2& other);

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
		vect2& operator+=(const vect2& other);
		vect2& operator-=(const vect2& other);
		
		vect2 operator*(int num) const;
		vect2& operator*=(int num);

		vect2 operator-() const;

		int& operator[](int index);
		int operator[](int index) const;

		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;
};

vect2 operator*(int num, const vect2& other);
std::ostream& operator<<(std::ostream& out, const vect2& other);

#endif
