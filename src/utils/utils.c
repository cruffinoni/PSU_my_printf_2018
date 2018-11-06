/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils functions for the main project, my_printf
*/

#include "my.h"
#include "utils.h"

int get_specifier_index(char specifier)
{
    switch (specifier) {
        case 'i':
        case 'd': return (0);
        case 'u': return (1);
        case 'x': return (2);
        case 'X': return (3);
        case 'c': return (4);
        case 'o': return (5);
        case 's': return (6);
        case 'S': return (7);
        case '%': return (8);
        case 'b': return (9);
        case 'p': return (10);
        default: return (INVALID_SPECIFIER);
    }
}