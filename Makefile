NAME = libprint.a
SRCS =
OBJS = $(SRCS: .c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f bonus

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re
