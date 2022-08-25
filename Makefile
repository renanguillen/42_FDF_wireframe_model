NAME = fdf

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libraries/42_libft/

SRCS = $(addprefix $(PATH_SRCS)main/,\
		main.c\
		write_matrix.c\
		get_arguments.c\
		get_lines.c\
		found_error.c\
		count_lines.c\
		check_args.c\
		htoi.c) \
		$(addprefix $(PATH_SRCS)rend/,\
		img_pix_put.c\
		render_line.c\
		handle_mousekey.c\
		handle_button.c\
		render.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS =  -lm -lX11 -lXext -lmlx $(LIBFT)
IFLAGS = -I $(PATH_INCL)

REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)rend/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	$(REMOVE) $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)

fclean: clean
	$(REMOVE) $(NAME)
	make fclean -C $(PATH_LIBFT)


re: fclean all

git:
	git status
	@sleep 1 && echo 5 && sleep 1 && echo 4 && sleep 1 && echo 3 && sleep 1 && echo 2 && sleep 1 && echo 1 && sleep 2
	git add .
	git commit -m 'automatic commit [Make Git]'
	git push
	clear
	git status

PHONY: all clean fclean re