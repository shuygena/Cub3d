/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:57:51 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:32:11 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	resul;
	int			positive;

	positive = 1;
	resul = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		positive = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		resul = resul * 10 + (*str - 48);
		if ((resul > 2147483648) && (positive == -1))
			return (0);
		if ((resul > 2147483647) && (positive == 1))
			return (-1);
		str++;
	}
	return (resul * positive);
}
