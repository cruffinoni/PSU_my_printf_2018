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
#include "../src/type/hexadecimal.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(hexadecimal, simple_value, .init = redirect_all_std)
{
    unsigned int un_int = 10;

    cr_assert(my_printf("%x", un_int) == 1);
    cr_assert_stdout_eq_str("a");
}

Test(hexadecimal, up_simple_value, .init = redirect_all_std)
{
    unsigned int un_int = 10;

    cr_assert(my_printf("%X", un_int) == 1);
    cr_assert_stdout_eq_str("A");
}

Test(hexadecimal, big_val, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%x", un_int) == 4);
    cr_assert_stdout_eq_str("ffff");
}

Test(hexadecimal, up_big_val, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%X", un_int) == 4);
    cr_assert_stdout_eq_str("FFFF");
}

Test(hexadecimal, acc_zero, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%05x", un_int) == 5);
    cr_assert_stdout_eq_str("0ffff");
}

Test(hexadecimal, acc_zero_up, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%05X", un_int) == 5);
    cr_assert_stdout_eq_str("0FFFF");
}

Test(hexadecimal, acc_space, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%5x", un_int) == 5);
    cr_assert_stdout_eq_str(" ffff");
}

Test(hexadecimal, acc_space_up, .init = redirect_all_std)
{
    unsigned int un_int = 0xFFFF;

    cr_assert(my_printf("%5X", un_int) == 5);
    cr_assert_stdout_eq_str(" FFFF");
}