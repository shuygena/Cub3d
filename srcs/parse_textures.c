/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:04:30 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 14:08:20 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_png_textures(char *name, char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(6));
	close(fd);
	if (name[0] == 'S' && name[1] == 'O')
	{
		cub->t.so.img = mlx_xpm_file_to_image(cub->vars.mlx, path,
				&(cub->t.so.width), &(cub->t.so.height));
		cub->t.so.addr = mlx_get_data_addr(cub->t.so.img,
				&cub->t.so.bits_per_pixel, &cub->t.so.line_length,
				&cub->t.so.endian);
		return (1);
	}
	if (name[0] == 'N' && name[1] == 'O')
	{
		cub->t.no.img = mlx_xpm_file_to_image(cub->vars.mlx, path,
				&(cub->t.no.width), &(cub->t.no.height));
		cub->t.no.addr = mlx_get_data_addr(cub->t.no.img,
				&cub->t.no.bits_per_pixel, &cub->t.no.line_length,
				&cub->t.no.endian);
		return (1);
	}
	return (ft_continue_tex(name, path, cub));
}

int	ft_continue_tex(char *name, char *path, t_cub *cub)
{
	if (name[0] == 'W' && name[1] == 'E')
	{
		cub->t.we.img = mlx_xpm_file_to_image(cub->vars.mlx, path,
				&(cub->t.we.width), &(cub->t.we.height));
		cub->t.we.addr = mlx_get_data_addr(cub->t.we.img,
				&cub->t.we.bits_per_pixel, &cub->t.we.line_length,
				&cub->t.we.endian);
		return (1);
	}
	if (name[0] == 'E' && name[1] == 'A')
	{
		cub->t.ea.img = mlx_xpm_file_to_image(cub->vars.mlx, path,
				&(cub->t.ea.width), &(cub->t.ea.height));
		cub->t.ea.addr = mlx_get_data_addr(cub->t.ea.img,
				&cub->t.ea.bits_per_pixel, &cub->t.ea.line_length,
				&cub->t.ea.endian);
		return (1);
	}
	return (ft_error(6));
}

int	ft_init_sprite(t_cub *cub)
{
	int		fd;
	char	*path;

	path = ft_strtrim(cub->line + 2, " ");
	fd = open(path, O_RDONLY);
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".xpm", 4) != 0)
	{
		free(path);
		return (ft_error(6));
	}
	if (fd == -1)
	{
		free(path);
		return (ft_error(6));
	}
	cub->sprite.s.img = mlx_xpm_file_to_image(cub->vars.mlx, path,
			&(cub->sprite.s.width), &(cub->sprite.s.height));
	cub->sprite.s.addr = mlx_get_data_addr(cub->sprite.s.img,
			&cub->sprite.s.bits_per_pixel, &cub->sprite.s.line_length,
			&cub->sprite.s.endian);
	free(path);
	return (1);
}

int	ft_check_head(t_cub *cub)
{
	if ((*cub).t.so.img != NULL && (*cub).t.no.img != NULL
		&& (*cub).f.green > -1 && (*cub).f.red > -1
		&& (*cub).t.ea.img != NULL && (*cub).t.we.img != NULL
		&& (*cub).c.red > -1 && (*cub).r.x > 0 && (*cub).r.y > 0
		&& (*cub).f.blue > -1 && (*cub).sprite.s.img != NULL
		&& (*cub).c.green > -1 && (*cub).c.blue > -1)
		return (1);
	ft_error(10);
	return (0);
}

void	ft_init_int(t_cub *cub)
{
	mlx_get_screen_size(&cub->maX, &cub->maY);
	(*cub).r.x = -1;
	(*cub).r.y = -1;
	(*cub).f.red = -1;
	(*cub).f.green = -1;
	(*cub).f.blue = -1;
	(*cub).c.red = -1;
	(*cub).c.green = -1;
	(*cub).c.blue = -1;
}
