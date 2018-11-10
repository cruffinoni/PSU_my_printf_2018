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

MAIN_FILE = ./src/main.c

SRC_TEST = 	./tests/tests_integer.c 		\
			./tests/tests_hexadecimal.c 	\
			./tests/tests_octal.c 			\
			./tests/tests_char.c 			\
			./tests/tests_binary.c 			\
			./tests/tests_string.c 			\
			./tests/tests_errors.c 			\
			./tests/tests_pointer.c 		\

NAME	=	my_printf
NAME_TEST	=	test_my_printf
LIB_MAKEFILE_PATH = ./lib/my/
LIB_PATH = ./lib
INCLUDE_PATH = ./include/
PRINTF_PATH = ./lib/my/my_printf

CFLAGS	=	-W -Wall -Wextra -I $(INCLUDE_PATH) -L $(LIB_PATH) -lmy

OBJ	=	$(SRC:.c=.o)
OBJ_MAIN = $(MAIN_FILE:.c=.o)

$(NAME):
	cp ./src $(PRINTF_PATH) -rf
	$(MAKE) -C $(PRINTF_PATH)
	$(MAKE) -C $(LIB_MAKEFILE_PATH)

binary:	$(OBJ) $(OBJ_MAIN)
		$(MAKE) -C $(LIB_MAKEFILE_PATH)
		cc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) -g

all: $(NAME)

debug:
	gcc $(SRC) -o $(NAME) $(CFLAGS) -g

tests_run:
	$(MAKE) -C $(LIB_MAKEFILE_PATH)
	gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) -lcriterion --coverage -g

clean:
		rm -f $(OBJ) $(OBJ_MAIN)
		$(MAKE) -C $(LIB_MAKEFILE_PATH) clean

fclean:
		rm -f $(OBJ) $(OBJ_MAIN)
		rm -f $(NAME) $(NAME_TEST)
		$(MAKE) -C $(LIB_MAKEFILE_PATH) fclean

re:		fclean all

.PHONY: 	all clean fclean re debug