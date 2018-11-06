/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for the my_printf project.
*/

#include <stdio.h>
#include "my_printf.h"

int main(int argc, char **argv)
{
    int returned_val = my_printf("a%");

    printf("Returned val: %i\n", returned_val);
    my_putstr("--------------\n");
    returned_val = printf("a%");
    printf("Returned val: %i\n", returned_val);


    /*int returned_val = printf("Some tests: '%5i', '%hli', '%li'\n", 1, 0xFFFFF, 1);
    printf("Value-> %i\n", returned_val);*/
    return (0);
}