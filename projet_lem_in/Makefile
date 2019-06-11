# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/06/11 19:05:56 by lcabanes         ###   ########.fr        #
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

LIBFT = ./libft/libft.a

NAME = lem-in

SRC_PATH = ./srcs_lem_in

SRC_NAME = main_lem_in.c\
			li_options.c\
			li_error.c\
			li_get_output.c\
			li_get_next_non_comment_line.c\
			li_parse_input.c\
			li_match_ants.c\
			li_match_room.c\
			li_allocate_map.c\
			li_match_pipe.c\
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

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# Allez savoir pourquoi, meme lorque '$(NAME)' existe deja,
# 'all' s'evertue a appeler la regle correspondante
all: $(NAME)

# L'appel de 'libft' permet d'actualiser '$(LIBFT)'
# afin qu'eventuellement '$(NAME)' se lance lors du prochain appel de 'make'

$(NAME): $(OBJ) $(LIBFT) | libft
	gcc -o $(NAME) $(LDFLAGS) $(OBJ) $(LDLIBS)

# Autre solution de creation du dossier '$(OBJ_PATH)' :
#	@mkdir -p $(OBJ_PATH) 2> /dev/null
# dans la dependance '$(OBJ_PATH)'
# Dans ce cas 'mkdir' est appele lors de la compilation de chaque fichier source

# Il est necessaire d'employer l'option '-o' de 'gcc' de la maniere qui suit
# pour que les fichiers objets se placent dans le repertoire '$(OBJ_PATH)'

# Par ailleurs il egalement necessaire de placer le '/' comme c'est la cas
# et de ne pas l'inclure dans dans la variable '$(OBJ_PATH)'
# car autrement allez savoir pourquoi la commande 'make re' revoie une erreur

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD) | $(OBJ_PATH)
	gcc -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(LIBFT): libft

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
