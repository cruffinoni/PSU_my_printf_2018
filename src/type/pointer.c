/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include <unistd.h>
#include "../utils/print.h"

int type_pointer(va_list args)
{
    void *var = va_arg(args, void *);
    int count = 2;

    write(1, "0x", 2);
    print_nbr_base((long) var, &count, 0, 16);
    return (count);
}