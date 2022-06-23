/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:00:12 by mskeleto          #+#    #+#             */
/*   Updated: 2020/11/11 15:00:36 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	index;

	if (s1 == NULL)
		return (NULL);
	index = 0;
	str = (ft_calloc(((ft_strlen(s1) + ft_strlen(s2) + 1)), sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		str[index] = *s1;
		s1++;
		index++;
	}
	while (*s2)
	{
		str[index] = *s2;
		s2++;
		index++;
	}
	return (str);
}
