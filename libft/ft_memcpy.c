/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:02:44 by mskeleto          #+#    #+#             */
/*   Updated: 2020/11/09 19:51:07 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*psrc;
	char	*pdest;

	i = 0;
	psrc = (char *)src;
	pdest = (char *)dest;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (n--)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
