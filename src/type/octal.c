/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include "my.h"
#include "../utils/print.h"

int type_octal(va_list args)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    print_nbr_base(var, &count, 0, 8);
    return (count);
}