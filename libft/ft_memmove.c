/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:38:15 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:38:16 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dptr;
	const char	*sptr;

	dptr = dst;
	sptr = src;
	if (src < dst)
	{
		dptr += len;
		sptr += len;
		while (len--)
			*--dptr = *--sptr;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
