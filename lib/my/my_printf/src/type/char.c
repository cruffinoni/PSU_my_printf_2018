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

int type_char(va_list args, t_specifier specifier_infos)
{
    char var = va_arg(args, int);

    write(1, &var, 1);
    specifier_infos.precision = 0;
    return (1 + specifier_infos.precision);
}