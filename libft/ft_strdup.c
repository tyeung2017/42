/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:28:48 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:30:22 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s;

	s = (char*)malloc(ft_strlen(s1) + 1);
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	return (s);
}