/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include "my.h"
#include "../utils/print.h"

int type_string(va_list args)
{
    char *var = va_arg(args, char *);
    int count = 0;

    print_string(var, &count, 0);
    return (count);
}

int type_string_escape(va_list args)
{
    char *var = va_arg(args, char *);
    int count = 0;

    print_string(var, &count, 1);
    return (count);
}