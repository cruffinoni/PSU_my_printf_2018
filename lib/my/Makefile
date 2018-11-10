##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Basic makefile to compile 'my' library
##

SRC		= 	get_color.c \
			my_compute_power_rec.c \
			my_compute_square_root.c \
			my_find_prime_sup.c \
			my_getnbr.c \
			my_is_prime.c \
			my_isalphanumeric.c \
			my_isletter.c \
			my_isneg.c \
			my_isnumber.c \
			my_put_nbr.c \
			my_putnbr_base.c \
			my_putstr.c \
			my_revstr.c \
			my_putchar.c \
			my_showmem.c \
			my_showstr.c \
			my_sort_int_array.c \
			my_str_isalpha.c \
			my_str_islower.c \
			my_str_isnum.c \
			my_str_isprintable.c \
			my_str_isupper.c \
			my_str_to_word_array.c \
			my_strcapitalize.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_strdup.c \
			my_strlen.c \
			my_strlowcase.c \
			my_strncat.c \
			my_strncmp.c \
			my_strncpy.c \
			my_strstr.c \
			my_strupcase.c \
			my_swap.c \
			my_strtol.c \
			$(PRINTF_PATH)/my_printf.c 			\
			$(PRINTF_PATH)/utils/utils.c 		\
			$(PRINTF_PATH)/utils/print.c 		\
			$(PRINTF_PATH)/utils/flags.c 		\
			$(PRINTF_PATH)/type/integer.c 		\
			$(PRINTF_PATH)/type/hexadecimal.c 	\
			$(PRINTF_PATH)/type/octal.c 			\
			$(PRINTF_PATH)/type/char.c 			\
			$(PRINTF_PATH)/type/string.c 		\
			$(PRINTF_PATH)/type/binary.c 		\
			$(PRINTF_PATH)/type/pointer.c 		\

OBJ 	= 	$(SRC:.c=.o)
NAME_LIB 	= 	libmy.a
NAME_INCLUDE 	=	my.h
PRINTF_PATH 	= ./my_printf/src

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ) my
	ar rc $(NAME_LIB) $(OBJ)
	cp $(NAME_LIB) ../..
	mv $(NAME_LIB) ../

my:
	cp $(NAME_INCLUDE) ../../include/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f ../$(NAME_LIB)
		rm -f ../../$(NAME_LIB)

re: fclean all

.PHONY: all my clean fclean re