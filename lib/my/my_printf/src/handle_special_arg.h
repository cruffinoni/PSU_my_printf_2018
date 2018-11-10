/*
** EPITECH PROJECT, 2018
** handle_args.c
** File description:
** LL & HH type have 2 chars instead of 1 which makes them special.
*/

#ifndef HEADER_SRC_HANDLESPECIALARG
#define HEADER_SRC_HANDLESPECIALARG

#include <stdlib.h>
#include "my_printf.h"

size_t handle_special_arg_l(char const *src, int *idx);
size_t handle_special_arg_h(char const *src, int *idx);
size_t handle_normal_arg(char const *src, int *idx, size_t flag);

#endif