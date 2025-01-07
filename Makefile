SRC = main.c \
	get_path.c \
	pipex_utils.c
OBG = $(SRC:.c=.o)

SRC_BONUS = main_BONUS.c \
	get_path_BONUS.c \
	pipex_utils_BONUS.c

OBG_BONUS = $(SRC:.c=.o)

NAME = pipex
NAME_BONUS = pipex_bonus

run : fclean all

bonus: $(NAME_BONUS)

$(NAME) : 
	cc -g -Wall -Wextra -Werror  $(SRC) libft/libft.a -o $(NAME)

$(NAME_BONUS) : 
	cc -g -Wall -Wextra -Werror  $(SRC_BONUS) libft/libft.a -o $(NAME_BONUS) 

clean : 
	rm -f $(OBG) $(OBG_BONUS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

