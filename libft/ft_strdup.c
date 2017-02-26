/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:00:52 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 21:09:57 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem_array;

	mem_array = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (mem_array == 0)
		return (NULL);
	ft_strcpy(mem_array, s1);
	return (mem_array);
}
