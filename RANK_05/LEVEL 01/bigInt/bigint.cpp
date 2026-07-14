/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:54:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/07/14 10:24:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint(unsigned int n)
{
	std::stringstream ss;

	ss << n;
	str = ss.str();
}

void bigint::normalize()
{
	while (str.length() > 1 && str[0] == '0')
		str.erase(0, 1);
	if (str.empty())
		str = "0";
}

bigint::bigint(const std::string& s) : str(s)
{
	normalize();
}

bigint::bigint(const bigint& other) : str(other.str)
{
}

bigint::~bigint()
{
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		str = other.str;
	return (*this);
}

std::string bigint::getStr() const
{
	return (str);
}

bigint bigint::operator+(const bigint& other) const
{
	std::string res = "";
	int carry = 0;
	int i = str.size() - 1;
	int j = other.str.size() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;

		if (i >= 0)
			sum += str[i--] - '0';
		if (j >= 0)
			sum += other.str[j--] - '0';
		carry = sum / 10;
		res = char((sum % 10) + '0') + res;
	}
	return (bigint(res));
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

bigint& bigint::operator++()
{
	*this += bigint(1);
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);

	++(*this);
	return (tmp);
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint tmp(*this);

	tmp <<= n;
	return (tmp);
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint tmp(*this);

	tmp >>= n;
	return (tmp);
}

bigint& bigint::operator<<=(unsigned int n)
{
	if (str != "0")
		str.append(n, '0');
	return (*this);
}

bigint& bigint::operator>>=(unsigned int n)
{
	if (n >= str.length())
		str = "0";
	else
		str.erase(str.length() - n);
	return (*this);
}

bigint& bigint::operator<<=(const bigint& other)
{
	unsigned int n = 0;

	for (size_t i = 0; i < other.str.length(); i++)
		n = n * 10 + (other.str[i] - '0');
	return (*this <<= n);
}

bigint& bigint::operator>>=(const bigint& other)
{
	unsigned int n = 0;

	for (size_t i = 0; i < other.str.length(); i++)
	{
		n = n * 10 + (other.str[i] - '0');
		if (n >= str.length())
		{
			str = "0";
			return (*this);
		}
	}
	return (*this >>= n);
}

bigint bigint::operator<<(const bigint& other) const
{
	bigint tmp(*this);

	tmp <<= other;
	return (tmp);
}

bigint bigint::operator>>(const bigint& other) const
{
	bigint tmp(*this);

	tmp >>= other;
	return (tmp);
}

bool bigint::operator==(const bigint& other) const
{
	return (str == other.str);
}

bool bigint::operator!=(const bigint& other) const
{
	return (!(*this == other));
}

bool bigint::operator<(const bigint& other) const
{
	if (str.length() != other.str.length())
		return (str.length() < other.str.length());
	return (str < other.str);
}

bool bigint::operator>(const bigint& other) const
{
	return (other < *this);
}

bool bigint::operator<=(const bigint& other) const
{
	return (!(*this > other));
}

bool bigint::operator>=(const bigint& other) const
{
	return (!(*this < other));
}

std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return (output);
}
