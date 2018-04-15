# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/04/15 14:58:50 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

NAME = libftprintf.a

SRCS = ./srcs_libftprintf/ft_printf.c\
	   ./srcs_libftprintf/pf_special_char.c\
	   ./srcs_libftprintf/pf_colors.c\
	   ./srcs_libftprintf/pf_flags.c\
	   ./srcs_libftprintf/pf_go_to_conv_flag.c\
	   ./srcs_libftprintf/pf_occurs.c\
	   ./srcs_libftprintf/pf_optionnal_flags.c\
	   ./srcs_libftprintf/pf_detect_mnoz.c\
	   ./srcs_libftprintf/pf_field_width_length.c\
	   ./srcs_libftprintf/pf_escape.c\
	   ./srcs_libftprintf/pf_add_elem.c\
	   ./srcs_libftprintf/pf_global_char_format.c\
	   ./srcs_libftprintf/pf_add_unicode_string_mai.c\
	   ./srcs_libftprintf/pf_add_unicode_char_mai.c\
	   ./srcs_libftprintf/pf_complete_uni_array.c\
	   ./srcs_libftprintf/pf_length_modifier_anm.c\
	   ./srcs_libftprintf/pf_aux_lm_anm.c\
	   ./srcs_libftprintf/pf_specify_base.c\
	   ./srcs_libftprintf/pf_obsolete_convers.c\
	   ./srcs_libftprintf/pf_add_nb_mai.c\
	   ./srcs_libftprintf/pf_p_padding.c\
	   ./srcs_libftprintf/pf_error_code.c

OBJS = ft_printf.o\
	   pf_special_char.o\
	   pf_colors.o\
	   pf_flags.o\
	   pf_go_to_conv_flag.o\
	   pf_occurs.o\
	   pf_optionnal_flags.o\
	   pf_detect_mnoz.o\
	   pf_field_width_length.o\
	   pf_escape.o\
	   pf_add_elem.o\
	   pf_global_char_format.o\
	   pf_add_unicode_string_mai.o\
	   pf_add_unicode_char_mai.o\
	   pf_complete_uni_array.o\
	   pf_length_modifier_anm.o\
	   pf_aux_lm_anm.o\
	   pf_specify_base.o\
	   pf_obsolete_convers.o\
	   pf_add_nb_mai.o\
	   pf_p_padding.o\
	   pf_error_code.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	libtool -static -o $(NAME) $(OBJS) ./libft/libft.a
	ranlib -f $(NAME)

clean:
	@make -C ./libft/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
