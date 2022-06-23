/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:35:05 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:32:54 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	int		i;
	char	*pstr;

	i = 0;
	pstr = (char *)str;
	while ((str[i] != '\0') && (str[i] != symbol))
		i++;
	if (str[i] == symbol)
		return (pstr + i);
	else
		return (NULL);
}
