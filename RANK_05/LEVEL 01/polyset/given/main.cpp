/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 23:23:37 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/06/27 23:23:39 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 23:16:50 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/06/27 23:18:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>

int main()
{
	std::cout << "===== SEARCHABLE ARRAY BAG =====" << std::endl;

	searchable_array_bag ab;

	ab.insert(10);
	ab.insert(20);
	ab.insert(30);

	int arr1[] = {40, 50, 60};

	ab.insert(arr1, 3);

	ab.print();

	std::cout << "has(10): " << ab.has(10) << std::endl;
	std::cout << "has(99): " << ab.has(99) << std::endl;

	std::cout << "\n===== ARRAY COPY =====" << std::endl;

	searchable_array_bag ab2(ab);

	ab2.print();

	searchable_array_bag ab3;

	ab3 = ab2;
	ab3.print();

	std::cout << "\n===== SEARCHABLE TREE BAG =====" << std::endl;

	searchable_tree_bag tb;

	tb.insert(5);
	tb.insert(3);
	tb.insert(8);
	tb.insert(1);
	tb.insert(7);

	int arr2[] = {4, 9, 6};

	tb.insert(arr2, 3);

	tb.print();

	std::cout << "has(7): " << tb.has(7) << std::endl;
	std::cout << "has(42): " << tb.has(42) << std::endl;

	std::cout << "\n===== TREE COPY =====" << std::endl;

	searchable_tree_bag tb2(tb);

	tb2.print();

	searchable_tree_bag tb3;

	tb3 = tb2;
	tb3.print();

	std::cout << "\n===== SET USING ARRAY =====" << std::endl;

	searchable_array_bag sab;
	set sa(sab);

	sa.insert(1);
	sa.insert(2);
	sa.insert(3);
	sa.insert(2);
	sa.insert(1);
	sa.insert(5);

	sa.print();

	std::cout << "has(3): " << sa.has(3) << std::endl;
	std::cout << "has(8): " << sa.has(8) << std::endl;

	std::cout << "\n===== SET USING TREE =====" << std::endl;

	searchable_tree_bag stb;
	set st(stb);

	st.insert(10);
	st.insert(7);
	st.insert(12);
	st.insert(7);
	st.insert(10);
	st.insert(5);

	st.print();

	std::cout << "has(12): " << st.has(12) << std::endl;
	std::cout << "has(100): " << st.has(100) << std::endl;

	std::cout << "\n===== CLEAR =====" << std::endl;

	st.clear();
	st.print();

	sa.clear();
	sa.print();

	return 0;
}



/*
===== SEARCHABLE ARRAY BAG =====
10 20 30 40 50 60 
has(10): 1
has(99): 0

===== ARRAY COPY =====
10 20 30 40 50 60 
10 20 30 40 50 60 

===== SEARCHABLE TREE BAG =====
create node: 5
create node: 3
create node: 8
create node: 1
create node: 7
create node: 4
create node: 9
create node: 6
1 3 4 5 6 7 8 9 
has(7): 1
has(42): 0

===== TREE COPY =====
1 3 4 5 6 7 8 9 
1 3 4 5 6 7 8 9 

===== SET USING ARRAY =====
1 2 3 5 
has(3): 1
has(8): 0

===== SET USING TREE =====
create node: 10
create node: 7
create node: 12
create node: 5
5 7 10 12 
has(12): 1
has(100): 0

===== CLEAR =====
destroying value: 10
destroying value: 7
destroying value: 5
destroying value: 12


destroying value: 5
destroying value: 3
destroying value: 1
destroying value: 4
destroying value: 8
destroying value: 7
destroying value: 6
destroying value: 9
destroying value: 5
destroying value: 3
destroying value: 1
destroying value: 4
destroying value: 8
destroying value: 7
destroying value: 6
destroying value: 9
destroying value: 5
destroying value: 3
destroying value: 1
destroying value: 4
destroying value: 8
destroying value: 7
destroying value: 6
destroying value: 9


*/