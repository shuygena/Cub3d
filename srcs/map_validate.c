/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:05:51 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 23:45:29 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_valid_map(char **map, t_cub *cub)
{
	unsigned int	i;
	unsigned int	j;

	cub->sprite_count = 0;
	if (map[0] == NULL)
		return (ft_error(9));
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '2')
				cub->sprite_count++;
			if (ft_check_symbol(map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (ft_count_hero(map) == 0 || ft_check_spaces(map) == 0)
		return (0);
	return (1);
}

int	ft_check_spaces(char **map)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	if (ft_base_roof(map[0]) == 0)
		return (0);
	while (map[i + 1] != NULL)
	{
		if (ft_check_frame(map[i]) == 0)
			return (0);
		j = 1;
		while (map[i][j + 1] != '\0')
		{
			if ((map[i][j] != ' ' && map[i][j] != '1')
				&& (ft_strlen(map[i - 1]) <= j || ft_strlen(map[i + 1]) <= j))
				return (ft_error(9));
			if (ft_check_around(i, j, map) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (ft_base_roof(map[i]));
}

int	ft_check_around(unsigned int i, unsigned int j, char **map)
{
	if (map[i][j] == '1' || map[i][j] == ' ')
		return (1);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (ft_error(9));
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (ft_error(9));
	return (1);
}

int	ft_check_frame(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '1')
	{
		if (str[i] != ' ')
			return (ft_error(9));
		i++;
	}
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] != '1')
	{
		if (str[i] != ' ')
			return (ft_error(9));
		i--;
	}
	return (1);
}

int	ft_check_n(char *map_str)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(map_str) && map_str[i] == '\n')
		i++;
	while (i < ft_strlen(map_str) - 1)
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			return (ft_error(7));
		i++;
	}
	return (1);
}
