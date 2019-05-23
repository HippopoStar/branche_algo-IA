# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/05/23 22:50:22 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

HEAD = push_swap.h

NAME = push_swap
NAME_2 = checker

SRCS_PUSH_SWAP =	./srcs_push_swap/main_push_swap.c\
					./srcs_push_swap/ps_sort_three.c\
					./srcs_push_swap/ps_sort_five.c\
					./srcs_push_swap/ps_sort_power_two.c\
					./srcs_push_swap/ps_position.c\
					./srcs_push_swap/ps_gotta_push.c\
					./srcs_push_swap/ps_shorten.c\
					./srcs_push_swap/ps_aux_alamano_a.c\
					./srcs_push_swap/ps_alamano_a.c\
					./srcs_push_swap/ps_aux_alamano_b.c\
					./srcs_push_swap/ps_alamano_b.c\
					./srcs_push_swap/ps_sort_power_two_alamano.c\
					./srcs_push_swap/ps_do.c

SRCS_CHECKER =		./srcs_push_swap/main_checker.c\
					./srcs_push_swap/ps_get_input.c\
					./srcs_push_swap/ps_get_options.c\
					./srcs_push_swap/ps_print_register.c

SRCS_BOTH =			./srcs_push_swap/ft_swap.c\
					./srcs_push_swap/ft_rotate.c\
					./srcs_push_swap/ft_push.c\
					./srcs_push_swap/ft_reverse_rotate.c\
					./srcs_push_swap/ps_display_error.c\
					./srcs_push_swap/ps_display_stacks.c\
					./srcs_push_swap/ps_parse.c\
					./srcs_push_swap/ps_apply_moves.c\
					./srcs_push_swap/ps_is_ready_to_go.c

OBJS_PUSH_SWAP =	./main_push_swap.o\
					./ps_sort_three.o\
					./ps_sort_five.o\
					./ps_sort_power_two.o\
					./ps_position.o\
					./ps_gotta_push.o\
					./ps_shorten.o\
					./ps_aux_alamano_a.o\
					./ps_alamano_a.o\
					./ps_aux_alamano_b.o\
					./ps_alamano_b.o\
					./ps_sort_power_two_alamano.o\
					./ps_do.o

OBJS_CHECKER =		./main_checker.o\
					./ps_get_input.o\
					./ps_get_options.o\
					./ps_print_register.o

OBJS_BOTH =			./ft_swap.o\
					./ft_rotate.o\
					./ft_push.o\
					./ft_reverse_rotate.o\
					./ps_display_error.o\
					./ps_display_stacks.o\
					./ps_parse.o\
					./ps_apply_moves.o\
					./ps_is_ready_to_go.o

all: $(NAME) $(NAME_2)

$(NAME): $(SRCS_PUSH_SWAP) $(SRCS_BOTH) $(HEAD)
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS_PUSH_SWAP) $(SRCS_BOTH)
	gcc -o $(NAME) $(CFLAGS) -L./libft/ $(OBJS_PUSH_SWAP) $(OBJS_BOTH) -lft

$(NAME_2): $(SRCS_CHECKER) $(SRCS_BOTH) $(HEAD)
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS_CHECKER) $(SRCS_BOTH)
	gcc -o $(NAME_2) $(CFLAGS) -L./libft/ $(OBJS_CHECKER) $(OBJS_BOTH) -lft

clean:
	@make -C ./libft/ clean
	rm -f $(OBJS_PUSH_SWAP)
	rm -f $(OBJS_CHECKER)
	rm -f $(OBJS_BOTH)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)
	rm -f $(NAME_2)

re: fclean all

.PHONY	:				all clean fclean re
