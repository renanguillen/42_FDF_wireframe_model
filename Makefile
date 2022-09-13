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
		lin_transf.c) \
		$(addprefix $(PATH_SRCS)utils/,\
		found_error.c\
		count_lines.c\
		check_args.c) \
		$(addprefix $(PATH_SRCS)minilib_utils/,\
		put_a_pixel.c\
		bresenham_line_drawing.c\
		handle_x_button.c\
		handle_keypress.c\
		render.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
LFLAGS = -lm -lX11 -lXext -lmlx $(LIBFT)
IFLAGS = -I $(PATH_INCL)

REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)minilib_utils/
	@mkdir -p $(PATH_OBJS)utils/
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
	git checkout main
	git merge branch
	git push
	git branch -d branch
	git checkout -b branch
	clear
	git status

run: all
	./fdf ./test_maps/t2.fdf

vg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./fdf ./test_maps/t2.fdf

PHONY: all clean fclean re