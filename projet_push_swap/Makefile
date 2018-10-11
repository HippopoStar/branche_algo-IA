# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/10/11 18:54:19 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

NAME = test_push_swap.exe

SRCS = main_test_push_swap.c\
		./srcs_push_swap/main_push_swap.c\
		./srcs_push_swap/main_checker.c\
		\
		./srcs_push_swap/ft_ps_swap.c\
		./srcs_push_swap/ft_ps_rotate.c\
		./srcs_push_swap/ft_ps_push.c\
		./srcs_push_swap/ft_ps_reverse_rotate.c\
		./srcs_push_swap/ft_ps_display_stacks.c\
		./srcs_push_swap/ft_ps_initialize_stacks.c\
		./srcs_push_swap/ft_ps_add_elem.c\
		./srcs_push_swap/ft_ps_parse_parameters.c\
		./srcs_push_swap/ft_ps_apply_moves.c\
		./srcs_push_swap/ft_ps_get_ref.c\
		./srcs_push_swap/ft_ps_check_doublons.c\
		./srcs_push_swap/ft_ps_check_order.c\
		./srcs_push_swap/ft_ps_free.c

OBJS = ft_ps_swap.o\
		ft_ps_rotate.o\
		ft_ps_push.o\
		ft_ps_reverse_rotate.o\
		ft_ps_display_stacks.o\
		ft_ps_initialize_stacks.o\
		ft_ps_add_elem.o\
		ft_ps_parse_parameters.o\
		ft_ps_apply_moves.o\
		ft_ps_get_ref.o\
		ft_ps_check_doublons.o\
		ft_ps_check_order.o\
		ft_ps_free.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./libft/ main_test_push_swap.o $(OBJS) -lft
	gcc -o push_swap $(CFLAGS) -L./libft/ main_push_swap.o $(OBJS) -lft
	gcc -o checker $(CFLAGS) -L./libft/ main_checker.o $(OBJS) -lft

clean:
	@make -C ./libft/ clean
	rm -f main_test_push_swap.o
	rm -f main_push_swap.o
	rm -f main_checker.o
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)
	rm -f push_swap
	rm -f checker

re: fclean all

.PHONY	:				all clean fclean re
