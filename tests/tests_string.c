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
#include "../src/type/string.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(string, word, .init = redirect_all_std)
{
    cr_assert(my_printf("%s", "Hello") == 5);
    cr_assert_stdout_eq_str("Hello");
}

Test(string, sentance, .init = redirect_all_std)
{
    cr_assert(my_printf("%s", "Hello World") == 11);
    cr_assert_stdout_eq_str("Hello World");
}

Test(string, acc_space_only, .init = redirect_all_std)
{
    cr_assert(my_printf("%15s", "Hello World") == 15);
    cr_assert_stdout_eq_str("    Hello World");
}

Test(string, escape, .init = redirect_all_std)
{
    cr_assert(my_printf("%S", "\n") == 3);
}