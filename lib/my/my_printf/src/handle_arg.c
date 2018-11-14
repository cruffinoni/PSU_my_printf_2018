/*
** EPITECH PROJECT, 2018
** handle_args.c
** File description:
** Main function that handle every args after the '%' char.
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../../my.h"
#include "utils/utils.h"
#include "utils/print.h"
#include "utils/flags.h"
#include "handle_special_arg.h"
#include "type/integer.h"
#include "type/hexadecimal.h"
#include "type/octal.h"
#include "type/char.h"
#include "type/string.h"
#include "type/binary.h"
#include "type/pointer.h"

static int (*func_ptr[])(va_list, t_specifier) = {type_int, type_unsigned_int,
    type_hex, type_hex_up, type_char, type_octal, type_string,
    type_string_escape, type_binary, type_pointer};

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
        specifier->flags |= FLAG_ACC_IS_ZERO;
        *idx = *idx + 1;
    }
    *idx = *idx + 1;
    number = my_strtol(cpy + *idx, &cpy);
    if (number < 0)
        *gflag |= GFLAG_INVALID_VALUE;
    else
        specifier->precision = number;
    *idx = *idx + (int_len(number) - 1);
    free(ptr_cpy);
    return (0);
}

static int handle_invalid_arg(char const *src, int index, size_t *gflag)
{
    if (src[index + 1] == '\0' && src[index + 1] != '%') {
        *gflag |= GFLAG_INVALID_VALUE;
        return (84);
    }
    else {
        my_putchar(src[index]);
        return (1);
    }
}

static void handle_type(char const *src, int *idx, t_specifier *specifier)
{
    switch (src[*idx + 1]) {
        case 'h':
        case 'H': specifier->flags |= handle_special_arg_h(src, idx);
            break;
        case 'L':
        case 'l': specifier->flags |= handle_special_arg_l(src, idx);
            break;
        case 'J':
        case 'j': specifier->flags |= handle_normal_arg(src, idx, FLAG_TYPE_J);
            break;
        case 'Z':
        case 'z': specifier->flags |= handle_normal_arg(src, idx, FLAG_TYPE_Z);
            break;
        case 'T':
        case 't': specifier->flags |= handle_normal_arg(src, idx, FLAG_TYPE_T);
            break;
        default: specifier->flags |= FLAG_INVALID_TYPE;
    }
    if ((specifier->flags & (FLAG_SINGLE)) == specifier->flags)
        *idx = *idx + 1;
}

int handle_args(char const *src, int *index, va_list args, size_t *gflag)
{
    t_specifier specifier = {0, 1};

    if (my_isnumber(src[*index + 1]))
        handle_precision(src, index, &specifier, gflag);
    if (my_isletter(src[*index + 1]) && get_specifier_index(src[*index + 1])
        == INVALID_SPECIFIER)
        handle_type(src, index, &specifier);
    if (src[*index + 1] == '%' || (specifier.flags & FLAG_INVALID_TYPE)) {
        my_putchar('%');
        if ((specifier.flags & FLAG_INVALID_TYPE) != FLAG_INVALID_TYPE)
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
