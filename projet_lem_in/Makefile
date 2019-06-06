# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/06/05 20:38:22 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/
#CFLAGS	+=		-O1 -g -fsanitize=address \
#				-fno-omit-frame-pointer \
#				-fsanitize-address-use-after-scope

HEAD = lem_in.h

NAME = lem-in

SRCS = ./srcs_lem_in/main_lem_in.c\
		./srcs_lem_in/li_error.c\
		./srcs_lem_in/li_get_output.c\
		./srcs_lem_in/li_parse_input.c\
		./srcs_lem_in/ft_is_int.c\
		./srcs_lem_in/li_match_ants.c\
		./srcs_lem_in/li_match_rooms.c\
		./srcs_lem_in/li_allocate_map.c\
		./srcs_lem_in/li_match_pipes.c\
		./srcs_lem_in/li_shorten_map_pipes.c\
		./srcs_lem_in/li_print_map.c\
		./srcs_lem_in/li_bellman_ford.c\
		./srcs_lem_in/li_bhandari.c\
		./srcs_lem_in/li_build_routes.c\
		./srcs_lem_in/li_remove_edges.c\
		./srcs_lem_in/li_get_routes_lengths.c\
		./srcs_lem_in/li_eval_routes.c\
		./srcs_lem_in/li_size_ttoa.c\
		./srcs_lem_in/li_move_ants.c\
		./srcs_lem_in/li_memory_liberator.c

OBJS = ./main_lem_in.o\
		./li_error.o\
		./li_get_output.o\
		./li_parse_input.o\
		./ft_is_int.o\
		./li_match_ants.o\
		./li_match_rooms.o\
		./li_allocate_map.o\
		./li_match_pipes.o\
		./li_shorten_map_pipes.o\
		./li_print_map.o\
		./li_bellman_ford.o\
		./li_bhandari.o\
		./li_build_routes.o\
		./li_remove_edges.o\
		./li_get_routes_lengths.o\
		./li_eval_routes.o\
		./li_size_ttoa.o\
		./li_move_ants.o\
		./li_memory_liberator.o

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
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
