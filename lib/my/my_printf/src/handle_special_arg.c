/*
** EPITECH PROJECT, 2018
** handle_special_types.c
** File description:
** LL & HH type have 2 chars instead of 1 which makes them special.
*/

#include "my.h"
#include "my_printf.h"
#include "utils/flags.h"
#include "utils/utils.h"

size_t handle_special_arg_l(char const *src, int *idx)
{
    *idx = *idx + 1;
    if (src[*idx + 1] == 'l' || src[*idx + 1] == 'L') {
        *idx = *idx + 1;
        if (get_local_spe_index(src[*idx + 1]) == INVALID_SPECIFIER)
            return (FLAG_INVALID_TYPE);
        return (FLAG_TYPE_LL);
    }
    else if (get_local_spe_index(src[*idx + 1]) != INVALID_SPECIFIER)
        return (FLAG_TYPE_L);
    return (FLAG_INVALID_TYPE);
}

size_t handle_special_arg_h(char const *src, int *idx)
{
    *idx = *idx + 1;
    if (src[*idx + 1] == 'h' || src[*idx + 1] == 'H') {
        *idx = *idx + 1;
        if (get_local_spe_index(src[*idx + 1]) == INVALID_SPECIFIER)
            return (FLAG_INVALID_TYPE);
        return (FLAG_TYPE_HH);
    }
    else if (get_local_spe_index(src[*idx + 1]) != INVALID_SPECIFIER)
        return (FLAG_TYPE_H);
    return (FLAG_INVALID_TYPE);
}

size_t handle_normal_arg(char const *src, int *idx, size_t flag)
{
    *idx = *idx + 1;
    if (get_local_spe_index(src[*idx + 1]) != INVALID_SPECIFIER)
        return (flag);
    return (FLAG_INVALID_TYPE);
}