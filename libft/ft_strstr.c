/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:23:36 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 17:23:39 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int			i;
	const char	*ptr;
	char		*s;

	i = 0;
	s = (char *)big;
	if (*little == '\0')
		return (s);
	while (*big)
	{
		ptr = big;
		while ((*ptr == little[i]) && little[i])
		{
			ptr++;
			i++;
		}
		s = (char *)big;
		if (little[i] == '\0')
			return (s);
		i = 0;
		big++;
	}
	return (0);
}
