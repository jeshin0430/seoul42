/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:45:58 by jeshin            #+#    #+#             */
/*   Updated: 2020/02/06 14:51:16 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int chess[10][10])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (chess[i][j] == 1)
			{
				c = '0' + j;
				write(1, &c, 1);
				j = 10;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	move_queen(int chess[10][10], int row, int col)
{
	int i;
	int j;

	if (chess[row][col] == 0)
		i = -1;
	else
		i = 1;
	j = -1;
	while (++j < 10)
	{
		chess[row][j] += i;
		chess[j][col] += i;
		if (row - j >= 0 && col - j >= 0)
			chess[row - j][col - j] += i;
		if (row + j < 10 && col + j < 10)
			chess[row + j][col + j] += i;
		if (row - j >= 0 && col + j < 10)
			chess[row - j][col + j] += i;
		if (row + j < 10 && col - j >= 0)
			chess[row + j][col - j] += i;
	}
	if (i == 1)
		chess[row][col] = 0;
	else
		chess[row][col] = 1;
}

void	recursive(int chess[10][10], int *result, int row)
{
	int col;

	col = 0;
	if (row == 10)
	{
		*result += 1;
		print_result(chess);
	}
	else
	{
		while (col < 10)
		{
			if (chess[row][col] == 0)
			{
				move_queen(chess, row, col);
				recursive(chess, result, row + 1);
				move_queen(chess, row, col);
			}
			col++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int j;
	int chess[10][10];
	int result;

	result = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			chess[i][j] = 0;
			j++;
		}
		i++;
	}
	recursive(chess, &result, 0);
	return (result);
}
