/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:41:07 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 14:39:27 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_tex_raycast(t_cub *cub, int x)
{
	int		i;
	int		color;
	t_data	*ch_t;

	i = cub->drawStart - 1;
	ch_t = ft_choose_tex(cub);
	cub->tools.texX = (int)(cub->tools.wallX * (float)(ch_t->width));
	if (cub->tools.side == 0 && cub->tools.rayDirX > 0)
		cub->tools.texX = ch_t->width - cub->tools.texX - 1;
	if (cub->tools.side == 1 && cub->tools.rayDirY < 0)
		cub->tools.texX = ch_t->width - cub->tools.texX - 1;
	cub->tools.step = 1.0 * ch_t->height / cub->lineHeight;
	cub->tools.texPos = (cub->drawStart - cub->r.y / 2 + cub->lineHeight / 2)
		* cub->tools.step;
	while (++i < cub->drawEnd)
	{
		cub->tools.texY = (int) cub->tools.texPos & (ch_t->width - 1);
		cub->tools.texPos += cub->tools.step;
		color = *(int *)(ch_t->addr + (ch_t->line_length * cub->tools.texY
					+ cub->tools.texX * (ch_t->bits_per_pixel / 8)));
		my_mlx_pixel_put(&(cub->img), x, i, color);
	}
	cub->buf_dist[x] = cub->tools.perpWallDist;
}

t_data	*ft_choose_tex(t_cub *cub)
{
	if (cub->tools.side == 1)
	{
		if (cub->tools.mapY < cub->gamer.posY)
			return (&cub->t.no);
		else
			return (&cub->t.so);
	}
	else
	{
		if (cub->tools.mapX < cub->gamer.posX)
			return (&cub->t.we);
		else
			return (&cub->t.ea);
	}
}
