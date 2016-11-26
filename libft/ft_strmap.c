/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:25:59 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 22:38:14 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	if (!(str = ft_strdup(s)))
		return (0);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
