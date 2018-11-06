/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include "my.h"
#include "../utils/print.h"

int type_hex(va_list args)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    print_nbr_base(var, &count, 0, 16);
    return (count);
}

int type_hex_up(va_list args)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    print_nbr_base(var, &count, 1, 16);
    return (count);
}