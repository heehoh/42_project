NAME = fdf
BONUS_NAME = fdf_bonus

SRCS = ./src/1fdf_main.c \
	   ./src/2fdf_get_map.c \
	   ./src/3fdf_get_map_utils.c \
	   ./src/4fdf_rotate.c \
	   ./src/5fdf_map_draw.c \
	   ./src/6fdf_error_msg.c

BONUS_SRCS = ./src/2fdf_get_map.c \
			 ./src/3fdf_get_map_utils.c \
			 ./src/4fdf_rotate.c \
			 ./src/5fdf_map_draw.c \
			 ./src/6fdf_error_msg.c \
			 ./src/7fdf_main_bonus.c \
			 ./src/8fdf_hook_bonus.c \
			 ./src/9fdf_viewpoint_bonus.c 

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft.a

all : $(NAME)

bonus : $(BONUS_NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	cc $(LIBFT) -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(LIBFT)
	cc $(LIBFT) -lmlx -framework OpenGL -framework Appkit $(BONUS_OBJS) -o $(BONUS_NAME)

clean :
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
.PHONY : clean

fclean : clean
	rm -rf libft/$(LIBFT)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re
