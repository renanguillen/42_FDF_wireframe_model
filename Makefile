NAME = fdf

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libraries/42_libft/

SRCS = $(addprefix $(PATH_SRCS),\
		fdf.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CFLAGS = -lX11 -lXext -lmlx
INCLUDES = -I $(PATH_INCLUDES)

REMOVE = rm -rf

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	cc $(LIBFT) $(SRCS) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	$(REMOVE) $(NAME)

fclean: clean
	make fclean -C $(PATH_LIBFT)

re: fclean all

PHONY: all clean fclean re