/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:40:56 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 18:44:10 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*start;

	if (!(lst && f))
		return (NULL);
	start = f(lst);
	current = start;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		current = current->next;
	}
	return (start);
}
