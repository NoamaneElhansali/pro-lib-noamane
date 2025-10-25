/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:39:22 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 18:56:40 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_word(char *s, char c)
{
	int	is_word;
	int	count;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

char	*ft_get_word(char *start, char *end)
{
	return (ft_substr(start, 0, end - start));
}

char	**ft_split(char const *s, char c)
{
	const char	*tmp;
	char		**ptr;

	int (len_s), (i);
	if (!s)
		return (NULL);
	len_s = ft_count_word((char *)s, c);
	ptr = malloc((len_s + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		tmp = s;
		while (*s && *s != c)
			s++;
		if (s > tmp)
			ptr[i++] = ft_get_word((char *)tmp, (char *)s);
	}
	ptr[i] = NULL;
	return (ptr);
}