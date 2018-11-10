/*
** EPITECH PROJECT, 2018
** recast.c
** File description:
** Recast number with appropriate type..
*/

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "../utils/utils.h"
#include "../utils/print.h"
#include "../utils/flags.h"

void int_recast_cnb(ptrdiff_t nbr, int *count, int base, size_t flags)
{
    if (flags & FLAG_TYPE_HH)
        count_nbr_base((signed char) nbr, count, base);
    if (flags & FLAG_TYPE_H)
        count_nbr_base((short) nbr, count, base);
    if (flags & FLAG_TYPE_L)
        count_nbr_base((long) nbr, count, base);
    if (flags & FLAG_TYPE_LL)
        count_nbr_base((long long) nbr, count, base);
    if (flags & FLAG_TYPE_J)
        count_nbr_base((intmax_t) nbr, count, base);
    if (flags & FLAG_TYPE_Z)
        count_nbr_base((ssize_t) nbr, count, base);
    if (flags & FLAG_TYPE_T)
        count_nbr_base((ptrdiff_t) nbr, count, base);
    if ((flags & (FLAG_TYPE_ALL | FLAG_UPPERCASE)) == 0)
        count_nbr_base((int) nbr, count, base);
}

void uint_recast_cnb(uintptr_t nbr, int *count, int base, size_t flags)
{
    if (flags & FLAG_TYPE_HH)
        count_nbr_base((unsigned char) nbr, count, base);
    if (flags & FLAG_TYPE_H)
        count_nbr_base((unsigned short) nbr, count, base);
    if (flags & FLAG_TYPE_L)
        count_nbr_base((unsigned long) nbr, count, base);
    if (flags & FLAG_TYPE_LL)
        count_nbr_base((unsigned long long) nbr, count, base);
    if (flags & FLAG_TYPE_J)
        count_nbr_base((uintmax_t) nbr, count, base);
    if (flags & FLAG_TYPE_Z)
        count_nbr_base((size_t) nbr, count, base);
    if (flags & FLAG_TYPE_T)
        count_nbr_base((uintptr_t) nbr, count, base);
    if ((flags & (FLAG_TYPE_ALL | FLAG_UPPERCASE)) == 0)
        count_nbr_base((unsigned int) nbr, count, base);
}

void int_recast_pnb(ptrdiff_t nbr, int *count, int base, size_t flags)
{
    if (flags & FLAG_TYPE_HH)
        print_nbr_base((signed char) nbr, count, 0, base);
    if (flags & FLAG_TYPE_H)
        print_nbr_base((short) nbr, count, 0, base);
    if (flags & FLAG_TYPE_L)
        print_nbr_base((long) nbr, count, 0, base);
    if (flags & FLAG_TYPE_LL)
        print_nbr_base((long long) nbr, count, 0, base);
    if (flags & FLAG_TYPE_J)
        print_nbr_base((intmax_t) nbr, count, 0, base);
    if (flags & FLAG_TYPE_Z)
        print_nbr_base((ssize_t) nbr, count, 0, base);
    if (flags & FLAG_TYPE_T)
        print_nbr_base((ptrdiff_t) nbr, count, 0, base);
    if ((flags & (FLAG_TYPE_ALL | FLAG_UPPERCASE)) == 0)
        print_nbr_base((int) nbr, count, 0, base);
}

void uint_recast_pnb(uintptr_t nbr, int *count, int base, size_t flags)
{
    int uppercase = ((flags & FLAG_UPPERCASE) == FLAG_UPPERCASE);

    if (flags & FLAG_TYPE_HH)
        print_nbr_base((unsigned char) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_H)
        print_nbr_base((unsigned short) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_L)
        print_nbr_base((unsigned long) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_LL)
        print_nbr_base((unsigned long long) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_J)
        print_nbr_base((uintmax_t) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_Z)
        print_nbr_base((size_t) nbr, count, uppercase, base);
    if (flags & FLAG_TYPE_T)
        print_nbr_base((uintptr_t) nbr, count, uppercase, base);
    if (((flags & ~FLAG_UPPERCASE) & FLAG_TYPE_ALL) == 0)
        print_nbr_base((unsigned int) nbr, count, uppercase, base);
}