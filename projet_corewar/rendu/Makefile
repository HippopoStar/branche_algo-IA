# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/07/19 11:41:26 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =	-Wall -Wextra -Werror
CPPFLAGS =	-I./includes/ -I./libft/includes/
LDFLAGS =	-L./libft/
LDLIBS =	-lft

#CFLAGS +=	-O1 -g -fsanitize=address \
#			-fno-omit-frame-pointer \
#			-fsanitize-address-use-after-scope

HEAD = ./includes/op.h
HEAD1 = $(HEAD) ./includes/corewar.h
HEAD2 = $(HEAD) ./includes/ft_asm.h

LIBFT = ./libft/libft.a

NAME1 = corewar
NAME2 = asm

SRC1_PATH = ./srcs_corewar
SRC2_PATH = ./srcs_asm

SRC1_NAME = add.c\
			aff.c\
			and.c\
			champion.c\
			decode.c\
			exit.c\
			fork.c\
			init.c\
			input.c\
			ld.c\
			ldi.c\
			lfork.c\
			live.c\
			lld.c\
			lldi.c\
			main.c\
			or.c\
			outputs.c\
			play.c\
			process.c\
			st.c\
			sti.c\
			sub.c\
			tools.c\
			xor.c\
			zjmp.c

SRC2_NAME = main_asm.c\
			asm_initialize_data.c\
			asm_open_input_file.c\
			asm_compile.c\
			asm_putchar_output.c\
			asm_put_header_output.c\
			asm_parse_header.c\
			asm_get_quote.c\
			asm_get_label_declaration.c\
			asm_parse_prog.c\
			asm_parse_line.c\
			asm_parse_instruction.c\
			asm_parse_inst_arg.c\
			asm_get_inst_op_code.c\
			asm_inst_arg_types.c\
			asm_parse_arg_types_01.c\
			asm_parse_arg_types_02.c\
			asm_check_inst_args.c\
			asm_put_inst_prog.c\
			asm_putchar_prog.c\
			asm_put_prog_output.c\
			asm_skip_spacing_chars.c\
			asm_gnl.c\
			asm_create_output_file.c\
			asm_allocate_label_ref.c\
			asm_liberate_memory.c\
			asm_ft_atoi.c\
			asm_error_messages_01.c\
			asm_error_messages_02.c\
			asm_error_messages_03.c\
			asm_error_messages_04.c\
			asm_error_messages_05.c\
			asm_warning_messages.c

SRC1 = $(addprefix $(SRC1_PATH)/,$(SRC1_NAME))
SRC2 = $(addprefix $(SRC2_PATH)/,$(SRC2_NAME))

OBJ1_PATH = ./objs_corewar
OBJ2_PATH = ./objs_asm

OBJ1_NAME = $(SRC1_NAME:.c=.o)
OBJ2_NAME = $(SRC2_NAME:.c=.o)

OBJ1 = $(addprefix $(OBJ1_PATH)/,$(OBJ1_NAME))
OBJ2 = $(addprefix $(OBJ2_PATH)/,$(OBJ2_NAME))

# Allez savoir pourquoi, meme lorque '$(NAME)' existe deja,
# 'all' s'evertue a appeler la regle correspondante
all: $(NAME1) $(NAME2)

# L'appel de 'libft' permet d'actualiser '$(LIBFT)'
# afin qu'eventuellement '$(NAME)' se lance lors du prochain appel de 'make'
#
# Les regles appelee par l'intermediaire d'autres regles s'executent quoi
# qu'il arrive, et quoi qu'il arrive les regles les appelant s'executent

$(NAME1): $(OBJ1) $(LIBFT) | libft
	gcc -o $(NAME1) $(LDFLAGS) $(OBJ1) $(LDLIBS)

$(NAME2): $(OBJ2) $(LIBFT) | libft
	gcc -o $(NAME2) $(LDFLAGS) $(OBJ2) $(LDLIBS)

# Autre solution de creation du dossier '$(OBJ_PATH)' :
#	@mkdir -p $(OBJ_PATH) 2> /dev/null
# dans la dependance '$(OBJ_PATH)'
# Dans ce cas 'mkdir' est appele lors de la compilation de chaque fichier source

# Il est necessaire d'employer l'option '-o' de 'gcc' de la maniere qui suit
# pour que les fichiers objets se placent dans le repertoire '$(OBJ_PATH)'

# Par ailleurs il egalement necessaire de placer le '/' comme c'est la cas
# et de ne pas l'inclure dans dans la variable '$(OBJ_PATH)'
# car autrement allez savoir pourquoi la commande 'make re' revoie une erreur

$(OBJ1_PATH)/%.o: $(SRC1_PATH)/%.c $(HEAD1) | $(OBJ1_PATH)
	gcc -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(OBJ2_PATH)/%.o: $(SRC2_PATH)/%.c $(HEAD2) | $(OBJ2_PATH)
	gcc -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(OBJ1_PATH):
	mkdir $(OBJ1_PATH)

$(OBJ2_PATH):
	mkdir $(OBJ2_PATH)

$(LIBFT): libft

libft:
	@make -C ./libft/ all

clean:
	@make -C ./libft/ clean
	rm -f $(OBJ1) $(OBJ2)
	rm -df $(OBJ1_PATH) $(OBJ2_PATH)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re libft $(NAME1) $(NAME2)
