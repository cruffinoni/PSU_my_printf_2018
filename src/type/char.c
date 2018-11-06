/*
** EPITECH PROJECT, 2018
** hexadecimal.c
** File description:
** Print an hexadecimal number.
*/

#include <stdarg.h>
#include <unistd.h>

int type_char(va_list args)
{
    char var = va_arg(args, int);

    write(1, &var, 1);
    return (1);
}