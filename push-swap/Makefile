NAME = push_swap
BONUS_NAME = checker
SRCS = main.c \
	   nums.c \
	   operation.c \
	   operation2.c \
	   operation3.c \
	   print_error.c \
	   set_stack.c \
	   sort_stack.c \
	   stack_function.c \
	   stack_greedy.c \
	   stack_greedy_utils.c

BNS_SRCS = main_bonus.c \
		   new_argv_bonus.c \
		   operation2_bonus.c \
		   operation3_bonus.c \
		   operation_bonus.c \
		   print_error_bonus.c \
		   set_stack_bonus.c \
		   sort_stack_bonus.c \
		   stack_function_bonus.c

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

OBJ_DIR = obj
BNS_OBJ_DIR = bonus_obj

SRC_DIR = src
BNS_SRC_DIR = bonus

OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))
BNS_OBJS_FILES = $(addprefix $(BNS_OBJ_DIR)/, $(BNS_OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lft -Llibft

LIBFT = libft/libft.a

all : $(NAME)

bonus : $(BONUS_NAME)

$(LIBFT) :
	make -C libft

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
$(BNS_OBJ_DIR) :
	mkdir -p $(BNS_OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BNS_OBJ_DIR)/%.o : $(BNS_SRC_DIR)/%.c | $(BNS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS_FILES) -o $(NAME)

$(BONUS_NAME) : $(BNS_OBJS_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LFLAGS) $(BNS_OBJS_FILES) -o $(BONUS_NAME)

clean :
	make -C libft clean
	rm -rf $(OBJ_DIR)
	rm -rf $(BNS_OBJ_DIR)
.PHONY : clean

fclean : clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
.PHONY : fclean

re : fclean
	make all
.PHONY : re