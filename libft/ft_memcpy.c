/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:42:33 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/06 10:57:29 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dptr;
	char const	*sptr;

	dptr = dst;
	sptr = src;
	while (n--)
		*dptr++ = *sptr++;
	return (dst);
}
