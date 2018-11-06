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
#include "../src/type/binary.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(binary, simple_value, .init = redirect_all_std)
{
    unsigned int un_int = 10;

    cr_assert(my_printf("%b", un_int) == 4);
    cr_assert_stdout_eq_str("1010");
}

Test(binary, big_val, .init = redirect_all_std)
{
    unsigned int un_int = 65535;

    cr_assert(my_printf("%b", un_int) == 16);
    cr_assert_stdout_eq_str("1111111111111111");
}