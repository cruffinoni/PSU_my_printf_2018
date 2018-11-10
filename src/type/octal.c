/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"

int type_octal(va_list args, t_specifier specifier_infos)
{
    unsigned int var = va_arg(args, unsigned int);
    int count = 0;

    count_nbr_base(var, &count, 8);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    print_nbr_base(var, &count, 0, 8);
    return (count + specifier_infos.precision);
}