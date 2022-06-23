/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:08:03 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 15:20:01 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_cub *cub)
{
	cub->vars.win = mlx_new_window(cub->vars.mlx, cub->r.x, cub->r.y, "cub3d");
	cub->img.img = mlx_new_image(cub->vars.mlx, cub->r.x, cub->r.y);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->buf_dist = (float *)malloc(cub->r.x * sizeof(float));
	ft_raycast_main(cub);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->img.img, 0, 0);
	mlx_hook(cub->vars.win, 17, 1L << 1, key_close, cub);
	mlx_hook(cub->vars.win, 2, 1L << 0, key_hook, cub);
	mlx_loop(cub->vars.mlx);
}

int	key_hook(int key, t_cub *cub)
{
	if (key == 126 || key == 13)
		ft_up(cub);
	if (key == 125 || key == 1)
		ft_down(cub);
	if (key == 124)
		ft_right_rotate(cub);
	if (key == 123)
		ft_left_rotate(cub);
	if (key == 53)
	{
		mlx_destroy_window(cub->vars.mlx, cub->vars.win);
		exit(0);
	}
	ft_strafe(key, cub);
	ft_raycast_main(cub);
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->img.img, 0, 0);
	return (1);
}

void	ft_get_sprites(t_cub *cub)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	if (cub->sprite_count > 0)
		cub->sprite.sprites = (t_arr *)malloc(cub->sprite_count
				* sizeof(t_arr));
	while (cub->map[i] != NULL)
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if (cub->map[i][j] == '2' && index < cub->sprite_count)
			{
				ft_init_array_sprites(cub, i, j, index);
				index++;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_colors(t_cub *cub)
{
	cub->c.color = 0;
	cub->f.color = 0;
	cub->c.color = (cub->c.red << 16) + (cub->c.green << 8) + cub->c.blue;
	cub->f.color = (cub->f.red << 16) + (cub->f.green << 8) + cub->f.blue;
}

void	ft_s_dist(t_cub *cub)
{
	int		i;
	float	x;
	float	y;

	i = -1;
	while (++i < cub->sprite_count)
	{
		x = pow((cub->gamer.posX - cub->sprite.sprites[i].sX), 2);
		y = pow((cub->gamer.posY - cub->sprite.sprites[i].sY), 2);
		cub->sprite.sprites[i].dist = x + y;
	}
}
