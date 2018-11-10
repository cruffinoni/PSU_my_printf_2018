/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "../my_printf.h"
#include "../utils/print.h"

int type_char(va_list args, t_specifier specifier_infos)
{
    int var = va_arg(args, int);

    if (specifier_infos.precision > 1)
        specifier_infos.precision --;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, specifier_infos.flags);
    write(1, &var, 1);
    return (1 + specifier_infos.precision);
}