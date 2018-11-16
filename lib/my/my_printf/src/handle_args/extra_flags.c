/*
** EPITECH PROJECT, 2018
** extra_flags.c
** File description:
** Handle flags below: +, - and #
*/

#include "./extra_flags.h"
#include "../my_printf.h"
#include "../utils/getid.h"

void parse_extra_flags(char const *src, int *index, t_local_spe *specifier)
{
    while (src[*index + 1] != '\0') {
        switch (src[*index + 1]) {
            case '-': specifier->flags_extra |= EXTRAF_MINUS;
                break;
            case '+': specifier->flags_extra |= EXTRAF_PLUS;
                break;
            case '#': specifier->flags_extra |= EXTRAF_HASH;
                break;
            case ' ': specifier->flags_extra |= EXTRAF_SPACE;
                break;
            default: return;
        }
        *index = *index + 1;
    }
}