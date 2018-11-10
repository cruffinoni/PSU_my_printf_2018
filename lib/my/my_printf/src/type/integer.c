/*
** EPITECH PROJECT, 2018
** integer.c
** File description:
** Handle case with integer only.
*/

#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"

int type_int(va_list args, t_specifier specifier_infos)
{
    int var = va_arg(args, int);
    int count = 0;

    count_nbr_base(var, &count, 10);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    print_nbr_base(var, &count, 0, 10);
    return (count + specifier_infos.precision);
}

int type_unsigned_int(va_list args, t_specifier specifier_infos)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    count_nbr_base(var, &count, 10);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    print_nbr_base(var, &count, 0, 10);
    return (count + specifier_infos.precision);
}