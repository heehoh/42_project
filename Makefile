NAME = push_swap
SRCS = main.c \
	   nums.c \
	   operation.c \
	   operation2.c \
	   operation3.c \
	   print_error.c \
	   set_stack.c \
	   sort_stack.c \
	   stack_function.c \
	   stack_greedy.c
OBJS = $(SRCS:.c=.o)
OBJ_DIR = obj
SRC_DIR = src
OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

all : $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

$(NAME) : $(OBJS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_FILES) -o $(NAME)

clean :
	make -C libft clean
	rm -rf $(OBJ_DIR)
.PHONY : clean

fclean : clean
	rm -rf libft/$(LIBFT)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re