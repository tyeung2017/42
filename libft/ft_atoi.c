/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:13:47 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/15 22:49:08 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_sign(char *str)
{
	int sign;

	if (*str == '-')
		sign = 1;
	else
		sign = 0;
	return (sign);
}

static char		*ft_isspace(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == ' ' || *str == '\f' ||
			*str == '\r' || *str == '\v')
		str++;
	return (str);
}

int				ft_atoi(char *str)
{
	unsigned long long		result;
	int						digit;
	int						sign;
	int						i;

	result = 0;
	i = 0;
	str = ft_isspace(str);
	sign = ft_sign(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str)
	{
		digit = *str - '0';
		if (digit > 9 || digit < 0)
			break ;
		result = (10 * result) + digit;
		str++;
		i++;
	}
	if (i > 19 || result >= 9223372036854775808ULL)
		return (sign == 1 ? 0 : -1);
	return (sign == 1 ? -result : result);
}
