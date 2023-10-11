NAME = a.out
SRCS = main.cpp \
			 Bureaucrat.cpp \
			 AForm.cpp \
			 PresidentialPardonForm.cpp \
			 RobotomyRequestForm.cpp \
			 ShrubberyCreationForm.cpp \
			 Intern.cpp

OBJS = $(SRCS:.cpp=.o)

OBJ_DIR = obj

OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJS_FILES)
	@$(CXX) $(CXXFLAGS) $(OBJS_FILES) -o $(NAME)
	@echo "\033[32mmake $(NAME)\033[0m"

clean :
	@rm -rf $(OBJ_DIR)
	@rm -rf *_shrubbery
	@echo "\033[33mremove obj\033[0m"
.PHONY : clean

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[33mremove $(NAME)\033[0m"
.PHONY : fclean

re : fclean
	@make all
.PHONY : re