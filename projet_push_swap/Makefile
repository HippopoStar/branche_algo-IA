# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/28 18:28:58 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

NAME = test_push_swap.exe

SRCS = main_test_push_swap.c\
		./srcs_push_swap/ft_ps_swap.c\
		./srcs_push_swap/ft_ps_rotate.c\
		./srcs_push_swap/ft_ps_push.c\
		./srcs_push_swap/ft_ps_reverse_rotate.c\
		./srcs_push_swap/ft_ps_display_stacks.c\
		./srcs_push_swap/ft_ps_initialize_stacks.c\
		./srcs_push_swap/ft_ps_add_elem.c

OBJS = main_test_push_swap.o\
		ft_ps_swap.o\
		ft_ps_rotate.o\
		ft_ps_push.o\
		ft_ps_reverse_rotate.o\
		ft_ps_display_stacks.o\
		ft_ps_initialize_stacks.o\
		ft_ps_add_elem.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./libft/ $(OBJS) -lft

clean:
	@make -C ./libft/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
