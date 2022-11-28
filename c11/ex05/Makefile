NAME = do-op
OBJS = srcs/main.o srcs/ft_atoi.o srcs/operator.o

INC = includes 

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME) 
re : fclean all

.PHONY : all clean fclean re
