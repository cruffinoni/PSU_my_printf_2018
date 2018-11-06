/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils functions for the main programm, my_printf
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

void put_char_base(long number, int upper_case)
{
    if (upper_case) {
        if (number >= 10)
            my_putchar((number - 10) + 'A');
        else
            my_putchar(number + '0');
    }
    else {
        if (number >= 10)
            my_putchar((number - 10) + 'a');
        else
            my_putchar(number + '0');
    }
}

int print_nbr_base(long nbr, int *count, int upper_case, int base)
{
    long displayed_number = 0;

    if (nbr < 0) {
        my_putchar('-');
        *count = *count + 1;
        nbr *= -1;
    }
    if (nbr >= base) {
        displayed_number = nbr % base;
        nbr = (nbr - displayed_number) / base;
        *count = *count + 1;
        print_nbr_base(nbr, count, upper_case, base);
        put_char_base(displayed_number, upper_case);
    }
    else {
        *count = *count + 1;
        put_char_base(nbr, upper_case);
    }
    return (0);
}

int my_putchar_escaped(char c)
{
    int count_char = 0;

    if (!(c >= 32 && c <= 126)) {
        my_putchar('\\');
        count_char++;
        print_nbr_base(c, &count_char, 0, 8);
    }
    else {
        count_char++;
        my_putchar(c);
    }
    return (count_char);
}

int print_string(char *string, int *count, int escape_char)
{
    if (*string == '\0')
        return (0);
    if (!escape_char) {
        my_putchar(*string);
        *count = *count + 1;
    }
    else
        *count = *count + my_putchar_escaped(*string);
    return (print_string(++string, count, escape_char));
}