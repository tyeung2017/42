/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:30:32 by tyeung            #+#    #+#             */
/*   Updated: 2016/12/05 01:55:26 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	char	*str;

	str = readin(argv[1]);
	if (argc == 1)
		write(1, "usage: fillit [filename] target_file", 37);
	else if (!check(str) || argc != 2)
		error();
	else if (start(str) != 0)
		error();
	return (0);
}
