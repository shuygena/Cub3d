/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_review.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:46:05 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 22:15:02 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_symbol(char c)
{
	if (c == '1')
		return (1);
	if (c == '2')
		return (1);
	if (c == '0')
		return (1);
	if (c == ' ')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (ft_error(7));
}

int	ft_count_hero(char **map)
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
					|| map[i][j] == 'S' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (ft_error(8));
}

int	ft_base_roof(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1')
			return (ft_error(9));
		i++;
	}
	return (1);
}

void	ft_hero_position(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i] != NULL)
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if (cub->map[i][j] == 'S' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				cub->gamer.posX = (float)j + 0.5;
				cub->gamer.posY = (float)i + 0.5;
				ft_vector(cub, cub->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	ft_vector(t_cub *cub, char dir)
{
	if (dir == 'N')
	{
		cub->gamer.dirX = 0.0;
		cub->gamer.dirY = -1.0;
		cub->gamer.planeX = 1 * FOV;
		cub->gamer.planeY = 0.0;
	}
	if (dir == 'S')
	{
		cub->gamer.dirX = 0.0;
		cub->gamer.dirY = 1.0;
		cub->gamer.planeX = -1 * FOV;
		cub->gamer.planeY = 0.0;
	}
	if (dir == 'E' || dir == 'W')
	{
		cub->gamer.dirX = 1.0 - 2 * (dir == 'W');
		cub->gamer.dirY = 0.0;
		cub->gamer.planeX = 0.0;
		cub->gamer.planeY = FOV - 2 * FOV * (dir == 'W');
	}
}
