/*
** EPITECH PROJECT, 2018
** integer.c
** File description:
** Handle case with integer only.
*/

#include <stdarg.h>
#include "my.h"
#include "../utils/print.h"

int type_int(va_list args)
{
    int var = va_arg(args, int);
    int count = 0;

    print_nbr_base(var, &count, 0, 10);
    return (count);
}

int type_unsigned_int(va_list args)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    print_nbr_base(var, &count, 0, 10);
    return (count);
}