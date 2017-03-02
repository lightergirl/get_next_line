/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:51:21 by eignatye          #+#    #+#             */
/*   Updated: 2017/02/23 23:51:19 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*look_for_fd(size_t fd)
{
	
	static  t_list  *fd_list = NULL;
	t_list	*current_fd;
    
    current_fd = fd_list;
    while (current_fd)
    {
        if (current_fd->content_size == fd)
            return (current_fd);
        current_fd = current_fd->next;
    }
    current_fd = ft_lstnew(0, 0);
    current_fd->content_size = fd;
    ft_lstadd(&fd_list, current_fd);
    return (current_fd);
}

int		read_the_file(t_list *current_fd, char *buff)
{
    size_t	bytes_read;
    char    *tmp;
    
	tmp = NULL;
	while (!ft_strchr(current_fd->content, '\n') &&
           ((bytes_read = read((int)current_fd->content_size, buff, BUFF_SIZE)) > 0))
    {
        if (!(tmp = ft_strnew(bytes_read)))
            return (0);
        ft_strncpy(tmp, buff, bytes_read);
        ft_bzero(buff, bytes_read);
        if (!current_fd->content)
            current_fd->content = ft_strdup(tmp);
        else
            current_fd->content = ft_strjoin(current_fd->content, tmp);
        free(tmp);
		tmp = NULL;
    }
    if (!current_fd->content)
        return (0);
    return (1);
}

int		cut_the_content(t_list *current_fd, char **line)
{
    unsigned int	i;
    char			*tmp;
    
    i = 0;
    tmp = NULL;
    while (((char *)current_fd->content)[i] && ((char *)current_fd->content)[i] != '\n')
        i++;
    if (!(*line = ft_strnew(i)))
        return (0);
    ft_strncpy(*line, current_fd->content, (size_t) i);
    if (((char *)current_fd->content)[i] == '\n')
        if (!(tmp = ft_strsub((char *)current_fd->content,
					i + 1,
					ft_strlen((char *)current_fd->content) - i - 1)))
            return (0);
#warning memory leak
    //ft_memdel((void**)&(current_fd->content));
    current_fd->content = tmp;
    free(tmp);
    return (1);
    
}

int 	get_next_line(const int fd, char **line)
{
	
    t_list          *current_fd;
    char            buff[BUFF_SIZE + 1];
    
	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
        return (-1);
    ft_bzero(buff, BUFF_SIZE + 1);
    current_fd = look_for_fd((size_t)fd);
    if ((read_the_file(current_fd, buff) && cut_the_content(current_fd, line)))
		if (*line)
			return (1);
	return (0);
}
