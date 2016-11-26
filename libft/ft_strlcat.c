/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:26:16 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/18 16:07:03 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	o;
	int		i;

	i = 0;
	d = ft_strlen(dst);
	o = d;
	if (size < d + 1)
		return (size + ft_strlen(src));
	while (d < size - 1 && *src)
		dst[d++] = src[i++];
	dst[d] = '\0';
	return (o + ft_strlen(src));
}
