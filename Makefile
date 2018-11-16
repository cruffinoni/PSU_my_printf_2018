##
## EPITECH PROJECT, 2018
## makefile
## File description:
## this file is used for compliation of src and lib
##

SRC	=	./src/my_printf.c 						\
		./src/type/signed_int/small_len.c 		\
		./src/type/signed_int/big_len.c 		\
		./src/type/unsigned_int/small_len.c 	\
		./src/type/unsigned_int/big_len.c 		\
		./src/type/char.c 						\
		./src/type/string.c 					\
		./src/type/pointer.c 					\
		./src/handle_args/parse_redirect.c 		\
		./src/handle_args/extra_flags.c 		\
		./src/handle_args/precision.c 			\
		./src/utils/utils.c 					\
		./src/utils/print/print.c 				\
		./src/utils/print/print_int.c 			\
		./src/utils/print/print_uint.c 			\
		./src/utils/print/print_string.c 		\
		./src/utils/flags.c 					\
		./src/utils/getid.c 					\

MAIN_FILE = ./src/main.c
MAIN_TEST_FILE = ./src/main_test.c

SRC_TEST = 	./tests/tests_integer.c 		\
			./tests/tests_hexadecimal.c 	\
			./tests/tests_octal.c 			\
			./tests/tests_char.c 			\
			./tests/tests_binary.c 			\
			./tests/tests_string.c 			\
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
OBJ_MAIN_TEST = $(MAIN_FILE:.c=.o)

$(NAME):
	cp ./src $(LIB_MAKEFILE_PATH)my_printf/ -rf
	$(MAKE) -C $(LIB_MAKEFILE_PATH)

binary:	$(OBJ) $(OBJ_MAIN)
		$(MAKE) -C $(LIB_MAKEFILE_PATH)
		gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) -g

binary_test: $(OBJ) $(OBJ_MAIN_TEST)
		$(MAKE) -C $(LIB_MAKEFILE_PATH)
		gcc -o $(NAME) $(OBJ) $(OBJ_MAIN_TEST) $(CFLAGS) -g

all: $(NAME)

debug:
	gcc $(SRC) $(MAIN_FILE) -o $(NAME) $(CFLAGS) -g

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