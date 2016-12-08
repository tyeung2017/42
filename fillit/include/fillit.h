/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:56:16 by dye               #+#    #+#             */
/*   Updated: 2016/12/04 13:30:36 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_tetrimino
{
	int			piece[4][2][1];
	char		c;
}				t_tetrimino;

typedef struct	s_position
{
	int			row;
	int			col;
}				t_position;

typedef struct	s_board
{
	char		*map;
	int			col_max;
	int			row_max;
}				t_board;

/*
** Norm doesn't allow too many variables in one function,
** therefore put them in a struct.
*/

typedef struct	s_controler
{
	int			component_number;
	int			row;
	int			col;
	int			row_offset;
	int			col_offset;
}				t_controler;

int				index_in_map(t_board *board, t_position *pos);
int				is_empty_pos(t_board *board, t_position *pos);
int				is_valid_pos(t_board *board, t_position *pos);
int				is_end_pos(t_board *board, t_position *pos);
int				is_same_pos(t_position *p1, t_position *p2);
t_position		get_next_valid_pos(t_board *board, t_position *current);
int				increase_map(t_board *board);
int				put_tetris_from_pos(t_board *board,
									t_position *pos,
									t_tetrimino *list,
									int n_of_tetris);
int				put_tetri_a_from_pos(t_board *board,
									t_position *pos,
									t_tetrimino *list,
									int n_of_tetris);
t_position		get_compn_pos_in_board(t_position *pos,
									t_tetrimino *t, int component_number);
int				is_valid_empty_pos(t_board *board, t_position *pos);
void			put_compn_in_pos(t_board *board, t_position *pos, char c);
void			remove_compn_in_pos(t_board *board, t_position *pos);
void			put_compn_in_pos(t_board *board, t_position *pos, char c);
void			remove_compn_in_pos(t_board *board, t_position *pos);
void			remove_placed_compn(t_board *board, t_position *pos,
									t_tetrimino *tetri, int component_number);
int				put_tetri_at_pos(t_board *board, t_position *pos,
									t_tetrimino *tetri);
void			remove_tetri_at_pos(t_board *board, t_position *pos,
									t_tetrimino *tetri);
void			from_shape_to_tetrimino(t_tetrimino *t, char *shape,
										t_controler *c, int tetrimino_number);
void			store_tetriminos(char *str, t_tetrimino *t, int *n_of_tetris);
int				find_minimum_map_row(int n_of_tetris);
int				init_board(t_board *b, int row);
void			add_newline(t_board *b);
void			print_board(t_board *b);
int				start(char *str);
void			error(void);
char			*readin(char *str);
int				connected(char *str);
int				check(char *str);
void			reset_pos(t_position *p);
#endif
