/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:01:13 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:04:09 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WSPACE(x) ((x >= 9 && x <= 13) || x == ' ')

void	ft_capitalize(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (i != 0 && ft_isalpha(s[i]) && !WSPACE(s[i - 1]))
			s[i] = ft_tolower(s[i]);
		else
			s[i] = ft_toupper(s[i]);
		i++;
	}
}
