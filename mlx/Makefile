#
#

NAME=libmlx.a
SRC= mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m mlx_get_screen_size.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-w -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ) mlx.h
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
