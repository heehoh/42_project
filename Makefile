NAME = fdf
SRCS = fdf_main.c \
	   fdf_get_map.c \
	   fdf_line_draw.c \
	   fdf_rotate.c \
	   fdf_error_msg.c  
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	cc -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

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
