/*
** EPITECH PROJECT, 2018
** tests_integer.c
** File description:
** Test file for integer value.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../src/my_printf.h"
#include "../src/type/octal.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(octal, little_val, .init = redirect_all_std)
{
    unsigned int un_int = 10;

    cr_assert(my_printf("%o", un_int) == 2);
    cr_assert_stdout_eq_str("12");
}

Test(octal, big_val, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%o", un_int) == 6);
    cr_assert_stdout_eq_str("177777");
}

Test(octal, acc_zero, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%07o", un_int) == 7);
    cr_assert_stdout_eq_str("0177777");
}