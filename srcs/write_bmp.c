/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 00:02:36 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 00:03:32 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	write_bitmapinfo(int fd, t_bitmapinfo *info)
{
	if (write(fd, &info->size, sizeof(info->size)) < 0)
		return (0);
	if (write(fd, &info->width, sizeof(info->width)) < 0)
		return (0);
	if (write(fd, &info->height, sizeof(info->height)) < 0)
		return (0);
	if (write(fd, &info->planes, sizeof(info->planes)) < 0)
		return (0);
	if (write(fd, &info->bitcount, sizeof(info->bitcount)) < 0)
		return (0);
	if (write(fd, &info->compression, sizeof(info->compression)) < 0)
		return (0);
	if (write(fd, &info->sizeimage, sizeof(info->sizeimage)) < 0)
		return (0);
	if (write(fd, &info->xpelspermeter, sizeof(info->xpelspermeter)) < 0)
		return (0);
	if (write(fd, &info->ypelspermeter, sizeof(info->ypelspermeter)) < 0)
		return (0);
	if (write(fd, &info->clrused, sizeof(info->clrused)) < 0)
		return (0);
	if (write(fd, &info->clrimportant, sizeof(info->clrimportant)) < 0)
		return (0);
	return (1);
}

static int	write_bitmapfileheader(int fd, t_bitmapfileheader *hdr)
{
	if (write(fd, &hdr->type, sizeof(hdr->type)) < 0)
		return (0);
	if (write(fd, &hdr->size, sizeof(hdr->size)) < 0)
		return (0);
	if (write(fd, &hdr->reserved, sizeof(hdr->reserved)) < 0)
		return (0);
	if (write(fd, &hdr->offset, sizeof(hdr->offset)) < 0)
		return (0);
	return (1);
}

int	ft_write_bmp(int fd, t_bmpfile *bitmap)
{
	if (fd > 0)
	{
		if (!(write_bitmapfileheader(fd, &bitmap->fileheader)))
			return (0);
		if (!(write_bitmapinfo(fd, &bitmap->info)))
			return (0);
		if (write(fd, bitmap->data,
				bitmap->fileheader.size - bitmap->fileheader.offset) < 0)
			return (0);
		return (1);
	}
	return (0);
}
