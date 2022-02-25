HEADER = philo.h
#
SRC = 	action.c check.c end.c ft_atoi.c \
  		 init.c   main.c  utils.c
#
OBJ = $(SRC:.c=.o)
#
FLAGS = -Wall -Werror -Wextra
#
NAME = philo_bonus
#
all: $(NAME)
#
$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "\033[32m\033[1m[philo_bonus compiled]"
#
%.o: %.c
	@$(CC) $(FLAGS) -c $<
#
clean:
	@rm -rf $(OBJ)
	@echo "\033[31m\033[1m[all clean]"
#
fclean: clean
	@rm -rf $(NAME)
#
re: fclean all
#
# -g -fsanitize=address
# -g -fsanitize=thread