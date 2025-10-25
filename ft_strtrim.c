/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:25:26 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/21 18:55:08 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_is_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*tmp;

	int (i), (j);
	i = 0;
	if (!s1[i] && set[i])
	{
		ptr = malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	while (*(s1 + i) && ft_is_set((char)*(s1 + i), (char *)set))
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (*(s1 + j) && ft_is_set((char)*(s1 + j), (char *)set))
		j--;
	ptr = malloc((j - i + 2) * sizeof(char));
	tmp = ptr;
	while (i <= j)
		*ptr++ = *(s1 + i++);
	*ptr = '\0';
	return (tmp);
}
