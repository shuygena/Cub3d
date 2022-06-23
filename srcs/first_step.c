/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:28:53 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/27 23:37:31 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int flag)
{
	printf("Error\n");
	if (flag == 1)
		printf("Error in open\n");
	if (flag == 2)
		printf("Bad type of file\n");
	if (flag == 3)
		printf("Error in read/write \n");
	if (flag == 4)
		printf("Bad size\n");
	if (flag == 5)
		printf("Error in RGB\n");
	if (flag == 6)
		printf("Trash before map\n");
	if (flag == 7)
		printf("Trash in map\n");
	if (flag == 8)
		printf("Bad count hero\n");
	if (flag == 9)
		printf("Bad map\n");
	if (flag == 10)
		printf("Error before map\n");
	return (0);
}

int	ft_start_the_party(char *file, t_cub *cub)
{
	int	fd;

	if (ft_check_file_name(file) == 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error(1));
	if (!(ft_data_processing(fd, cub)))
	{
		close(fd);
		return (0);
	}
	ft_get_sprites(cub);
	ft_get_colors(cub);
	return (1);
}

int	ft_data_processing(int fd, t_cub *cub)
{
	int	status;

	status = get_next_line(fd, &(cub->line));
	cub->limit = 0;
	cub->map_str = (char *)malloc(1);
	(cub->map_str)[0] = '\0';
	ft_init_int(cub);
	while (status == 1)
	{
		if (!(ft_parse_str(cub)))
			return (0);
		free(cub->line);
		cub->line = NULL;
		status = get_next_line(fd, &(cub->line));
	}
	if (status == -1)
		return (ft_error(3));
	else if (!(ft_parse_str(cub)))
		return (0);
	cub->map = ft_split(cub->map_str, '\n');
	if (!(ft_valid_map(cub->map, cub) && ft_check_head(cub)
			&& ft_check_n(cub->map_str)))
		return (0);
	ft_hero_position(cub);
	return (1);
}

int	ft_parse_str(t_cub *cub)
{
	char	*tmp;

	while (cub->limit < 8)
	{
		if (cub->line[0] == '\0')
			return (1);
		if (cub->line[0] == ' ')
			return (ft_error(6));
		if (ft_parse_settings(cub) == 0)
			return (0);
		cub->limit++;
		return (1);
	}
	tmp = cub->map_str;
	cub->map_str = ft_strjoin(cub->map_str, cub->line);
	free(tmp);
	tmp = cub->map_str;
	cub->map_str = ft_strjoin(cub->map_str, "\n");
	free(tmp);
	return (1);
}

int	ft_check_file_name(char *file)
{
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".cub", 4) == 0)
		return (1);
	return (ft_error(2));
}
