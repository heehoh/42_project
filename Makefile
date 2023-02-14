NAME = push_swap
SRCS = ./src/main.c \
	   ./src/nums.c \
	   ./src/o_stack_function.c \
	   ./src/o_stack_function2.c \
	   ./src/operation.c \
	   ./src/operation2.c \
	   ./src/operation3.c \
	   ./src/sort_stack.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
OBJS_FILES = $(addprefix $(OBJ_DIR/, $(OBJS)))

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

all : $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

clean :
	make -C libft clean
	rm -rf $(OBJS_DIR)
.PHONY : clean

fclean : clean
	rm -rf libft/$(LIBFT)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re