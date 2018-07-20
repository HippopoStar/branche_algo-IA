#!/bin/sh
gcc -o test_widestring_to_string.out -Wall -Wextra -Werror -I./libftprintf/includes/ ./main_widestring_to_string.c -L./libftprintf/ -lftprintf
