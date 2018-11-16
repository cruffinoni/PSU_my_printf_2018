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

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(octal, little_val, .init = redirect_all_std)
{
    cr_assert(my_printf("%o", 10) == 2);
    cr_assert_stdout_eq_str("12");
}

Test(octal, big_val, .init = redirect_all_std)
{
    cr_assert(my_printf("%o", 0xFFFF) == 6);
    cr_assert_stdout_eq_str("177777");
}

Test(octal, acc_zero, .init = redirect_all_std)
{
    cr_assert(my_printf("%07o", 0xFFFF) == 7);
    cr_assert_stdout_eq_str("0177777");
}

Test(octal, acc_space, .init = redirect_all_std)
{
    cr_assert(my_printf("%7o", 0xFFFF) == 7);
    cr_assert_stdout_eq_str(" 177777");
}