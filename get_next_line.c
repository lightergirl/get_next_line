/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:51:21 by eignatye          #+#    #+#             */
/*   Updated: 2017/03/04 17:52:47 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*look_for_fd(size_t fd, t_list **head)
{
	t_list			*current_fd;
	t_list			*tmp;

	current_fd = *head;
	tmp = *head;
	while (current_fd)
	{
		if (current_fd->content_size == fd)
			return (current_fd);
		current_fd = current_fd->next;
	}
	current_fd = ft_lstnew(0, 0);
	current_fd->content_size = fd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = current_fd;
	return (current_fd);
}

int					read_the_file(t_list *current_fd, char *buff)
{
	size_t			bytes_read;
	char			*tmp;

	while ((!ft_strchr(current_fd->content, '\n')) &&
	((bytes_read = read((int)current_fd->content_size, buff, BUFF_SIZE)) > 0))
	{
		buff[bytes_read] = '\0';
		tmp = current_fd->content;
		current_fd->content = (current_fd->content == NULL) ? ft_strdup(buff) :
								ft_strjoin(current_fd->content, buff);
		ft_memdel((void **)&tmp);
	}
	if (!ft_strlen(current_fd->content))
		return (0);
	return (1);
}

int					cut_the_content(t_list *current_fd, char **line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	while (((char *)current_fd->content)[i] &&
			((char *)current_fd->content)[i] != '\n')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	ft_strncpy(*line, current_fd->content, (size_t)i);
	if (((char *)current_fd->content)[i] == '\n')
		tmp = ft_strsub((char *)current_fd->content, i + 1,
			ft_strlen((char *)current_fd->content) - i - 1);
	ft_memdel((void **)&(current_fd->content));
	current_fd->content = tmp;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*current_fd;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, buff, 0) == -1)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (!fd_list)
		fd_list = ft_lstnew(0, (size_t)fd);
	current_fd = look_for_fd((size_t)fd, &fd_list);
	if ((read_the_file(current_fd, buff) && cut_the_content(current_fd, line)))
		if (*line)
			return (1);
	return (0);
}
