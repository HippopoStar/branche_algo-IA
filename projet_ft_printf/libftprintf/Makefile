# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/07/25 00:45:24 by lcabanes         ###   ########.fr        #
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
		./srcs_common_functions/get_next_line.c\
		./srcs_common_functions/get_next_line_backslash_zero.c\
		./srcs_common_functions/ft_putnbr_base.c\
		./srcs_common_functions/ft_split_whitespaces.c\
		./srcs_common_functions/ft_sqrt.c\
		./srcs_common_functions/ft_hypotenuse.c\
		./srcs_common_functions/ft_melt_colors.c\
		./srcs_common_functions/ft_break_color_down.c\
		./srcs_common_functions/ft_itoa_base.c\
		./srcs_common_functions/ft_lli_and_ulli_toa_base.c\
		./srcs_common_functions/ft_widestring_to_string.c\
		./srcs_common_functions/ft_strndup.c\
		\
		./srcs_libftprintf/ft_printf.c\
		./srcs_libftprintf/pf_check.c\
		./srcs_libftprintf/pf_color.c\
		./srcs_libftprintf/pf_convers.c\
		./srcs_libftprintf/pf_get_prec_and_spac.c\
		./srcs_libftprintf/pf_is_flag_present.c\
		./srcs_libftprintf/pf_characters_convers.c\
		./srcs_libftprintf/pf_deal_minus_sign_and_zero.c\
		./srcs_libftprintf/pf_signed_convers.c\
		./srcs_libftprintf/pf_unsigned_convers.c\
		./srcs_libftprintf/pf_sharp_plus_space.c\
		./srcs_libftprintf/pf_numeric_flags.c\
		./srcs_libftprintf/pf_add_const_string_mai.c

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
		get_next_line.o\
		get_next_line_backslash_zero.o\
		ft_putnbr_base.o\
		ft_split_whitespaces.o\
		ft_sqrt.o\
		ft_hypotenuse.o\
		ft_melt_colors.o\
		ft_break_color_down.o\
		ft_itoa_base.o\
		ft_lli_and_ulli_toa_base.o\
		ft_widestring_to_string.o\
		ft_strndup.o\
		\
		ft_printf.o\
		pf_check.o\
		pf_color.o\
		pf_convers.o\
		pf_get_prec_and_spac.o\
		pf_is_flag_present.o\
		pf_characters_convers.o\
		pf_deal_minus_sign_and_zero.o\
		pf_signed_convers.o\
		pf_unsigned_convers.o\
		pf_sharp_plus_space.o\
		pf_numeric_flags.o\
		pf_add_const_string_mai.o

all: $(NAME)

$(NAME): $(SRCS)
	gcc -c $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
