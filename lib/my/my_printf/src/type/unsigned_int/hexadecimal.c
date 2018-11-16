/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "../../utils/flags.h"
#include "../../utils/recast.h"
#include "../../my_printf.h"
#include "../../utils/utils.h"
#include "../../utils/print.h"

int type_hex(va_list args, t_local_spe specifier_infos)
{
    uintptr_t var = va_arg(args, uintptr_t);
    int count = 0;

    uint_recast_cnb(var, &count, 16, specifier_infos);
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos);
    count = 0;
    uint_recast_pnb(var, &count, 16, specifier_infos);
    return (count + specifier_infos.precision);
}

int type_hex_up(va_list args, t_local_spe specifier_infos)
{
    uintptr_t var = va_arg(args, uintptr_t);
    int count = 0;

    uint_recast_cnb(var, &count, 16, specifier_infos);
    specifier_infos.flags_type |= FLAG_UPPERCASE;
    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos);
    count = 0;
    uint_recast_pnb(var, &count, 16, specifier_infos);
    return (count + specifier_infos.precision);
}