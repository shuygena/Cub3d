NAME = cub3D

HEADERS = ./headers

SRCSDIR = srcs

SRCS := main.c \
		screenshot.c \
		first_step.c \
		map_review.c \
		map_validate.c \
		parse_settings.c \
		parse_textures.c \
		my_mlx.c \
		raycast.c \
		progress.c \
		sprite_raycast.c \
		tex_raycast.c \
		write_bmp.c \
		crutches.c \
		get_next_line.c \
		get_next_line_utils.c \

SRCS_BONUS = step_rotate_bonus.c

SRCS_MAND = step_rotate.c

OBJS = $(SRCS:%.c=%.o)

OBJS_ADD ?= $(SRCS_MAND:%.c=%.o)

OBJS_REMOVE ?= $(SRCS_BONUS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBS = libft/libft.a mlx/libmlx.a

vpath %.c srcs
vpath %.h headers

all:  $(OBJS_ADD) $(NAME)

bonus:
	make OBJS_ADD:="$(SRCS_BONUS:%.c=%.o)" OBJS_REMOVE:="$(SRCS_MAND:%.c=%.o)"  all

$(NAME): $(LIBS) $(OBJS) $(OBJS_ADD)
	rm -rf $(OBJS_REMOVE)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBS) $(OBJS) $(OBJS_ADD) -o $(NAME)

libft/libft.a: libft/*.c libft.h
	@$(MAKE) -C libft

mlx/libmlx.a: mlx/*.c mlx/*.m mlx.h
	@$(MAKE) -C mlx

%.o: %.c cub3d.h
	$(CC) -c $< $(CFLAGS) -I $(HEADERS) -o $@

clean:
	@echo "Cleaning done"
	@rm -rf $(OBJS) $(OBJS_ADD) $(OBJS_REMOVE)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C mlx


fclean:	clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a
	@rm -rf mlx/libmlx.a

re:			fclean  all

norme:
	@clear
	@norminette headers/libft.h
	@norminette headers/cub3d.h
	@norminette srcs/*.c
	@norminette libft/*.c libft/*.h

.PHONY:		all clean fclean re bonus norme
