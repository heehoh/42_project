NAME = philo
SRCS = main.c \
	   philo_do.c \
	   philo_set.c \
	   philo_thread.c \
	   philo_util.c

OBJS = $(SRCS:.c=.o)

OBJ_DIR = obj

OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=address
LFLAGS =

INCLUDE = 

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES)
	@$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)
	@echo "\033[31mmake philo\033[0m"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "\033[33mclean obj\033[0m"
.PHONY : clean

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[33mremove philo\033[0m"
.PHONY : fclean

re : fclean
	@make all
.PHONY : re