# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 17:42:57 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/16 20:42:49 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/

NAME = libftprintf.a

SRCS = ft_printf.c\
	   special_char.c\
	   colors.c\
	   flags.c\
	   go_to_conv_flag.c\
	   occurs.c\
	   optionnal_flags.c\
	   detect_mnoz.c\
	   field_width_length.c\
	   escape.c\
	   add_elem.c\
	   global_char_format.c\
	   add_unicode_string_mai.c\
	   add_unicode_char_mai.c\
	   complete_uni_array.c\
	   length_modifier_anm.c\
	   aux_lm_anm.c\
	   specify_base.c\
	   obsolete_convers.c\
	   add_nb_mai.c\
	   p_padding.c\
	   error_code.c

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
	gcc -c $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	rm -f test_ft_printf.exe
	gcc -o test_ft_printf.exe $(CFLAGS) main_test_ft_printf.c -L./ -lftprintf -L./libft/ -lft

.PHONY	:				all clean fclean re test
