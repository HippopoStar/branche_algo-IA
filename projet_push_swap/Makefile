# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/02/21 11:48:56 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

HEAD = push_swap.h

NAME = push_swap

SRCS =	./srcs_push_swap/main_push_swap.c\
		./srcs_push_swap/main_checker.c\
		\
		./srcs_push_swap/ft_swap.c\
		./srcs_push_swap/ft_rotate.c\
		./srcs_push_swap/ft_push.c\
		./srcs_push_swap/ft_reverse_rotate.c\
		./srcs_push_swap/ps_parse.c\
		./srcs_push_swap/ps_display_error.c\
		./srcs_push_swap/ps_display_stacks.c\
		./srcs_push_swap/ps_sort_three.c\
		./srcs_push_swap/ps_sort_five.c\
		./srcs_push_swap/ps_sort_power_two.c\
		./srcs_push_swap/ps_position.c\
		./srcs_push_swap/ps_get_input.c\
		./srcs_push_swap/ps_apply_moves.c\
		./srcs_push_swap/ps_gotta_push.c\
		./srcs_push_swap/ps_is_ready_to_go.c\
		./srcs_push_swap/ps_get_options.c\
		./srcs_push_swap/ps_print_register.c

OBJS =	ft_swap.o\
		ft_rotate.o\
		ft_push.o\
		ft_reverse_rotate.o\
		ps_parse.o\
		ps_display_error.o\
		ps_display_stacks.o\
		ps_sort_three.o\
		ps_sort_five.o\
		ps_sort_power_two.o\
		ps_position.o\
		ps_get_input.o\
		ps_apply_moves.o\
		ps_gotta_push.o\
		ps_is_ready_to_go.o\
		ps_get_options.o\
		ps_print_register.o

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./libft/ main_push_swap.o $(OBJS) -lft
	gcc -o checker $(CFLAGS) -L./libft/ main_checker.o $(OBJS) -lft

clean:
	@make -C ./libft/ clean
	rm -f main_push_swap.o
	rm -f main_checker.o
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY	:				all clean fclean re
