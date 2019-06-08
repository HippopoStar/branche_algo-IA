# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/06/08 18:06:31 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =	-Wall -Wextra -Werror
CPPFLAGS =	-I./ -I./libft/includes/
LDFLAGS =	-L./libft/
LDLIBS =	-lft

#CFLAGS +=	-O1 -g -fsanitize=address \
#			-fno-omit-frame-pointer \
#			-fsanitize-address-use-after-scope

HEAD = ./lem_in.h

NAME = lem-in

SRC_PATH = ./srcs_lem_in/

SRC_NAME = main_lem_in.c\
			ft_is_int.c\
			ft_options.c\
			li_options.c\
			li_error.c\
			li_get_output.c\
			li_parse_input.c\
			li_match_ants.c\
			li_match_rooms.c\
			li_allocate_map.c\
			li_match_pipes.c\
			li_shorten_map_pipes.c\
			li_print_map.c\
			li_bellman_ford.c\
			li_bhandari.c\
			li_build_routes.c\
			li_remove_edges.c\
			li_get_routes_lengths.c\
			li_eval_routes.c\
			li_size_ttoa.c\
			li_move_ants.c\
			li_display_steps.c\
			li_memory_liberator.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD) libft
	gcc -o $(NAME) $(LDFLAGS) $(OBJ) $(LDLIBS)

# 'mkdir' est appele lors de la compilation de chaque fichier source
# en fichier objet, mais c'est une nessecite car une regle ne peut pas
# etre appelee par une autre regle autrement qu'en temps que dependance
# Il est necessaire d'employer l'option '-o' de 'gcc' pour que les fichiers
# objets se placent dans le repertoire '$(OBJ_PATH)'
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) > /dev/null
	gcc -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

libft:
	@make -C ./libft/ all

clean:
	@make -C ./libft/ clean
	rm -f $(OBJ)
	rm -df $(OBJ_PATH)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
