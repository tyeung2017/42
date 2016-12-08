/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:45:54 by dye               #+#    #+#             */
/*   Updated: 2016/11/28 12:45:59 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** - Make sure there is at least one tetrimino in list
**      before calling put_tetri_a_from_pos()
**	- *list is pointing to the first piece in the whole list
** - Only pass in valid position
** - get_next_valid_pos() in put_tetri_a_from_pos()
**      will never return the same pos,
**  - because is_end_pos(board, pos) has handled it
** - return
**  - 0 => success
**  - 1 => fail
*/

int		put_tetri_a_from_pos(t_board *board, t_position *pos,
	t_tetrimino *list, int n_of_tetris)
{
	t_position next;
	t_position begin;

	reset_pos(&begin);
	if (is_end_pos(board, pos))
	{
		if (increase_map(board) == 0)
			return (put_tetri_a_from_pos(board, &begin, list, n_of_tetris));
		return (1);
	}
	next = get_next_valid_pos(board, pos);
	if (is_empty_pos(board, pos))
	{
		if (put_tetri_at_pos(board, pos, list) == 0)
		{
			if (put_tetris_from_pos(board, &begin, list + 1,
									n_of_tetris - 1) == 0)
				return (0);
			else
				remove_tetri_at_pos(board, pos, list);
		}
	}
	return (put_tetri_a_from_pos(board, &next, list, n_of_tetris));
}

/*
** return
** - 0 => success
** - 1 => fail
** if fail, will retore the map as no pieces have been placed
*/

int		put_tetris_from_pos(t_board *board,
	t_position *pos, t_tetrimino *list, int n_of_tetris)
{
	t_position next;
	t_position begin;

	reset_pos(&begin);
	if (n_of_tetris == 0)
		return (0);
	if (is_end_pos(board, pos))
		return (1);
	next = get_next_valid_pos(board, pos);
	if (is_empty_pos(board, pos))
	{
		if (put_tetri_at_pos(board, pos, list) == 0)
		{
			if (put_tetris_from_pos(board, &begin, list + 1,
									n_of_tetris - 1) == 0)
				return (0);
			else
				remove_tetri_at_pos(board, pos, list);
		}
	}
	return (put_tetris_from_pos(board, &next, list, n_of_tetris));
}

void	reset_pos(t_position *p)
{
	p->row = 0;
	p->col = 0;
}
