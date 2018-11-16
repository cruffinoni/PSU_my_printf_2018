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

Test(binary, simple_value, .init = redirect_all_std)
{
    cr_assert(my_printf("%b", 10) == 4);
    cr_assert_stdout_eq_str("1010");
}

Test(binary, specifier_spaced, .init = redirect_all_std)
{
    cr_assert(my_printf("%     b", 10) == 4);
    cr_assert_stdout_eq_str("1010");
}

Test(binary, big_val, .init = redirect_all_std)
{
    cr_assert(my_printf("%b", 0xFFFF) == 16);
    cr_assert_stdout_eq_str("1111111111111111");
}

Test(binary, acc_space, .init = redirect_all_std)
{
    cr_assert(my_printf("%20b", 0xFFFF) == 20);
    cr_assert_stdout_eq_str("    1111111111111111");
}

Test(binary, acc_zero, .init = redirect_all_std)
{
    cr_assert(my_printf("%0020b", 0xFFFF) == 20);
    cr_assert_stdout_eq_str("00001111111111111111");
}

Test(binary, extra_acc, .init = redirect_all_std)
{
    cr_assert(my_printf("%0020.21b", 0xFFFF) == 21);
    cr_assert_stdout_eq_str("000001111111111111111");
}

Test(binary, mix_acc, .init = redirect_all_std)
{
    cr_assert(my_printf("%21.20b", 0xFFFF) == 21);
    cr_assert_stdout_eq_str(" 00001111111111111111");
}

Test(binary, mix_acc_neg, .init = redirect_all_std)
{
    cr_assert(my_printf("%-21.20b", 0xFFFF) == 21);
    cr_assert_stdout_eq_str("00001111111111111111 ");
}

Test(binary, mix_acc_zero, .init = redirect_all_std)
{
    cr_assert(my_printf("%021.20b", 0xFFFF) == 21);
    cr_assert_stdout_eq_str(" 00001111111111111111");
}