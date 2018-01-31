# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/01/31 18:07:14 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./

NAME = test_ft_printf.exe

SRCS = main_test_ft_printf.c\
	   ft_printf.c\
	   colors.c

OBJS = main_test_ft_printf.o\
	   ft_printf.o\
	   colors.o

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
