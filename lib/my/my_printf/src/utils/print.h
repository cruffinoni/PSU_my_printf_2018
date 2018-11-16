/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_PRINT
#define HEADER_SRC_PRINT

#include "../my_printf.h"
int print_nbr_base(long nbr, int *count, int upper_case, int base);
void put_char_base(long number, int upper_case);
int print_string(char *string, int *count, int escape_char);
void print_char_ite(long count, t_local_spe specifier_infos);

#endif