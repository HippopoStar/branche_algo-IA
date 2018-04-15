# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/04/15 18:37:56 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./libftprintf/includes/

NAME = test_ft_printf.exe

SRCS = main_test_ft_printf.c

OBJS = main_test_ft_printf.o

all: $(NAME)

$(NAME):
	@make -C ./libftprintf/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./libftprintf/ $(OBJS) -lftprintf

clean:
	@make -C ./libftprintf/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./libftprintf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
