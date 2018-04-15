# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/04/15 18:32:54 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./includes/

NAME = libftprintf.a

SRCS = ./srcs_libft/ft_memset.c\
		./srcs_libft/ft_bzero.c\
		./srcs_libft/ft_memcpy.c\
		./srcs_libft/ft_memccpy.c\
		./srcs_libft/ft_memmove.c\
		./srcs_libft/ft_memchr.c\
		./srcs_libft/ft_memcmp.c\
		./srcs_libft/ft_strlen.c\
		./srcs_libft/ft_strdup.c\
		./srcs_libft/ft_strcpy.c\
		./srcs_libft/ft_strncpy.c\
		./srcs_libft/ft_strcat.c\
		./srcs_libft/ft_strncat.c\
		./srcs_libft/ft_strlcat.c\
		./srcs_libft/ft_strchr.c\
		./srcs_libft/ft_strrchr.c\
		./srcs_libft/ft_strstr.c\
		./srcs_libft/ft_strnstr.c\
		./srcs_libft/ft_strcmp.c\
		./srcs_libft/ft_strncmp.c\
		./srcs_libft/ft_atoi.c\
		./srcs_libft/ft_isalpha.c\
		./srcs_libft/ft_isdigit.c\
		./srcs_libft/ft_isalnum.c\
		./srcs_libft/ft_isascii.c\
		./srcs_libft/ft_isprint.c\
		./srcs_libft/ft_toupper.c\
		./srcs_libft/ft_tolower.c\
		\
		./srcs_libft/ft_memalloc.c\
		./srcs_libft/ft_memdel.c\
		./srcs_libft/ft_strnew.c\
		./srcs_libft/ft_strdel.c\
		./srcs_libft/ft_strclr.c\
		./srcs_libft/ft_striter.c\
		./srcs_libft/ft_striteri.c\
		./srcs_libft/ft_strmap.c\
		./srcs_libft/ft_strmapi.c\
		./srcs_libft/ft_strequ.c\
		./srcs_libft/ft_strnequ.c\
		./srcs_libft/ft_strsub.c\
		./srcs_libft/ft_strjoin.c\
		./srcs_libft/ft_strtrim.c\
		./srcs_libft/ft_strsplit.c\
		./srcs_libft/ft_itoa.c\
		./srcs_libft/ft_putchar.c\
		./srcs_libft/ft_putstr.c\
		./srcs_libft/ft_putendl.c\
		./srcs_libft/ft_putnbr.c\
		./srcs_libft/ft_putchar_fd.c\
		./srcs_libft/ft_putstr_fd.c\
		./srcs_libft/ft_putendl_fd.c\
		./srcs_libft/ft_putnbr_fd.c\
		\
		./srcs_libft/ft_lstnew.c\
		./srcs_libft/ft_lstdelone.c\
		./srcs_libft/ft_lstdel.c\
		./srcs_libft/ft_lstadd.c\
		./srcs_libft/ft_lstiter.c\
		./srcs_libft/ft_lstmap.c\
		\
		./srcs_libftprintf/ft_printf.c\
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

OBJS = ft_memset.o\
		ft_bzero.o\
		ft_memcpy.o\
		ft_memccpy.o\
		ft_memmove.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_strlen.o\
		ft_strdup.o\
		ft_strcpy.o\
		ft_strncpy.o\
		ft_strcat.o\
		ft_strncat.o\
		ft_strlcat.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strstr.o\
		ft_strnstr.o\
		ft_strcmp.o\
		ft_strncmp.o\
		ft_atoi.o\
		ft_isalpha.o\
		ft_isdigit.o\
		ft_isalnum.o\
		ft_isascii.o\
		ft_isprint.o\
		ft_toupper.o\
		ft_tolower.o\
		\
		ft_memalloc.o\
		ft_memdel.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strclr.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strsplit.o\
		ft_itoa.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_putendl.o\
		ft_putnbr.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		\
		ft_lstnew.o\
		ft_lstdelone.o\
		ft_lstdel.o\
		ft_lstadd.o\
		ft_lstiter.o\
		ft_lstmap.o\
		\
		ft_printf.o\
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
	gcc -c $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
