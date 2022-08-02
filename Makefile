NAME = fdf

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/

SRCS = $(addprefix $(PATH_SRCS),\
		fdf.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CFLAGS = -lX11 -lXext -lmlx
INCLUDES = -I $(PATH_INCLUDES)

REMOVE = rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	cc $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

PHONY: all clean fclean re