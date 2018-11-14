/*
** EPITECH PROJECT, 2018
** string.c
** File description:
** Print a string passed as an argument.
*/

#include <stdarg.h>
#include "../../../my.h"
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"

int type_string(va_list args, t_specifier specifier_infos)
{
    char *var = va_arg(args, char *);
    int count = my_strlen(var);

    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, 0);
    count = 0;
    print_string(var, &count, 0);
    return (count + specifier_infos.precision);
}

int type_string_escape(va_list args, t_specifier specifier_infos)
{
    char *var = va_arg(args, char *);
    int count = my_strlen(var);

    if (specifier_infos.precision > count)
        specifier_infos.precision -= count;
    else
        specifier_infos.precision = 0;
    print_char_ite(specifier_infos.precision, 0);
    count = 0;
    print_string(var, &count, 1);
    return (count + specifier_infos.precision);
}