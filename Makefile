NAME = fdf
SRCS = ./src/1fdf_main.c \
	   ./src/2fdf_get_map.c \
	   ./src/3fdf_get_map_utils.c \
	   ./src/4fdf_rotate.c \
	   ./src/5fdf_map_draw.c \
	   ./src/6fdf_error_msg.c  
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	cc $(LIBFT) -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

clean :
	make -C libft clean
	rm -rf $(OBJS)
.PHONY : clean

fclean : clean
	rm -rf libft/$(LIBFT)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re
