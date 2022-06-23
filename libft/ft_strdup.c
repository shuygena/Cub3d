/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:28 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:33:09 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*pstr;
	char	*duble_string;
	int		len;
	int		i;

	len = 0;
	i = 0;
	pstr = (char *)str;
	while (pstr[len] != '\0')
		len++;
	duble_string = (char *)malloc(len + 1);
	if (duble_string == NULL)
		return (NULL);
	while (i < len)
	{
		duble_string[i] = pstr[i];
		i++;
	}
	duble_string[len] = '\0';
	return (duble_string);
}
