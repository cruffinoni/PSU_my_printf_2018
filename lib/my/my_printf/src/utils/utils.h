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
int int_len(long long number);
int count_nbr_base(long long nbr, int *count, int base);

#endif