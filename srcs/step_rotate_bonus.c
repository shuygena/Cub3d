/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:09:20 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:13:16 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_up(t_cub *cub)
{
	int	i;
	int	j;

	i = (int)cub->gamer.posY;
	j = (int)(cub->gamer.posX + cub->gamer.dirX * 0.05);
	if (cub->map[i][j] != '1' && cub->map[i][j] != '2')
		cub->gamer.posX += cub->gamer.dirX * 0.05;
	i = (int)(cub->gamer.posY + cub->gamer.dirY * 0.05);
	j = (int)cub->gamer.posX;
	if (cub->map[i][j] != '1' && cub->map[i][j] != '2')
		cub->gamer.posY += cub->gamer.dirY * 0.05;
}

void	ft_down(t_cub *cub)
{
	int	i;
	int	j;

	i = (int)(cub->gamer.posY);
	j = (int)(cub->gamer.posX - cub->gamer.dirX * 0.05);
	if (cub->map[i][j] != '1' && cub->map[i][j] != '2')
		cub->gamer.posX -= cub->gamer.dirX * 0.05;
	i = (int)(cub->gamer.posY - cub->gamer.dirY * 0.05);
	j = (int)(cub->gamer.posX);
	if (cub->map[i][j] != '1' && cub->map[i][j] != '2')
		cub->gamer.posY -= cub->gamer.dirY * 0.05;
}

void	ft_right_rotate(t_cub *cub)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX = cub->gamer.dirX;
	oldPlaneX = cub->gamer.planeX;
	cub->gamer.dirX = cub->gamer.dirX * cos(0.05) - cub->gamer.dirY * sin(0.05);
	cub->gamer.dirY = oldDirX * sin(0.05) + cub->gamer.dirY * cos(0.05);
	cub->gamer.planeX = cub->gamer.planeX * cos(0.05) - cub->gamer.planeY
		* sin(0.05);
	cub->gamer.planeY = oldPlaneX * sin(0.05) + cub->gamer.planeY * cos(0.05);
}

void	ft_left_rotate(t_cub *cub)
{
	float	oldDirX;
	float	oldPlaneX;

	oldDirX = cub->gamer.dirX;
	oldPlaneX = cub->gamer.planeX;
	cub->gamer.dirX = cub->gamer.dirX * cos(-0.05) - cub->gamer.dirY
		* sin(-0.05);
	cub->gamer.dirY = oldDirX * sin(-0.05) + cub->gamer.dirY * cos(-0.05);
	cub->gamer.planeX = cub->gamer.planeX * cos(-0.05) - cub->gamer.planeY
		* sin(-0.05);
	cub->gamer.planeY = oldPlaneX * sin(-0.05) + cub->gamer.planeY * cos(-0.05);
}

void	ft_strafe(int key, t_cub *cub)
{
	float	newDirX;
	float	newDirY;

	newDirX = cub->gamer.dirX * cos(1.570796) - cub->gamer.dirY * sin(1.570796);
	newDirY = cub->gamer.dirX * sin(1.570796) - cub->gamer.dirY * cos(1.570796);
	if (key == 2)
	{
		if (cub->map[(int)cub->gamer.posY][(int)(cub->gamer.posX
			+ newDirX * 0.05)] == '0')
			cub->gamer.posX += newDirX * 0.05;
		if (cub->map[(int)(cub->gamer.posY + newDirY * 0.05)][(int)
				cub->gamer.posX] == '0')
			cub->gamer.posY += newDirY * 0.05;
	}
	if (key == 0)
	{
		if (cub->map[(int)cub->gamer.posY][(int)(cub->gamer.posX - newDirX
			* 0.05)] == '0')
			cub->gamer.posX -= newDirX * 0.05;
		if (cub->map[(int)(cub->gamer.posY - newDirY * 0.05)]
			[(int)cub->gamer.posX] == '0')
			cub->gamer.posY -= newDirY * 0.05;
	}
}
