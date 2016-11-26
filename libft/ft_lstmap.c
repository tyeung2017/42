/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:44:45 by tyeung            #+#    #+#             */
/*   Updated: 2016/11/11 21:44:47 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (new);
}
