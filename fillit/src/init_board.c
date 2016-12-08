/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:42:21 by dye               #+#    #+#             */
/*   Updated: 2016/12/03 20:30:14 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_minimum_map_row(int n_of_tetris)
{
	int size;
	int min_n_of_chars;

	size = 2;
	min_n_of_chars = 4 * n_of_tetris;
	while (size * size < min_n_of_chars)
		size++;
	return (size);
}

/*
** Return
**	- 0 => success
** 	- 1 => fail
*/

int		init_board(t_board *b, int row)
{
	int		size;
	char	*map;

	size = (row + 1) * row + 1;
	b->row_max = row;
	b->col_max = row + 1;
	if (!(map = (char*)malloc(sizeof(char) * size)))
		return (1);
	b->map = ft_memset(map, '.', size - 1);
	map[size - 1] = '\0';
	return (0);
}

void	add_newline(t_board *b)
{
	int i;
	int row;

	row = -1;
	i = b->col_max - 1;
	while (++row < b->row_max)
	{
		b->map[i] = '\n';
		i += b->col_max;
	}
}

void	print_board(t_board *b)
{
	add_newline(b);
	ft_putstr(b->map);
}
