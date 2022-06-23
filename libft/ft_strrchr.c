/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:11:05 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:34:23 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int		last_index;
	int		i;
	char	*pstr;

	i = 0;
	last_index = -1;
	pstr = (char *)str;
	while (str[i] != '\0')
	{
		if (str[i] == symbol)
			last_index = i;
		i++;
	}
	if (symbol == '\0')
		last_index = i;
	if (last_index >= 0)
		return (pstr + last_index);
	else
		return (NULL);
}
