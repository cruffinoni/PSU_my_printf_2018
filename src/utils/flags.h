/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_UTILS_FLAGS
#define HEADER_SRC_UTILS_FLAGS

#define FLAGS_ERROR (1)

#include <stddef.h>
void add_flag(size_t *var, size_t flag);
int compute_flag(int value, size_t flag);

#endif