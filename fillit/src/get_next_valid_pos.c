/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_valid_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:22:30 by dye               #+#    #+#             */
/*   Updated: 2016/12/03 18:22:32 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_same_pos(t_position *p1, t_position *p2)
{
	return (p1->row == p2->row && p1->col == p2->col);
}

/*
** The next valid position is
**  - either next col on the same line
** 	- or first col on the next line
**  - will return the same position if current position is the end of the map
*/

t_position	get_next_valid_pos(t_board *board, t_position *current)
{
	t_position next;

	next.row = 0;
	next.col = 0;
	if (is_end_pos(board, current))
		next = *current;
	else if ((current->col + 1) < board->col_max - 1)
	{
		next.col = current->col + 1;
		next.row = current->row;
	}
	else if ((current->row + 1) < board->row_max)
	{
		next.row = current->row + 1;
		next.col = 0;
	}
	return (next);
}

/*
** Return
**	- 0 => success
** 	- 1 => fail
*/

int			increase_map(t_board *board)
{
	int		new_size;
	char	*map;

	board->row_max++;
	board->col_max++;
	new_size = (board->col_max) * (board->row_max) + 1;
	free(board->map);
	if (!(map = (char*)malloc(sizeof(char) * new_size)))
		return (1);
	board->map = ft_memset(map, '.', new_size - 1);
	map[new_size - 1] = '\0';
	return (0);
}

/*
** Doesn't check if component_number is valid or not
*/

t_position	get_compn_pos_in_board(t_position *pos,
	t_tetrimino *t, int component_number)
{
	t_position p_in_board;

	p_in_board.row = t->piece[component_number][0][0] + pos->row;
	p_in_board.col = t->piece[component_number][1][0] + pos->col;
	return (p_in_board);
}

void		put_compn_in_pos(t_board *board, t_position *pos, char c)
{
	board->map[index_in_map(board, pos)] = c;
}
