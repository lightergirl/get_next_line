/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:51:21 by eignatye          #+#    #+#             */
/*   Updated: 2017/02/19 16:51:24 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *look_for_fd(t_list fd_list, const int fd)
{
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

int		read_the_file(t_list current_fd, char *buff, const int fd)
{
	size_t	bytes_read;
	char    *tmp;

	while (!ft_strchr(current_fd->content, '\n') && 
			bytes_read = read(current_fd->content_size, buff, BUFF_SIZE) > 0)
	{
		if (!(tmp = ft_strnew(bytes_read))
			return (0);
		ft_strncpy(tmp, buff, bytes_read);
		ft_bzero(buff, bytes_read);
		if (!current_fd->content)
			current_fd->content = ft_strdup(tmp);
		else
			current_fd->content = ft_strjoin(current_fd->content, tmp);
		free(tmp);
	}
	if (!current_fd->content)
		return (0);
	return (1);
}

//searching for \n & cutting the content

int 	get_next_line(const int fd, char **line)
{
	static  t_list  *fd_list = NULL;
	t_list          *current_fd;
	char            buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 1) < 0)
		return (-1);
	ft_bzero(&buff, BUFF_SIZE + 1);
	current_fd = look_for_fd(&fd_list, fd);
	if (!(read_the_file(current_fd, buff, fd))
		return (0);
	//
}