/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:26:26 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/18 16:18:09 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char		*i;
	const char		*ptr;
	const char		*s;

	i = big + len;
	if (*little == '\0')
		return ((char *)big);
	while (big < i && *big)
	{
		ptr = big;
		s = little;
		while (ptr < i && *ptr && *s)
			if (*ptr++ != *s)
				break ;
			else
				s++;
		if (*s == '\0')
			return ((char *)big);
		big++;
	}
	return (0);
}
