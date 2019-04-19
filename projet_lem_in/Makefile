# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/02/22 10:12:51 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

HEAD = lem_in.h

NAME = lem-in

SRCS = ./srcs_lem_in/main_lem_in.c\
		./srcs_lem_in/li_error.c\
		./srcs_lem_in/li_parse_input.c\
		./srcs_lem_in/ft_is_int.c\
		./srcs_lem_in/li_match_ants.c\
		./srcs_lem_in/li_match_rooms.c\
		./srcs_lem_in/li_allocate_map.c\
		./srcs_lem_in/li_match_pipes.c\
		./srcs_lem_in/li_print_map.c

OBJS = ./main_lem_in.o\
		./li_error.o\
		./li_parse_input.o\
		./ft_is_int.o\
		./li_match_ants.o\
		./li_match_rooms.o\
		./li_allocate_map.o\
		./li_match_pipes.o\
		./li_print_map.o

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
