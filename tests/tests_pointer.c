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
#include "../src/type/pointer.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pointer, simple_value, .init = redirect_all_std)
{
    int ***val = 500;
    char *str = malloc(sizeof(char) * 100);

    if (!str)
        return;
    sprintf(str, "%p", &val);
    cr_assert(my_printf("%p", &val) == 1);
    cr_assert_stdout_eq_str(str);
    free(str);
}