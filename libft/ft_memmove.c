/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:27:35 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 20:16:30 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_copy;
	unsigned char	*src_copy;
	size_t			i;

	dst_copy = (unsigned char *)dst;
	src_copy = (unsigned char *)src;
	i = 0;
	if (dst < src)
		while (i < len)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
	else
		while (i < len)
		{
			dst_copy[len - i - 1] = src_copy[len - i - 1];
			i++;
		}
	return (dst);
}
