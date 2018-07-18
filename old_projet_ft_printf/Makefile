# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/04/17 02:25:00 by lcabanes         ###   ########.fr        #
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

quick:
	@make -C ./libftprintf/ all
	gcc -o quick_test.out $(CFLAGS) -L./libftprintf/ quick_main.c -lftprintf
	@echo "\033[36m_____\033[00m"
	./quick_test.out
	@echo "\033[36m_____\033[00m"
	@make -C ./libftprintf/ fclean
	rm -f quick_test.out

.PHONY	:				all clean fclean re quick
