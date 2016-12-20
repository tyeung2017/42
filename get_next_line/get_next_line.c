/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 09:42:34 by tyeung            #+#    #+#             */
/*   Updated: 2016/12/19 22:23:41 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		no_nl(char **str, char **line, int ret)
{
	int	count;

	count = 0;
	*line = ft_strdup(*str);
	count = ft_strlen(*str);
	ft_strdel(str);
	if (ret == 0)
	{
		if (count > 0)
			return (1);
		else
		{
			*line = NULL;
			return (0);
		}
	}
	return (1);
}

int		nl_found(char **str, char **line, char *nl_pos)
{
	char	*temp;

	*line = ft_strsub(*str, 0, nl_pos - *str);
	temp = ft_strsub(*str, nl_pos - *str + 1, ft_strlen(nl_pos) - 1);
	ft_strdel(str);
	*str = temp;
	return (1);
}

int		copy_lines(int ret, char *buf, char **str)
{
	char	*tmp;

	tmp = NULL;
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	if ((*str) != NULL)
	{
		tmp = ft_strjoin(*str, buf);
		ft_strdel(str);
	}
	else
		tmp = ft_strdup(buf);
	*str = tmp;
	return (0);
}

t_text	*m_list(int fd, t_list **head)
{
	t_list	*new;

	new = NULL;
	if (*head == NULL)
	{
		new = ft_lstnew((void *)&(t_text){fd, NULL}, sizeof(t_text));
		ft_lstadd(head, new);
		return ((t_text *)((*head)->content));
	}
	if (((t_text *)((*head)->content))->fd == fd)
		return ((t_text *)((*head)->content));
	else
		return (m_list(fd, &((*head)->next)));
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_text			*temp;
	int				ret;
	char			*buff;

	ret = 42;
	if (fd < 0 || BUFF_SIZE < 1 || !line || !(buff = ft_strnew(BUFF_SIZE))
			|| !(temp = m_list(fd, &head)))
		return (-1);
	while (temp->str == NULL || (!(ft_strchr(temp->str, '\n')) &&
				(ret = read(fd, buff, BUFF_SIZE))))
	{
		if (copy_lines(ret, buff, &temp->str) == -1)
			return (-1);
	}
	ft_strdel(&buff);
	if (ft_strchr(temp->str, '\n') && temp->str != NULL)
		return (nl_found(&temp->str, line, ft_strchr(temp->str, '\n')));
	else if (!(ft_strchr(temp->str, '\n')) && temp->str != NULL)
		return (no_nl(&temp->str, line, ret));
	return (-1);
}
