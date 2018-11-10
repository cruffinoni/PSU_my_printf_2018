##
## EPITECH PROJECT, 2018
## makefile
## File description:
## this file is used for compliation of src and lib
##

SRC	=	./src/my_printf.c 			\
		./src/utils/utils.c 		\
		./src/utils/print.c 		\
		./src/utils/flags.c 		\
		./src/type/integer.c 		\
		./src/type/hexadecimal.c 	\
		./src/type/octal.c 			\
		./src/type/char.c 			\
		./src/type/string.c 		\
		./src/type/binary.c 		\
		./src/type/pointer.c 		\

LIB_PATH = ../
INCLUDE_PATH = ./include/
PRINTF_PATH = ./lib/my/my_printf

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	rm ./src/main.c -f

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(OBJ)

re:		fclean all

.PHONY: 	all clean fclean re
