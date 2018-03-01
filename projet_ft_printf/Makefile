# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/19 17:13:22 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ft_printf_folder/ -I./ft_printf_folder/libft/includes/

NAME = test_ft_printf.exe

SRCS = main_test_ft_printf.c

OBJS = main_test_ft_printf.o

all: $(NAME)

$(NAME):
	@make -C ./ft_printf_folder/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./ft_printf_folder/ -L./ft_printf_folder/libft/ $(OBJS) -lftprintf -lft

clean:
	@make -C ./ft_printf_folder/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./ft_printf_folder/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
