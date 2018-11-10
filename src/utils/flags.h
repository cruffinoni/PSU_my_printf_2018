/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_UTILS_FLAGS
#define HEADER_SRC_UTILS_FLAGS

#define INVALID_TYPE            (-1)
#define GFLAG_INVALID_VALUE     (0b1)
#define FLAG_TYPE_HH            (0b1)
#define FLAG_TYPE_H             (0b10)
#define FLAG_TYPE_L             (0b100)
#define FLAG_TYPE_LL            (0b1000)
#define FLAG_TYPE_J             (0b10000)
#define FLAG_TYPE_Z             (0b100000)
#define FLAG_TYPE_T             (0b10000000)
#define FLAG_ACC_IS_ZERO        (0b100000000)
#define FLAG_INVALID_TYPE       (0b1000000000)
#define FLAG_SINGLE             (FLAG_TYPE_J | FLAG_TYPE_Z | FLAG_TYPE_T)

#include <stddef.h>
int compute_gflag(int value, size_t flag);

#endif