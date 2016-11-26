/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:59:46 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/15 22:43:49 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int	word;
	int has_word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		has_word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			has_word = 1;
			i++;
		}
		if (has_word == 1)
			word++;
	}
	return (word);
}

static int		char_count(const char *s, char c)
{
	int	count;
	int i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*w;
	int		wc;
	int		i;
	int		wt;

	if (!s || !(arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	wc = 0;
	wt = word_count(s, c);
	while (wc < wt)
	{
		i = 0;
		if (!(w = (char *)malloc(sizeof(char) * (char_count(s, c) + 1))))
			return (NULL);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			w[i++] = *s++;
		w[i] = '\0';
		arr[wc++] = w;
	}
	arr[wc] = 0;
	return (arr);
}
