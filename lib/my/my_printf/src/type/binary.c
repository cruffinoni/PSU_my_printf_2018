/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print a binary number.
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "my.h"
#include "../utils/recast.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"

int type_binary(va_list args, t_specifier specifier_infos)
{
    uintptr_t var = va_arg(args, uintptr_t);
    int count = 0;

    uint_recast_cnb(var, &count, 2, specifier_infos.flags);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    count = 0;
    uint_recast_pnb(var, &count, 2, specifier_infos.flags);
    return (count + specifier_infos.precision);
}