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

Test(errors, forbidden_specifier, .init = redirect_all_std)
{
    cr_assert(my_printf("%m") == 2);
    cr_assert_stdout_eq_str("%m");
}

Test(errors, solo_per, .init = redirect_all_std)
{
    cr_assert(my_printf("a%") == -1);
    cr_assert_stdout_eq_str("a");
}