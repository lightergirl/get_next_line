/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:12:33 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 18:28:17 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_int_size(int n)
{
	size_t size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		flag;

	flag = 0;
	if (n < 0)
		flag = 1;
	size = get_int_size(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (size != 0)
	{
		if (n < 0)
			str[--size] = '0' - (n % 10);
		if (n >= 0)
			str[--size] = '0' + (n % 10);
		n = n / 10;
	}
	if (flag)
		str[0] = '-';
	return (str);
}
