/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:41:55 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 12:55:25 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_settings(t_cub *cub)
{
	if ((*cub).line[0] == 'F' || (*cub).line[0] == 'C')
	{
		if (ft_init_rgb(cub))
			return (1);
		return (0);
	}
	if (ft_strncmp(cub->line, "R ", 2) == 0)
		return (ft_screen_size(cub));
	if (ft_strncmp(cub->line, "SO ", 3) == 0
		|| ft_strncmp(cub->line, "NO ", 3) == 0
		|| ft_strncmp(cub->line, "WE ", 3) == 0
		|| ft_strncmp(cub->line, "EA ", 3) == 0)
		return (ft_get_texs(cub));
	if (ft_strncmp(cub->line, "S ", 2) == 0)
		return (ft_init_sprite(cub));
	return (ft_error(6));
}

int	ft_screen_size(t_cub *cub)
{
	char	**size;

	size = ft_split(cub->line, ' ');
	if (ft_count_params(size) != 3)
	{
		free_tab(size);
		return (ft_error(10));
	}
	if (ft_check_digit_in_str(size[1]) == 0
		|| ft_check_digit_in_str(size[2]) == 0)
	{
		free_tab(size);
		return (ft_error(4));
	}
	(*cub).r.x = ft_atoi(size[1]);
	(*cub).r.y = ft_atoi(size[2]);
	if (ft_check_size(size[1]) || cub->r.x > cub->maX)
		cub->r.x = cub->maX;
	if (ft_check_size(size[2]) || cub->r.y > cub->maY)
		cub->r.y = cub->maY;
	free_tab(size);
	if ((*cub).r.x <= 0 || (*cub).r.y <= 0)
		return (ft_error(4));
	return (1);
}

int	ft_init_rgb(t_cub *cub)
{
	char	**colors;

	if (check_line(cub->line) == 0)
		return (ft_error(5));
	colors = ft_split((*cub).line, ',');
	if (ft_count_params(colors) != 3 )
	{
		free_tab(colors);
		return (ft_error(5));
	}
	if ((*cub).line[0] == 'F')
	{
		(*cub).f.red = ft_get_rgb((colors[0] + 1));
		(*cub).f.green = ft_get_rgb(colors[1]);
		(*cub).f.blue = ft_get_rgb(colors[2]);
	}
	if ((*cub).line[0] == 'C')
	{
		(*cub).c.red = ft_get_rgb((colors[0] + 1));
		(*cub).c.green = ft_get_rgb(colors[1]);
		(*cub).c.blue = ft_get_rgb(colors[2]);
	}
	free_tab(colors);
	return (1);
}

int	ft_get_rgb(char *str)
{
	char	*color;
	int		rgb;

	color = ft_strtrim(str, " ");
	if (ft_strlen(color) > 3)
	{
		free(color);
		return (-1);
	}
	if (ft_check_digit_in_str(color) == 0)
	{
		free(color);
		return (-1);
	}
	rgb = ft_atoi(color);
	if (rgb > 255 || rgb < 0)
	{
		free(color);
		return (-1);
	}
	free(color);
	return (rgb);
}

int	ft_check_digit_in_str(char *str)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
