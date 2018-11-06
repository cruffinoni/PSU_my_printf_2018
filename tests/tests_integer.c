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
#include "../src/type/integer.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(integer, simple_value, .init = redirect_all_std)
{
    int int_val = 5;

    cr_assert(my_printf("%i", int_val) == 1);
    cr_assert_stdout_eq_str("5");
}

Test(integer, negative_val, .init = redirect_all_std)
{
    int int_val = -5;

    cr_assert(my_printf("%i", int_val) == 2);
    cr_assert_stdout_eq_str("-5");
}

Test(unsigned_int, simple_value, .init = redirect_all_std)
{
    unsigned int un_int = 6;

    cr_assert(my_printf("%u", un_int) == 1);
    cr_assert_stdout_eq_str("6");
}

Test(unsigned_int, little_val, .init = redirect_all_std)
{
    unsigned int un_int = 65456;

    cr_assert(my_printf("%u", un_int) == 5);
    cr_assert_stdout_eq_str("65456");
}