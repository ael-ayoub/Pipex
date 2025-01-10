SRC = pipex.c pipex_util.c get_path.c
OBG = $(SRC:.c=.o)
flags = -Wall -Wextra -Werror
name = pipex
LIBFT = libft/libft.a

all: $(name)

$(name) : $(OBG) $(LIBFT)
	cc $(flags) $(OBG) $(LIBFT) -o $(name)

$(LIBFT):
	make -C libft

%.o:%.c 
	cc $(flags) -c $< -o $@

clean: 
	rm -f $(OBG)
	make clean -C libft
fclean: clean
	rm -f $(name)
	make fclean -C libft
re : fclean all

.PHONY: all clean fclean re
