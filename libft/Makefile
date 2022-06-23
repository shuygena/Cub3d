NAME = libft.a
INCLUDES = libft.h
DEFS = 		ft_atoi.c \
            ft_calloc.c \
            ft_isdigit.c \
            ft_strjoin.c\
            ft_strchr.c \
            ft_strdup.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strtrim.c\
            ft_substr.c \
            ft_split.c \
            ft_strrchr.c \
            ft_memcpy.c \

OBJS = $(DEFS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES)
	gcc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
