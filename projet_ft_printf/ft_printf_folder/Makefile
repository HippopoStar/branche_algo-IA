# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/03/22 01:53:41 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

NAME = libftprintf.a

SRCS = ./srcs_libftprintf/ft_printf.c\
	   ./srcs_libftprintf/special_char.c\
	   ./srcs_libftprintf/colors.c\
	   ./srcs_libftprintf/flags.c\
	   ./srcs_libftprintf/go_to_conv_flag.c\
	   ./srcs_libftprintf/occurs.c\
	   ./srcs_libftprintf/optionnal_flags.c\
	   ./srcs_libftprintf/detect_mnoz.c\
	   ./srcs_libftprintf/field_width_length.c\
	   ./srcs_libftprintf/escape.c\
	   ./srcs_libftprintf/add_elem.c\
	   ./srcs_libftprintf/global_char_format.c\
	   ./srcs_libftprintf/add_unicode_string_mai.c\
	   ./srcs_libftprintf/add_unicode_char_mai.c\
	   ./srcs_libftprintf/complete_uni_array.c\
	   ./srcs_libftprintf/length_modifier_anm.c\
	   ./srcs_libftprintf/aux_lm_anm.c\
	   ./srcs_libftprintf/specify_base.c\
	   ./srcs_libftprintf/obsolete_convers.c\
	   ./srcs_libftprintf/add_nb_mai.c\
	   ./srcs_libftprintf/p_padding.c\
	   ./srcs_libftprintf/error_code.c

OBJS = ft_printf.o\
	   special_char.o\
	   colors.o\
	   flags.o\
	   go_to_conv_flag.o\
	   occurs.o\
	   optionnal_flags.o\
	   detect_mnoz.o\
	   field_width_length.o\
	   escape.o\
	   add_elem.o\
	   global_char_format.o\
	   add_unicode_string_mai.o\
	   add_unicode_char_mai.o\
	   complete_uni_array.o\
	   length_modifier_anm.o\
	   aux_lm_anm.o\
	   specify_base.o\
	   obsolete_convers.o\
	   add_nb_mai.o\
	   p_padding.o\
	   error_code.o

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
