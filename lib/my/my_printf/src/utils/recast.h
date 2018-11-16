/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_RECAST
#define HEADER_SRC_RECAST

#include <sys/types.h>
#include <stdint.h>
#include <stdarg.h>
#include "../my_printf.h"

void int_recast_cnb(ptrdiff_t nbr, int *count, int base, t_local_spe spec);
void uint_recast_cnb(uintptr_t nbr, int *count, int base, t_local_spe spec);
void int_recast_pnb(ptrdiff_t nbr, int *count, int base, t_local_spe spec);
void uint_recast_pnb(uintptr_t nbr, int *count, int base, t_local_spe spec);

#endif