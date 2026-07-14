/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:15:37 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/12/21 18:22:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : n_queens
Expected files   : *.c *.h
Allowed functions: atoi, printf, write, malloc, calloc, realloc, free
--------------------------------------------------------------------------------

Write a program that prints all the solutions to the N Queens
problem for a given N received as argument.

The N Queens problem is a classic puzzle that involves placing N queens on an NxN chessboard
in such a way that no queens threaten each other. Please refer to the files attached to this subject.

We will not test with negative values.
The order of the solutions is not important.

You will display the solutions under the following format:
<p1> <p2> <p3> <p4> \n
where pn are the line index of the queen in each column starting from 0.
For instance, if you want to place your queens on the chessboard like this:

0: . Q . .
1: . . . Q
2: Q . . .
3: . . Q .

you must provide the following output:
1 3 0 2

For example, this should work:

$> ./n_queens 2 | cat -e
$>
$> ./n_queens 4 | cat -e
1 3 0 2$
2 0 3 1$
$> ./n_queens 7 | cat -e
0 2 4 6 1 3 5$
0 3 6 2 5 1 4$
0 4 1 5 2 6 3$
0 5 3 1 6 4 2$
1 3 5 0 2 4 6$
1 4 0 3 6 2 5$
1 4 2 0 6 3 5$
...
*/

#include <stdio.h>
#include <stdlib.h>

void   print_board(int *board, int n)
{
    int i = 0;
    
    while(i < n)
    {
        printf("%d", board[i]);
        if (i + 1 < n)
            printf(" ");
        i++;
    }
    printf("\n");
}

int     is_valid(int *board, int col, int row)
{
    int i = 0;

    while(i < row)
    {
        if (board[i] == col)
            return (0);
        if (board[i] + i == col + row)
            return (0);
        if (board[i] - i == col - row)
            return (0);
        i++;
    }
    return (1);
}

void    queens(int *board, int row, int n)
{
    int col = 0;
    
    if (row == n)
    {
        print_board(board, n);
        return ;
    }
    while(col < n)
    {
        if (is_valid(board, col, row))
        {
            board[row] = col;
            queens(board, row + 1, n);
        }
        col++;
    }
}

int main (int argc, char **argv)
{
    int board[10000];
    int i = 0;
    
    if (argc != 2)
        return (1);
    int    size = atoi(argv[1]);
    while(i < size)
        board[i++] = 0;
    queens(board, 0, size);
    return (0);
}