/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include <unistd.h>
#include "../my_printf.h"
#include "../utils/utils.h"
#include "../utils/print.h"

int type_pointer(va_list args, t_specifier specifier_infos)
{
    void *var = va_arg(args, void *);
    int count = 2;

    write(1, "0x", 2);
    print_nbr_base((long) var, &count, 0, 16);
    specifier_infos.precision = 0;
    return (count + specifier_infos.precision);
}