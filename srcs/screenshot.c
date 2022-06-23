/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:03:17 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 00:00:36 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save_img(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->vars.mlx, cub->r.x, cub->r.y);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->img.width = cub->r.x;
	cub->img.height = cub->r.y;
	cub->buf_dist = (float *)malloc(cub->r.x * sizeof(float));
	ft_raycast_main(cub);
	ft_screenshot(cub);
}

static void	set_bmp_info_from_image(t_bitmapinfo *info, t_data *data)
{
	info->size = BMP_SIZEOFINFO;
	info->width = data->width;
	info->height = -data->height;
	info->planes = BMP_PLANES;
	info->bitcount = BMP_BITPERPIXEL;
	info->compression = BMP_COMPRESSION;
	info->sizeimage = BMP_SIZEIMAGE;
	info->xpelspermeter = BMP_XPELSPERMETER;
	info->ypelspermeter = BMP_YPELSPERMETER;
	info->clrused = BMP_CLRUSED;
	info->clrimportant = BMP_CLRIMPORTANT;
}

static void	set_bmp_data_from_image(t_bmpfile *bmp, t_data *data)
{
	ft_memcpy(bmp->fileheader.type, BMP_IDENTIFIER, sizeof(BMP_IDENTIFIER));
	bmp->fileheader.size = data->width * data->height * BMP_BYTEPERPIXEL
		+ BMP_SIZEOFHEADER;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.offset = BMP_SIZEOFHEADER;
	set_bmp_info_from_image(&bmp->info, data);
	bmp->data = data->addr;
}

void	ft_screenshot(t_cub *cub)
{
	int			fd;
	t_bmpfile	bmp_data;

	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (fd < 0)
		ft_error(1);
	set_bmp_data_from_image(&bmp_data, &cub->img);
	if (!(ft_write_bmp(fd, &bmp_data)))
		ft_error(3);
	close(fd);
}

int	key_close(t_cub *cub)
{
	mlx_destroy_window(cub->vars.mlx, cub->vars.win);
	exit(0);
}
