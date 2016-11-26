/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:56:21 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/16 22:54:50 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WSPACE(x) (x == '\t' || x == '\n' || x == ' ')

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (WSPACE(s[j]))
		j++;
	while (WSPACE(s[i]) && i > j)
		i--;
	str = ft_strsub(&s[j], 0, i - j + 1);
	if (!str)
		return (NULL);
	return (str);
}
