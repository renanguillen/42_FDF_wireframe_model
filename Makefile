NAME = fdf

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libraries/42_libft/

SRCS = $(addprefix $(PATH_SRCS),\
		fdf.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -lX11 -lXext -lmlx
INCLUDES = -I $(PATH_INCLUDES)

REMOVE = rm -rf

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	cc -g $(SRCS) $(MINIFLAGS) -L$(PATH_LIBFT) -lft -o $(NAME)

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	$(REMOVE) $(NAME)

fclean: clean
	make fclean -C $(PATH_LIBFT)

re: fclean all

git:
	git status
	@sleep 1
	@echo 3
	@sleep 1
	@echo 2
	@sleep 1
	@echo 1
	@sleep 2
	git add .
	git commit -m 'automatic commit [Make Git]'
	git push

PHONY: all clean fclean re