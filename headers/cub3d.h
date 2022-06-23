/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:08:20 by mskeleto          #+#    #+#             */
/*   Updated: 2021/04/28 15:01:06 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BMP_IDENTIFIER		"BM"
# define BMP_BYTEPERPIXEL	4
# define BMP_SIZEOFHEADER	54
# define BMP_SIZEOFINFO		40
# define BMP_RESERVED		0
# define BMP_PLANES			1
# define BMP_BITPERPIXEL	32
# define BMP_COMPRESSION	0
# define BMP_SIZEIMAGE		0
# define BMP_XPELSPERMETER	0
# define BMP_YPELSPERMETER	0
# define BMP_CLRUSED		0
# define BMP_CLRIMPORTANT	0
# define FOV                0.75

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t number, size_t size);
char	*ft_dup(const char *str);
char	*ft_strjon(char *s1, char *s2);
int		ft_nsymbol(char *str);
int		ft_result(int status);
int		ft_check_remain(char ***line, char **remain);
int		get_next_line(int fd, char **line);
int		ft_zero(char *buffer, int i);
size_t	ft_strlen(const char *s);

typedef struct s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bitmapfileheader;

typedef struct s_bitmapinfo
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitcount;
	int		compression;
	int		sizeimage;
	int		xpelspermeter;
	int		ypelspermeter;
	int		clrused;
	int		clrimportant;
}				t_bitmapinfo;

typedef struct s_bmpfile
{
	t_bitmapfileheader	fileheader;
	t_bitmapinfo		info;
	char				*data;
}				t_bmpfile;

typedef struct s_render
{
	int	x;
	int	y;
}				t_render;

typedef struct s_arr
{
	float	sX;
	float	sY;
	float	dist;
}				t_arr;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_sprite
{
	t_data	s;
	t_arr	*sprites;
	int		w;
	int		h;
	float	x;
	float	y;
	float	invDet;
	float	tX;
	float	tY;
	int		ssX;
	int		dsY;
	int		deY;
	int		dsX;
	int		deX;
}				t_sprite;

typedef struct s_texture
{
	t_data		so;
	t_data		no;
	t_data		we;
	t_data		ea;
}					t_texture;

typedef struct s_rgb
{
	int	color;
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_gamer
{
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
}				t_gamer;

typedef struct s_tools
{
	float	cameraX;
	float	rayDirX;
	float	rayDirY;
	int		mapX;
	int		mapY;
	float	sideDistX;
	float	sideDistY;
	float	perpWallDist;
	float	deltaDistX;
	float	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		texX;
	int		texY;
	float	texPos;
	float	step;
	float	wallX;
}			t_tools;

typedef struct s_keys
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	A;
	int	S;
	int	W;
	int	D;
}				t_keys;

typedef struct s_cub
{
	int				limit;
	char			*line;
	t_render		r;
	t_rgb			f;
	t_rgb			c;
	t_texture		t;
	char			*map_str;
	char			**map;
	t_sprite		sprite;
	t_vars			vars;
	t_data			img;
	t_gamer			gamer;
	t_tools			tools;
	int				drawStart;
	int				drawEnd;
	int				lineHeight;
	int				sprite_count;
	float			*buf_dist;
	t_keys			key;
	int				maX;
	int				maY;
}					t_cub;

int		ft_start_the_party(char *file, t_cub *cub);
int		ft_data_processing(int fd, t_cub *cub);
int		ft_parse_str(t_cub *cub);
int		ft_check_file_name(char *file);
int		ft_parse_settings(t_cub *cub);
int		ft_screen_size(t_cub *cub);
int		ft_init_rgb(t_cub *cub);
int		ft_get_rgb(char *str);
int		ft_check_digit_in_str(char *str);
int		ft_png_textures(char *name, char *path, t_cub *cub);
int		ft_init_sprite(t_cub *cub);
int		ft_check_head(t_cub *cub);
int		ft_valid_map(char **map, t_cub *cub);
int		ft_check_n(char *map_str);
int		ft_error(int flag);
void	ft_init_int(t_cub *cub);
int		ft_check_spaces(char **map);
int		ft_check_around(unsigned int i, unsigned int j, char **map);
int		ft_check_frame(char *str);
int		ft_check_n(char *map_str);
int		ft_check_symbol(char c);
int		ft_count_hero(char **map);
int		ft_base_roof(char *str);
void	ft_draw_2d_map(t_cub *cub);
void	ft_draw_pixel(t_cub *cub, float y, float x);
void	ft_draw_gamer(t_cub *cub, float y, float x);
int		key_hook(int key, t_cub *cub);
void	move(t_cub *cub);
void	drow_map(t_cub *cub);
void	ft_clear(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_hero_position(t_cub *cub);
void	ft_raycast_main(t_cub *cub);
void	ft_init_tools(t_cub *cub, int x, int w);
void	ft_calculate(t_cub *cub);
void	ft_jump(t_cub *cub);
void	ft_side(t_cub *cub);
void	ft_draw_line(int x, int drawStart, int drawEnd, t_cub *cub);
void	ft_vector(t_cub *cub, char dir);
void	ft_up(t_cub *cub);
void	ft_down(t_cub *cub);
void	ft_right_rotate(t_cub *cub);
void	ft_left_rotate(t_cub *cub);
void	ft_strafe(int key, t_cub *cub);
void	ft_tex_raycast(t_cub *cub, int x);
int		ft_continue_tex(char *name, char *path, t_cub *cub);
t_data	*ft_choose_tex(t_cub *cub);
void	ft_sprite_raycast(t_cub *cub);
void	ft_init_array_sprites(t_cub *cub, int i, int j, int index);
void	ft_get_sprites(t_cub *cub);
void	ft_sort(t_cub *cub);
void	ft_s_dist(t_cub *cub);
void	ft_sprites_calculate(t_cub *cub);
void	ft_sprite_cicle(t_cub *cub, t_sprite *s);
void	ft_get_colors(t_cub *cub);
void	ft_save_img(t_cub *cub);
void	ft_screenshot(t_cub *cub);
int		ft_write_bmp(int fd, t_bmpfile *bitmap);
void	ft_img_file(t_cub *cub, int fd);
void	ft_write_img(t_cub *cub, int fd);
int		key_close(t_cub *cub);
void	free_tab(char **tab);
int		ft_get_texs(t_cub *cub);
int		ft_count_params(char **tab);
int		check_line(char *str);
int		ft_check_size(char *path);

#endif
