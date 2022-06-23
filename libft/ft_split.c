/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:02:02 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 22:03:44 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr, int p_index)
{
	int		i;

	i = 0;
	while (i < p_index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_count(const char *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		f;
	int		p_index;

	strings = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	i = 0;
	p_index = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		f = i;
		while (s[i] != c && s[i])
			i++;
		if (i > f)
		{
			strings[p_index] = ft_substr(s, f, i - f);
			if (!strings[p_index])
				return (ft_free(strings, p_index));
			p_index++;
		}
	}
	strings[p_index] = NULL;
	return (strings);
}
