/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils functions for the main project, my_printf
*/

#include "my.h"
#include "utils.h"
#include "flags.h"

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
        case 'b': return (8);
        case 'p': return (9);
        default: return (INVALID_SPECIFIER);
    }
}

int int_len(long long number)
{
    int count = 0;

    while (number > 0) {
        count++;
        number /= 10;
    }
    return (count);
}

int count_nbr_base(long long nbr, int *count, int base)
{
    long long displayed_number = 0;

    if (nbr < 0) {
        *count = *count + 1;
        nbr *= -1;
    }
    if (nbr >= base) {
        displayed_number = nbr % base;
        nbr = (nbr - displayed_number) / base;
        *count = *count + 1;
        count_nbr_base(nbr, count, base);
    }
    else
        *count = *count + 1;
    return (0);
}