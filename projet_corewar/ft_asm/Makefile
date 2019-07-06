# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/07/01 12:10:55 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =	-Wall -Wextra -Werror
CPPFLAGS =	-I./ -I./libft/includes/
LDFLAGS =	-L./libft/
LDLIBS =	-lft

#CFLAGS +=	-O1 -g -fsanitize=address \
#			-fno-omit-frame-pointer \
#			-fsanitize-address-use-after-scope

HEAD = ./ft_asm.h\
			./op.h

LIBFT = ./libft/libft.a

NAME = asm

SRC_PATH = ./srcs_asm

SRC_NAME = main_asm.c\
			asm_initialize_data.c\
			asm_open_input_file.c\
			asm_compile.c\
			asm_putchar_output.c\
			asm_put_header_output.c\
			asm_parse_header.c\
			asm_create_output_file.c\
			asm_allocate_label_ref.c\
			asm_liberate_memory.c\
			asm_error_messages_01.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# Allez savoir pourquoi, meme lorque '$(NAME)' existe deja,
# 'all' s'evertue a appeler la regle correspondante
all: $(NAME)

# L'appel de 'libft' permet d'actualiser '$(LIBFT)'
# afin qu'eventuellement '$(NAME)' se lance lors du prochain appel de 'make'
#
# Les regles appelee par l'intermediaire d'autres regles s'executent quoi
# qu'il arrive, et quoi qu'il arrive les regles les appelant s'executent

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
