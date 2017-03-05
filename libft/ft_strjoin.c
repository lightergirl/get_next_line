/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:38:29 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 21:20:19 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *newstring;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(newstring = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(newstring, s1);
	ft_strcat(newstring, s2);
	return (newstring);
}
