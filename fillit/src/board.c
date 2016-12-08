/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:25:50 by dye               #+#    #+#             */
/*   Updated: 2016/11/28 16:25:52 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_compn_in_pos(t_board *board, t_position *pos)
{
	board->map[index_in_map(board, pos)] = '.';
}

/*
** Will remove a tetri's components backwardly from component_number
*/

void	remove_placed_compn(t_board *board, t_position *pos,
	t_tetrimino *tetri, int component_number)
{
	t_position	compn_pos;

	while (component_number >= 0)
	{
		compn_pos = get_compn_pos_in_board(pos, tetri, component_number);
		remove_compn_in_pos(board, &compn_pos);
		component_number--;
	}
}

/*
** iterative version
** return
** - 0 => success
** - 1 => fail
** if fail, will retore the map as no tetri has been placed
*/

int		put_tetri_at_pos(t_board *board, t_position *pos,
	t_tetrimino *tetri)
{
	int			component_number;
	t_position	compn_pos;

	component_number = -1;
	while (++component_number < 4)
	{
		compn_pos = get_compn_pos_in_board(pos, tetri, component_number);
		if (is_valid_empty_pos(board, &compn_pos))
			put_compn_in_pos(board, &compn_pos, tetri->c);
		else
		{
			remove_placed_compn(board, pos, tetri, component_number - 1);
			return (1);
		}
	}
	return (0);
}

void	remove_tetri_at_pos(t_board *board, t_position *pos,
	t_tetrimino *tetri)
{
	remove_placed_compn(board, pos, tetri, 3);
}
