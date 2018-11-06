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
#include "../src/type/char.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(character, simple_value, .init = redirect_all_std)
{
    int un_int = 'a';

    cr_assert(my_printf("%c", un_int) == 1);
    cr_assert_stdout_eq_str("a");
}

Test(character, up_simple_value, .init = redirect_all_std)
{
    int un_int = 'A';

    cr_assert(my_printf("%c", un_int) == 1);
    cr_assert_stdout_eq_str("A");
}

Test(character, special_char, .init = redirect_all_std)
{
    cr_assert(my_printf("%%") == 1);
    cr_assert_stdout_eq_str("%");
}