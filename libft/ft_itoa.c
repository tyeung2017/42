/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:12:53 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/14 23:42:18 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len(int n)
{
	int l;

	l = 1;
	while (n /= 10)
		l++;
	return (l);
}

char				*ft_itoa(int n)
{
	size_t		len;
	char		*s;
	long int	tmp;

	len = ft_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp *= -1;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	s[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		s[--len] = tmp % 10 + '0';
	return (s);
}
