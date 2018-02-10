# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/09 07:42:03 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./

NAME = test_ft_printf.exe

SRCS = main_test_ft_printf.c\
	   ft_printf.c\
	   special_char.c\
	   colors.c\
	   flags.c\
	   go_to_conv_flags.c\
	   additionnal_flags.c\
	   escape.c\
	   add_elem.c\
	   length_modifier_anm.c\
	   add_nb_mai.c\
	   error_code.c

OBJS = main_test_ft_printf.o\
	   ft_printf.o\
	   special_char.o\
	   colors.o\
	   flags.o\
	   go_to_conv_flags.o\
	   additionnal_flags.o\
	   escape.o\
	   add_elem.o\
	   length_modifier_anm.o\
	   add_nb_mai.o\
	   error_code.o

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(OBJS) -L./libft/ -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
