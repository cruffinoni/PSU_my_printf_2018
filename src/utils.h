/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** Header file for utils.c
*/

#ifndef HEADER_SRC_UTILS
#define HEADER_SRC_UTILS

#define INVALID_SPECIFIER (-1)

int get_specifier_index(char specifier);
int print_nbr_base(long nbr, int *count, int upper_case, int base);
void put_char_base(long number, int upper_case);
int print_string(char *string, int *count, int escape_char);

#endif