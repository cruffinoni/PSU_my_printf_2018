/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Recode my_printf function (see man 3 printf)
*/

#include <stdarg.h>
#include "my_printf.h"

static int handle_args(char const *src, int *index, va_list args)
{
    int (*func_ptr[])(va_list) = {type_int, type_unsigned_int, type_hex,
        type_hex_up, type_char, type_octal, type_string, type_string_escape,
        type_char, type_binary, type_pointer};

    if (src[*index + 1] == '%') {
        my_putchar('%');
        *index = *index + 1;
        return (1);
    }
    else if (get_specifier_index(src[*index + 1]) != INVALID_SPECIFIER) {
        *index = *index + 1;
        return ((*func_ptr[get_specifier_index(src[*index])])(args));
    }
    return (0);
}

static int handle_invalid_arg(char const *src, int index, size_t *flags)
{
    if (src[index + 1] == '\0')
        add_flag(flags, FLAGS_ERROR);
    else
        my_putchar(src[index]);
    return (1);
}

int my_printf(char const *src, ...)
{
    va_list args;
    int return_val = 0;
    size_t flags = 0;

    va_start(args, src);
    for (int i = 0; src[i] != '\0'; i++) {
        if ((get_specifier_index(src[i + 1]) == INVALID_SPECIFIER
            && src[i] == '%'))
            return_val += handle_invalid_arg(src, i, &flags);
        else if (src[i] == '%')
            return_val += handle_args(src, &i, args);
        else
            return_val += my_putchar(src[i]);
    }
    va_end(args);
    return (compute_flag(return_val, flags));
}