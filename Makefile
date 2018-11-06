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

NAME	=	my_printf
NAME_TEST	=	test_my_printf
LIB_PATH = ./lib/my/
INCLUDE_PATH = ./include/
LIB_NAME = libmy.a

CFLAGS	=	-W -Wall -Wextra -I $(INCLUDE_PATH) -L $(LIB_PATH) -lmy

OBJ	=	$(SRC:.c=.o)
OBJ_MAIN = $(MAIN_FILE:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	ar rc $(LIB_NAME) $(OBJ)

binary:	$(OBJ) $(OBJ_MAIN)
		$(MAKE) -C $(LIB_PATH)
		cc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) -g

all: $(NAME)

debug:
	gcc $(SRC) -o $(NAME) $(CFLAGS) -g

tests_run:
	$(MAKE) -C $(LIB_PATH)
	gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) -lcriterion --coverage -g

clean:
		rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
		$(MAKE) -C $(LIB_PATH) clean

fclean:
		rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
		rm -f $(NAME) $(NAME_TEST)
		$(MAKE) -C $(LIB_PATH) fclean

re:		fclean all

.PHONY: 	all clean fclean re debug
