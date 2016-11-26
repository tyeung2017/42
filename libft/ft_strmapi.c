/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:25:18 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 22:38:19 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return (0);
	if (!(str = ft_strdup(s)))
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
