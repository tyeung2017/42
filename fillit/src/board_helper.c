/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:20:56 by dye               #+#    #+#             */
/*   Updated: 2016/12/03 18:20:59 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** The map in the board is a 1d char array, initialized with '.'.
** If nothing on a position, it is '.'.
** Return
**	- 0 => false
** 	- 1 => true
*/

int			is_empty_pos(t_board *board, t_position *pos)
{
	return (board->map[index_in_map(board, pos)] == '.');
}

/*
** Return the index in the 1d array of position(row, col)
** 	- no error checking
*/

int			index_in_map(t_board *board, t_position *pos)
{
	return (board->col_max * pos->row + pos->col);
}

/*
** A valid position in the concept of 2d array board map is
**  - valid row: 0 <= row < row_max
** 	- valid col: 0 <= col < col_max - 1
*/

int			is_valid_pos(t_board *board, t_position *pos)
{
	return ((0 <= pos->row && pos->row < board->row_max)
			&& (0 <= pos->col && pos->col < board->col_max - 1));
}

/*
** Return
**	- 0 => false
** 	- 1 => true
*/

int			is_valid_empty_pos(t_board *board, t_position *pos)
{
	return (is_valid_pos(board, pos) && is_empty_pos(board, pos));
}

/*
** Check if pos is at the end of the map
** 	- the final valid position of the map
**		- in 1d array view, it is
**		-  col_max * row_max - 2
** 			- minus 1 because index is 0-based
**			- minus another 1 because
**				- the actual last index in the 1d array is '\n'
**		- therefore, the index of final valid map position in the 1d array is
** 			- col_max * row_max - 2
**			- total_number_of_element_(without \0) - 2
*/

int			is_end_pos(t_board *board, t_position *pos)
{
	return (index_in_map(board, pos) == (board->col_max * board->row_max - 2));
}
