/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:48:06 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 17:12:42 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_side(t_cub *cub)
{
	if (cub->tools.rayDirX < 0)
	{
		cub->tools.stepX = -1;
		cub->tools.sideDistX = (cub->gamer.posX - cub->tools.mapX)
			* cub->tools.deltaDistX;
	}
	else
	{
		cub->tools.stepX = 1;
		cub->tools.sideDistX = (cub->tools.mapX + 1.0 - cub->gamer.posX)
			* cub->tools.deltaDistX;
	}
	if (cub->tools.rayDirY < 0)
	{
		cub->tools.stepY = -1;
		cub->tools.sideDistY = (cub->gamer.posY - cub->tools.mapY)
			* cub->tools.deltaDistY;
	}
	else
	{
		cub->tools.stepY = 1;
		cub->tools.sideDistY = (cub->tools.mapY + 1.0 - cub->gamer.posY)
			* cub->tools.deltaDistY;
	}
}

void	ft_jump(t_cub *cub)
{
	cub->tools.hit = 0;
	while (cub->tools.hit == 0)
	{
		if (cub->tools.sideDistX < cub->tools.sideDistY)
		{
			cub->tools.sideDistX += cub->tools.deltaDistX;
			cub->tools.mapX += cub->tools.stepX;
			cub->tools.side = 0;
		}
		else
		{
			cub->tools.sideDistY += cub->tools.deltaDistY;
			cub->tools.mapY += cub->tools.stepY;
			cub->tools.side = 1;
		}
		if (cub->map[cub->tools.mapY][cub->tools.mapX] == '1')
			cub->tools.hit = 1;
	}
}

void	ft_calculate(t_cub *cub)
{
	if (cub->tools.side == 0)
		cub->tools.perpWallDist = (cub->tools.mapX - cub->gamer.posX
				+ (1 - cub->tools.stepX) / 2) / cub->tools.rayDirX;
	else
		cub->tools.perpWallDist = (cub->tools.mapY - cub->gamer.posY
				+ (1 - cub->tools.stepY) / 2) / cub->tools.rayDirY;
	cub->lineHeight = (int)(cub->r.x * FOV / cub->tools.perpWallDist);
	cub->drawStart = (-1 * cub->lineHeight) / 2 + cub->r.y / 2;
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = cub->lineHeight / 2 + cub->r.y / 2;
	if (cub->drawEnd >= cub->r.y)
		cub->drawEnd = cub->r.y - 1;
	if (cub->tools.side == 0)
		cub->tools.wallX = cub->gamer.posY + cub->tools.perpWallDist
			* cub->tools.rayDirY;
	else
		cub->tools.wallX = cub->gamer.posX + cub->tools.perpWallDist
			* cub->tools.rayDirX;
	cub->tools.wallX -= floor((cub->tools.wallX));
}

void	ft_init_tools(t_cub *cub, int x, int w)
{
	cub->tools.cameraX = 2 * x / (float)w - 1;
	cub->tools.rayDirX = cub->gamer.dirX + cub->gamer.planeX
		* cub->tools.cameraX;
	cub->tools.rayDirY = cub->gamer.dirY + cub->gamer.planeY
		* cub->tools.cameraX;
	cub->tools.mapX = (int)cub->gamer.posX;
	cub->tools.mapY = (int)cub->gamer.posY;
	cub->tools.deltaDistX = fabsf(1 / cub->tools.rayDirX);
	cub->tools.deltaDistY = fabsf(1 / cub->tools.rayDirY);
	ft_side(cub);
	ft_jump(cub);
	ft_calculate(cub);
	ft_tex_raycast(cub, x);
}

void	ft_raycast_main(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->r.x)
	{
		ft_init_tools(cub, x, cub->r.x);
		ft_draw_line(x, cub->drawStart, cub->drawEnd, cub);
		x++;
	}
	ft_sprite_raycast(cub);
}
