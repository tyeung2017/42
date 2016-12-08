/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 08:07:54 by tyeung            #+#    #+#             */
/*   Updated: 2016/12/04 15:09:25 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
}

/*
** wonder whats the return for empty file
*/

char	*readin(char *str)
{
	char	*buf;
	int		fd;
	int		count;

	if (!(buf = ft_strnew(545)))
		return (NULL);
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	if ((count = read(fd, buf, 546)) <= 0)
		return (NULL);
	close(fd);
	return (buf);
}

int		connected(char *str)
{
	int i;
	int	con;
	int	block;

	i = 0;
	con = 0;
	block = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (i < 20 && str[i + 1] == '#')
				con++;
			if (i <= 15 && str[i + 5] == '#')
				con++;
			block++;
		}
		i++;
	}
	if (block != 4)
		return (0);
	return ((con == 3 || con == 4));
}

/*
** return 0 as error
*/

int		check(char *str)
{
	int	len;
	int	i;

	if (!str || (((len = ft_strlen(str)) - 20) % 21 != 0))
		return (0);
	while (*str)
	{
		i = 0;
		while (i < 21)
		{
			if (i % 5 < 4 && i != 20 && str[i] != '.' && str[i] != '#')
				return (0);
			else if ((i % 5 == 4 || i == 19) && str[i] != '\n')
				return (0);
			i++;
		}
		if (!connected(str))
			return (0);
		str += 21;
	}
	return (1);
}
