/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:33:02 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:34:00 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*pstr;
	size_t	len_to_find;

	if (*to_find == 0)
		return ((char *)str);
	len_to_find = ft_strlen(to_find);
	pstr = (char *)str;
	while (*pstr && (len-- >= len_to_find))
	{
		if (ft_strncmp(pstr, to_find, len_to_find) == 0)
			return (pstr);
		pstr++;
	}
	return (NULL);
}
