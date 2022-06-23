/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crutches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:32:47 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 11:50:41 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}

int	ft_count_params(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_get_texs(t_cub *cub)
{
	char	*path;
	int		res;

	path = ft_strtrim(cub->line + 3, " ");
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".xpm", 4) != 0)
	{
		free(path);
		return (ft_error(2));
	}
	res = ft_png_textures(cub->line, path, cub);
	free(path);
	return (res);
}

int	check_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	ft_check_size(char *path)
{
	int	i;

	i = 0;
	while (path[i] == '0' && path[i] != '\0')
		i++;
	if (ft_strlen(path + i) > 5)
		return (1);
	return (0);
}
