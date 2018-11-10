/*
** EPITECH PROJECT, 2018
** integer.c
** File description:
** Handle case with integer only.
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"
#include "../utils/recast.h"

int type_int(va_list args, t_specifier specifier_infos)
{
    long long var = va_arg(args, long long);
    int count = 0;

    int_recast_cnb(var, &count, 10, specifier_infos.flags);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    int_recast_pnb(var, &count, 10, specifier_infos.flags);
    return (count + specifier_infos.precision);
}

int type_unsigned_int(va_list args, t_specifier specifier_infos)
{
    uintptr_t var = va_arg(args, uintptr_t);
    int count = 0;

    uint_recast_cnb(var, &count, 10, specifier_infos.flags);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    uint_recast_pnb(var, &count, 10, specifier_infos.flags);
    return (count + specifier_infos.precision);
}