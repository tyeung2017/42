/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 09:42:34 by tyeung            #+#    #+#             */
/*   Updated: 2016/12/12 10:20:52 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_text	*m_list(int fd, t_list **head)
{
	t_list	*new;

	new = NULL;
	if (*head == NULL)
	{
		new = ft_lstnew((void *)&(t_text){fd, NULL}, sizeof(t_text));//(void *) and typecasting may not need
		ft_lstadd(head, new);
		return ((t_text *)(*head)->content); 
	}
	if ((*head)->content->fd == fd)
		return ((t_text *)(*head)->content);
	else
		m_list(fd, &((*head)->next)); //let's see if we need the return in the front
	return (NULL);
}

int     get_next_line(const int fd, char **line)
{
	static t_list	head;
	t_text			*temp;
	int				ret;
	char			*buff;
	
	if (fd < 0 || BUFF_SIZE < 1 || !line || !(buff = ft_strnew(BUFF_SIZE)) 
|| !(temp = m_list(fd, &head)))
		return (-1);
	if ()
}
