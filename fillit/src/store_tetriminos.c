/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:55:17 by dye               #+#    #+#             */
/*   Updated: 2016/12/03 18:55:19 by dye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** convert/store tetriminos in str to an array of t_tetriminos
**	- max number of actual tetriminos is 26
**	- assume valid map content
**		- no error checking
*/

void	store_tetriminos(char *str, t_tetrimino *t, int *n_of_tetris)
{
	int			tetrimino_number;
	char		*end;
	t_controler	c;

	tetrimino_number = -1;
	end = str + ft_strlen(str);
	while (end - str >= 21 && ++tetrimino_number < 26)
	{
		from_shape_to_tetrimino(&t[tetrimino_number],
			str, &c, tetrimino_number);
		str += 21;
	}
	if (end - str == 20 && ++tetrimino_number < 26)
	{
		from_shape_to_tetrimino(&t[tetrimino_number],
			str, &c, tetrimino_number);
	}
	*n_of_tetris = tetrimino_number + 1;
}
