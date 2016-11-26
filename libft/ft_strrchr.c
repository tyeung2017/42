/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:21:39 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:21:40 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;

	s1 = s;
	while (*s1)
		s1++;
	if ((unsigned char)c == '\0')
		return ((char *)s1);
	while (s1 > s)
	{
		s1--;
		if (*s1 == (unsigned char)c)
			return ((char *)s1);
	}
	return (0);
}
