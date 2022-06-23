/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:33:47 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 17:13:05 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite_raycast(t_cub *cub) //there is bug
{
	int	i;

	i = -1;
	ft_s_dist(cub);
	ft_sort(cub);
	while (++i < cub->sprite_count)
	{
		cub->sprite.x = cub->sprite.sprites[i].sX - cub->gamer.posX;
		cub->sprite.y = cub->sprite.sprites[i].sY - cub->gamer.posY;
		cub->sprite.invDet = 1.0 / (cub->gamer.planeX * cub->gamer.dirY
				- cub->gamer.dirX * cub->gamer.planeY);
		cub->sprite.tX = cub->sprite.invDet * (cub->gamer.dirY * cub->sprite.x
				- cub->gamer.dirX * cub->sprite.y);
		cub->sprite.tY = cub->sprite.invDet * (-cub->gamer.planeY
				* cub->sprite.x + cub->gamer.planeX * cub->sprite.y);
		cub->sprite.ssX = (int)((cub->r.x / 2) * (1 + cub->sprite.tX
					/ cub->sprite.tY));
		cub->sprite.h = abs((int)(cub->r.x * FOV / cub->sprite.tY));
		cub->sprite.w = abs((int)(cub->r.x * FOV / cub->sprite.tY));
		ft_sprites_calculate(cub);
	}
}

void	ft_sort(t_cub *cub)
{
	int		i;
	t_arr	tmp;

	i = 0;
	while (++i < cub->sprite_count)
	{
		if (cub->sprite.sprites[i].dist > cub->sprite.sprites[i - 1].dist)
		{
			tmp = cub->sprite.sprites[i];
			cub->sprite.sprites[i] = cub->sprite.sprites[i - 1];
			cub->sprite.sprites[i - 1] = tmp;
		}
	}
}

void	ft_sprites_calculate(t_cub *cub)
{
	cub->sprite.dsY = -cub->sprite.h / 2 + cub->r.y / 2;
	if (cub->sprite.dsY < 0)
		cub->sprite.dsY = 0;
	cub->sprite.deY = cub->sprite.h / 2 + cub->r.y /2;
	if (cub->sprite.deY >= cub->r.y)
		cub->sprite.deY = cub->r.y - 1;
	cub->sprite.dsX = -cub->sprite.w / 2 + cub->sprite.ssX;
	if (cub->sprite.dsX < 0)
		cub->sprite.dsX = 0;
	cub->sprite.deX = cub->sprite.w / 2 + cub->sprite.ssX;
	if (cub->sprite.deX >= cub->r.x)
		cub->sprite.deX = cub->r.x - 1;
	ft_sprite_cicle(cub, &(cub->sprite));
}

void	ft_sprite_cicle(t_cub *cub, t_sprite *s)
{
	int	i;
	int	j;
	int	texX;
	int	texY;
	int	d;

	i = s->dsX - 1;
	while (++i < s->deX)
	{
		j = s->dsY - 1;
		texX = (int)((i - (-s->w / 2 + s->ssX)) * s->s.width / s->w);
		if (s->tY > 0 && i > 0 && i < cub->r.x && s->tY < cub->buf_dist[i])
		{
			while (++j < cub->sprite.deY)
			{
				d = j * 2 - cub->r.y + cub->sprite.h;
				texY = ((d * cub->sprite.s.height) / cub->sprite.h) / 2;
				d = *(int *)(s->s.addr + (s->s.line_length
							* texY + texX * (s->s.bits_per_pixel / 8)));
				if ((d & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&(cub->img), i, j, d);
			}
		}
	}
}

void	ft_init_array_sprites(t_cub *cub, int i, int j, int index)
{
	float	x;
	float	y;

	x = j + 0.5;
	y = i + 0.5;
	cub->sprite.sprites[index].sX = x;
	cub->sprite.sprites[index].sY = y;
	cub->sprite.sprites[index].dist = pow((x - cub->gamer.posX), 2)
		+ pow((y - cub->gamer.posY), 2);
}
