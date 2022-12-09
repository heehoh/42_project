NAME = libftprintf.a

SRCS = ft_printf.c\
	   print_type.c\
	   ft_itoa.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	Make -C libft clean
	rm -f $(OBJS)

fclean :
	Make -C libft fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
