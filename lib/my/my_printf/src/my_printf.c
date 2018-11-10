/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Recode my_printf function (see man 3 printf)
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"
#include "utils/utils.h"
#include "utils/print.h"
#include "utils/flags.h"
#include "type/integer.h"
#include "type/hexadecimal.h"
#include "type/octal.h"
#include "type/char.h"
#include "type/string.h"
#include "type/binary.h"
#include "type/pointer.h"

static int (*func_ptr[])(va_list, t_specifier) = {type_int, type_unsigned_int,
    type_hex, type_hex_up, type_char, type_octal, type_string,
    type_string_escape, type_char, type_binary, type_pointer};

static int handle_precision(char const *src, int *idx, t_specifier *specifier,
    size_t *gflag)
{
    int number = 0;
    char *cpy = malloc(my_strlen(src) + 1);
    char *ptr_cpy = cpy;

    if (cpy == NULL)
        return (84);
    my_strcpy(cpy, src);
    while (cpy[*idx + 1] == '0') {
        specifier->flags = FLAG_ACC_IS_ZERO;
        *idx = *idx + 1;
    }
    *idx = *idx + 1;
    number = my_strtol(cpy + *idx, &cpy);
    if (number < 0)
        *gflag |= FLAGS_ERROR;
    else
        specifier->precision = number;
    *idx = *idx + (int_len(number) - 1);
    free(ptr_cpy);
    return (0);
}

static int handle_invalid_arg(char const *src, int index, size_t *gflag)
{
    if (src[index + 1] == '\0' && src[index + 1] != '%') {
        *gflag |= FLAGS_ERROR;
        return (84);
    }
    else {
        my_putchar(src[index]);
        return (1);
    }
}

static int handle_args(char const *src, int *index, va_list args, size_t *gflag)
{
    t_specifier specifier = {0, 1};

    if (my_isnumber(src[*index + 1]))
        handle_precision(src, index, &specifier, gflag);
    if (src[*index + 1] == '%') {
        my_putchar('%');
        *index = *index + 1;
        return (1);
    }
    if (get_specifier_index(src[*index + 1]) != INVALID_SPECIFIER) {
        *index = *index + 1;
        return ((*func_ptr[get_specifier_index(src[*index])])(args, specifier));
    }
    else if (handle_invalid_arg(src, *index, gflag) == 84)
        return (0);
    return (1);
}

int my_printf(char const *src, ...)
{
    va_list args;
    int return_val = 0;
    size_t gflags = 0;

    va_start(args, src);
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '%')
            return_val += handle_args(src, &i, args, &gflags);
        else
            return_val += my_putchar(src[i]);
    }
    va_end(args);
    return (compute_flag(return_val, gflags));
}