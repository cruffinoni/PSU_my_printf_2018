/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Utils functions for the main project, my_printf
*/

#include <stdint.h>
#include "my.h"
#include "../my_printf.h"
#include "../handle_args/handle_extraf.h"
#include "flags.h"

void put_char_base(long long number, int upper_case)
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

int print_nbr_base(long long nbr, int *count, int upper_case, int base)
{
    long long displayed_number = 0;

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

void print_char_ite(long count, t_local_spe specifier_infos)
{
    char c = 0;

    c = (specifier_infos.flags_type & FLAG_ACC_IS_ZERO) ? '0' : ' ';
    while (count-- > 0)
        my_putchar(c);
}

int print_char_ite2(long count, char c)
{
    for (int i = 0; i < count; i++)
        my_putchar(c);
    return (count);
}

int print_precision(t_local_spe speinfo)
{
    int c = 0;

    if (speinfo.precision > speinfo.extra_precision &&
        (speinfo.flags_type & FLAG_ACC_IS_ZERO) != FLAG_ACC_IS_ZERO)
        c = print_char_ite2(speinfo.precision - speinfo.extra_precision, ' ');
    else if (speinfo.precision > speinfo.extra_precision)
        c = print_char_ite2(speinfo.precision, '0');
    else
        c = print_char_ite2(speinfo.precision, '0');
    return (c);
}

static int print_hash_extraf(char basic_specifier)
{
    switch(basic_specifier) {
        case 'x': write(1, "0x", 2);
            return (2);
        case 'X': write(1, "0X", 2);
            return (2);
        case 'o': write(1, "0", 2);
            return (1);
    }
    return (0);
}

int print_extraf(int base, t_local_spe specifier_infos, int is_uint, int is_neg)
{
    int count = 0;

    if (specifier_infos.flags_extra & EXTRAF_HASH)
        count += print_hash_extraf(specifier_infos.basic_specifier);
    if ((specifier_infos.flags_extra & EXTRAF_PLUS) == EXTRAF_PLUS && !is_uint)
        if (is_neg)
            count += my_putchar('-');
        else
            count += my_putchar('+');
    return (count);
}

int uint_print_nbr(uintptr_t nbr, int *count, int upper_case, int base)
{
    uintptr_t displayed_number = 0;

    if (nbr >= base) {
        displayed_number = nbr % base;
        nbr = (nbr - displayed_number) / base;
        *count = *count + 1;
        print_uint_nbr(nbr, count, upper_case, base);
        put_char_base(displayed_number, upper_case);
    }
    else {
        *count = *count + 1;
        put_char_base(nbr, upper_case);
    }
    return (0);
}