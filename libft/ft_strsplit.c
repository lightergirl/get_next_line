/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:28:12 by eignatye          #+#    #+#             */
/*   Updated: 2016/12/14 21:41:52 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**init_array(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**array;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	if (!(array = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	return (array);
}

static char	**fill_array(char const *s, char c, char **array)
{
	size_t i;
	size_t j;
	size_t len;

	len = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				array[j] = ft_strsub(s, i - len + 1, len);
				j++;
				len = 0;
			}
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	char **array;

	if (s)
		if ((array = init_array(s, c)) != NULL)
			return (fill_array(s, c, array));
	return (NULL);
}
