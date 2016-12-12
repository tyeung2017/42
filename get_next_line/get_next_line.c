/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 09:42:34 by tyeung            #+#    #+#             */
/*   Updated: 2016/12/11 09:42:36 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(const int fd, char **line)
{
	int		ret;
	char	*buff;
	
	ret = 0;
	if (BUFF_SIZE < 1 || !(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ()
}
