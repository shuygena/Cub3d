/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:12:43 by mskeleto          #+#    #+#             */
/*   Updated: 2020/11/09 19:52:09 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	int		i;
	size_t	k;
	size_t	j;

	i = 0;
	j = 0;
	k = 0;
	if (dstsize <= ft_strlen(dest))
		return (ft_strlen(src) + dstsize);
	while (dest[j] != '\0')
		j++;
	k = j;
	while ((src[i] != '\0') && (j < dstsize - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (src[i] == '\0')
		return (j);
	while (src[i] != '\0')
		i++;
	return ((size_t)(k + i));
}
