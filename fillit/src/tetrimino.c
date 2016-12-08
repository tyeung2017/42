/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:26:43 by dye               #+#    #+#             */
/*   Updated: 2016/12/03 17:26:46 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Return the index in the shape array based on info in controler
** 5 is the col_max in 2d view of the 1d array
*/

int		index_in_shape(t_controler *c)
{
	return (5 * c->row + c->col);
}

void	init_controler(t_controler *c)
{
	c->row_offset = 0;
	c->col_offset = 0;
	c->component_number = 0;
	c->row = -1;
}

/*
** row_offset is the row position of the 1st compn in the shape table
** col_offset is the col position of the 1st compn in the shape table
** - they will be used to calculate
**		the relative position of other compn to the 1st one
*/

void	store_first_compn_info(t_tetrimino *t, t_controler *c)
{
	c->row_offset = c->row;
	c->col_offset = c->col;
	t->piece[c->component_number][0][0] = 0;
	t->piece[c->component_number][1][0] = 0;
	t->c = 'A';
	(c->component_number)++;
}

void	store_non_first_compn_info(t_tetrimino *t,
			t_controler *c, int tetrimino_number)
{
	t->piece[c->component_number][0][0] = c->row - c->row_offset;
	t->piece[c->component_number][1][0] = c->col - c->col_offset;
	t->c = 'A' + tetrimino_number;
	(c->component_number)++;
}

/*
** Assume the input shape is a valid tetrimino
** - shape is 4 lines from input file representing a piece
**	- it is actually a 1d char array of 20 char length
**		- ignoring extra \n in each group
** - shape is pointing to the 1st char in the string
** -------------------
** Shape in 2d view
** ..##
** .##.
** ....
** ....
** -------------------
** Shape in 1d view
** ..##\n.##.\n....\n....\n
** ===================
** tetrimino_number is used to get the char of a tetri
**	 based on its incoming order
*/

void	from_shape_to_tetrimino(t_tetrimino *t, char *shape,
	t_controler *c, int tetrimino_number)
{
	init_controler(c);
	while (++(c->row) < 4)
	{
		c->col = -1;
		while (++(c->col) < 4)
		{
			if (shape[index_in_shape(c)] == '#' && c->component_number == 0)
				store_first_compn_info(t, c);
			else if (shape[index_in_shape(c)] == '#'
					&& c->component_number != 0)
			{
				store_non_first_compn_info(t, c, tetrimino_number);
				if (c->component_number == 4)
					return ;
			}
		}
	}
}
