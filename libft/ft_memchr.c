/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:44:14 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:44:16 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*ptr;

	ptr = (void *)s;
	while (n--)
	{
		if (*(unsigned char *)ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
