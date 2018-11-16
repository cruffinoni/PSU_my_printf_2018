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

Test(unsigned_int, big_val, .init = redirect_all_std)
{
    unsigned int un_int = 65456;

    cr_assert(my_printf("%u", un_int) == 5);
    cr_assert_stdout_eq_str("65456");
}

Test(unsigned_int, acc_zero_big, .init = redirect_all_std)
{
    unsigned int un_int = 65456;

    cr_assert(my_printf("%00006u", un_int) == 6);
    cr_assert_stdout_eq_str("065456");
}

Test(unsigned_int, acc_lesser, .init = redirect_all_std)
{
    unsigned int un_int = 65456;

    cr_assert(my_printf("%00004u", un_int) == 5);
    cr_assert_stdout_eq_str("65456");
}

Test(unsigned_int, mix_simple, .init = redirect_all_std)
{
    cr_assert(my_printf("%1lu", 20) == 2);
    cr_assert_stdout_eq_str("20");
}

Test(unsigned_int, mix_medium, .init = redirect_all_std)
{
    cr_assert(my_printf("%05lu", 20) == 5);
    cr_assert_stdout_eq_str("00020");
}

Test(unsigned_int, mix_intermediate, .init = redirect_all_std)
{
    cr_assert(my_printf("%003llu", 20) == 3);
    cr_assert_stdout_eq_str("020");
}

Test(unsigned_int, mix_hard, .init = redirect_all_std)
{
    unsigned long long_val = 288945984651326132;
    cr_assert(my_printf("%003lu", long_val) == 18);
    cr_assert_stdout_eq_str("288945984651326132");
}