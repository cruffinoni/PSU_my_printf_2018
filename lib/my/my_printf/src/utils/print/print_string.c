/*
** EPITECH PROJECT, 2018
** print_string.c
** File description:
** Print functions for string only
*/

#include "my.h"
#include "print_uint.h"
#include "print_int.h"

static int my_putchar_escaped(char c)
{
    int count_char = 0;

    if (!(c >= 32 && c <= 126)) {
        my_putchar('\\');
        count_char++;
        uint_print_nbr(c, &count_char, 0, 8);
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

int print_char_ite(int count, char c)
{
    for (int i = 0; i < count; i++)
        my_putchar(c);
    return (count);
}

void put_char_base(int number, int upper_case)
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