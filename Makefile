# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 10:51:00 by ftourret     #+#   ##    ##    #+#        #
<<<<<<< HEAD
#    Updated: 2018/10/18 16:35:40 by naplouvi    ###    #+. /#+    ###.fr      #
=======
#    Updated: 2018/10/18 15:58:10 by ftourret    ###    #+. /#+    ###.fr      #
>>>>>>> 8f3aeec2f7559320cb5bd864970443b78c9f2af6
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC =	fillit.c\
		ft_error.c\
		main.c\

OBJ = $(subst .c,.o,$(SRC))

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@echo "$(LIGHT_GREEN)Compilation de la Libft : "
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

%.o: %.c fillit.h
	@gcc $(FLAGS) -I libft/includes -o $@ -c $<
	@echo "$(DARK_BLUE).\c"

clean:
	@rm -rf $(OBJ)
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: fclean all
