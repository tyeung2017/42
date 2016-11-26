/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:16:56 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:50:24 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define WSPACE(x) ((x >= 9 && x <= 13) || x == ' ')

int	ft_word_count(char const *s)
{
	int word;
	int has_word;
	int i;

	word = 0;
	i = 0;
	while (s[i])
	{
		has_word = 0;
		while (WSPACE(s[i]) && s[i])
			i++;
		while (!WSPACE(s[i]) && s[i])
		{
			has_word = 1;
			i++;
		}
		if (has_word == 1)
			word++;
	}
	return (word);
}
