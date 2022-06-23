/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:08:41 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:35:57 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	substr = (char *)(ft_calloc((len + 1), sizeof(char)));
	i = 0;
	if (substr == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (substr);
	while ((len--) && (s[start + i]))
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
