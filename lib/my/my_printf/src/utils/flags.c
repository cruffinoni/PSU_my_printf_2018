/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** Utils functions for the main project, my_printf
*/

#include <stddef.h>
#include "flags.h"

void add_flag(size_t *var, size_t flag)
{
    *var = *var | flag;
}

int compute_flag(int value, size_t flag)
{
    if (flag & FLAGS_ERROR)
        return (-1);
    return (value);
}