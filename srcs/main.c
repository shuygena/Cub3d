/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:29:01 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 12:31:02 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 2)
	{
		cub.vars.mlx = mlx_init();
		if (ft_start_the_party(argv[1], &cub))
			move(&cub);
	}
	else if (argc == 3 && ft_strlen(argv[2]) == 6
		&& ft_strncmp(argv[2], "--save", 6) == 0)
	{
		cub.vars.mlx = mlx_init();
		if (ft_start_the_party(argv[1], &cub))
			ft_save_img(&cub);
	}
	else
		printf("Please write command: ./cub3D validmap.cub [--save]\n");
	return (0);
}
