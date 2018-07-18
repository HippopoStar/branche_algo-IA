#!/bin/sh
gcc -o test_printf.out -Wall -Wextra -Werror -I./libftprintf/includes/ main_printf.c -L./libftprintf/ -lftprintf
