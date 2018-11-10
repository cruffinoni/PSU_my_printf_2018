/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** Header file for my_printf.c
*/

#ifndef HEADER_SRC_PRINTF
#define HEADER_SRC_PRINTF

#include <stdlib.h>

int my_printf(char const *src, ...);
typedef struct s_specifier
{
    size_t flags;
    //char to_fill;
    int precision;
} t_specifier;

#endif