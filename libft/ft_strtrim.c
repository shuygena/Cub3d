/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:38:09 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:35:45 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcmp(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*clean;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_setcmp(s1[start], set))
		start++;
	while (end > start && ft_setcmp(s1[end - 1], set))
		end--;
	clean = (char *)malloc(sizeof(char) * (end - start + 1));
	if (clean == NULL)
		return (NULL);
	while (start < end)
		clean[i++] = s1[start++];
	clean[i] = '\0';
	return (clean);
}
