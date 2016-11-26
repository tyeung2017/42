/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:03:10 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/13 21:48:41 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *ptr;

	ptr = dst;
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
		{
			dst++;
			return (dst);
		}
		dst++;
	}
	return (NULL);
}
