/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:20:59 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:21:00 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	size_t	n;
	size_t	i;
	char	c;

	i = 0;
	n = ft_strlen(s);
	while (i <= ft_strlen(s) / 2)
	{
		c = s[i];
		s[i++] = s[--n];
		s[n] = c;
	}
}
