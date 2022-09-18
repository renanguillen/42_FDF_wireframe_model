NAME = fdf

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libraries/42_libft/

SRCS = $(addprefix $(PATH_SRCS), fdf.c) \
		$(addprefix $(PATH_SRCS)map_handle/,\
		get_each_point.c\
		set_dot_struct.c\
		get_lines.c\
		linear_transformation.c\
		check_args.c\
		found_error.c\
		count_lines.c\
		free_data.c) \
		$(addprefix $(PATH_SRCS)img_handle/,\
		put_a_pixel.c\
		bresenham_line_drawing.c\
		draw_image.c\
		clear_window.c) \
		$(addprefix $(PATH_SRCS)win_handle/,\
		handle_hooks.c\
		handle_keypress.c\
		handle_x_button.c\
		win_initialization.c)


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
	@mkdir -p $(PATH_OBJS)map_handle/
	@mkdir -p $(PATH_OBJS)img_handle/
	@mkdir -p $(PATH_OBJS)win_handle/
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
	clear
	git status

t1: all
	./fdf ./test_maps/t1.fdf

t2: all
	./fdf ./test_maps/t2.fdf

julia: all
	./fdf ./test_maps/julia.fdf

fract: all
	./fdf ./test_maps/elem-fract.fdf

42: all
	./fdf ./test_maps/42.fdf

mars: all
	./fdf ./test_maps/mars.fdf

vg:
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf ./test_maps/t2.fdf

n:
	@clear
	@norminette ./sources

PHONY: all clean fclean re