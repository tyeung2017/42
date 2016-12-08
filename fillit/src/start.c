/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:12:26 by dye               #+#    #+#             */
/*   Updated: 2016/12/05 01:57:21 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Assume have at least one tetri to put
** return
** - 0 => success
** - 1 => fail
*/

int		start(char *str)
{
	int			n_of_tetris;
	t_board		b;
	t_position	p;
	t_tetrimino	tetrimino_list[26];

	store_tetriminos(str, tetrimino_list, &n_of_tetris);
	if (init_board(&b, find_minimum_map_row(n_of_tetris)) == 0)
	{
		p.col = 0;
		p.row = 0;
		if (put_tetri_a_from_pos(&b, &p, tetrimino_list, n_of_tetris) == 0)
		{
			print_board(&b);
			free(b.map);
			return (0);
		}
	}
	return (1);
}
