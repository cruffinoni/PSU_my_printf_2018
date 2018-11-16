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

Test(character, simple_value, .init = redirect_all_std)
{
    cr_assert(my_printf("%c", 'a') == 1);
    cr_assert_stdout_eq_str("a");
}

Test(character, up_simple_value, .init = redirect_all_std)
{
    cr_assert(my_printf("%c", 'A') == 1);
    cr_assert_stdout_eq_str("A");
}

Test(character, special_char, .init = redirect_all_std)
{
    cr_assert(my_printf("%%") == 1);
    cr_assert_stdout_eq_str("%");
}

Test(character, special_char_acc, .init = redirect_all_std)
{
    cr_assert(my_printf("%10%") == 1);
    cr_assert_stdout_eq_str("%");
}

Test(character, simple_acc, .init = redirect_all_std)
{
    cr_assert(my_printf("%5c", 'a') == 5);
    cr_assert_stdout_eq_str("    a");
}