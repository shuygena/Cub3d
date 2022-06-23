/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:25:26 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:32:26 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(number * size);
	if (arr == NULL)
		return (NULL);
	while (i < (number * size))
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
