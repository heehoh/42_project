NAME = libftprintf.a

SRCS = ft_printf.c\
	   print_type.c\
	   utils.c\
	   ft_itoa.c

OBJS = $(SRCS:.c=.o)

INC = .

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	Make -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
