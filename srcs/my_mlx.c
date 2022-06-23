/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:29:10 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 23:48:14 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(int x, int drawStart, int drawEnd, t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < drawStart)
		my_mlx_pixel_put(&(cub->img), x, i, cub->c.color);
	drawEnd--;
	while (++drawEnd < cub->r.y)
		my_mlx_pixel_put(&(cub->img), x, drawEnd, cub->f.color);
}

void	ft_black_img(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < cub->r.y)
	{
		while (j++ < cub->r.x)
			my_mlx_pixel_put(&(cub->img), j, i, 0x000000000);
	}
}
