NAME = pipex

SRCS = ./src/pipex_main.c \
	   ./src/pipex_set_cmd.c \
	   ./src/pipex_process.c \
	   ./src/pipex_free.c \
	   ./src/pipex_error_msg.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(LIBFT) $(OBJS) -o $(NAME)

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