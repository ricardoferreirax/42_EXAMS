/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 22:52:22 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/06/28 14:33:08 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(int x, int y) : x(x), y(y)
{
}

vect2::vect2(const vect2& other) : x(other.x), y(other.y)
{
}

vect2::~vect2()
{
}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

vect2& vect2::operator++()
{
	++x;
	++y;
	return (*this);
}

vect2& vect2::operator--()
{
	--x;
	--y;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);

	++(*this);
	return (tmp);
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);

	--(*this);
	return (tmp);
}

vect2 vect2::operator+(const vect2& other) const
{
	return (vect2(x + other.x, y + other.y));
}

vect2 vect2::operator-(const vect2& other) const
{
	return (vect2(x - other.x, y - other.y));
}

vect2& vect2::operator+=(const vect2& other)
{
	x += other.x;
	y += other.y;
	return (*this);
}

vect2& vect2::operator-=(const vect2& other)
{
	x -= other.x;
	y -= other.y;
	return (*this);
}

vect2 vect2::operator*(int num) const
{
	return (vect2(x * num, y * num));
}

vect2& vect2::operator*=(int num)
{
	x *= num;
	y *= num;
	return (*this);
}

vect2 vect2::operator-() const
{
	return (vect2(-x, -y));
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	return (y);
}

int vect2::operator[](int index) const
{
	if (index == 0)
		return (x);
	return (y);
}

bool vect2::operator==(const vect2& other) const
{
	return (x == other.x && y == other.y);
}

bool vect2::operator!=(const vect2& other) const
{
	return (!(*this == other));
}

std::ostream& operator<<(std::ostream& out, const vect2& other)
{
	out << "{" << other[0] << ", " << other[1] << "}";
	return (out);
}

vect2 operator*(int num, const vect2& other)
{
	return (other * num);
}
