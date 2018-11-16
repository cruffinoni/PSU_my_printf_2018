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

Test(string, acc, .init = redirect_all_std)
{
    cr_assert(my_printf("%12s", "Hello World") == 12);
    cr_assert_stdout_eq_str(" Hello World");
}

Test(string, acc_zero, .init = redirect_all_std)
{
    cr_assert(my_printf("%012s", "Hello World") == 12);
    cr_assert_stdout_eq_str(" Hello World");
}

Test(string, mix_acc_zero, .init = redirect_all_std)
{
    cr_assert(my_printf("%012.13s", "Hello World") == 12);
    cr_assert_stdout_eq_str(" Hello World");
}

Test(string, mix_acc_zero_neg, .init = redirect_all_std)
{
    cr_assert(my_printf("%-012.13s", "Hello World") == 12);
    cr_assert_stdout_eq_str("Hello World  ");
}

Test(string, all_extraf, .init = redirect_all_std)
{
    cr_assert(my_printf("%+#-012.13s", "Hello World") == 12);
    cr_assert_stdout_eq_str("Hello World  ");
}

Test(string, escape, .init = redirect_all_std)
{
    cr_assert(my_printf("%S", "\n") == 3);
}