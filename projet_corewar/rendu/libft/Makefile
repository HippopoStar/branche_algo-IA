# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 20:42:11 by cmiran            #+#    #+#              #
#    Updated: 2019/07/21 00:42:00 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c\
      ft_atoi_base.c\
      ft_bzero.c\
	  ft_count_set_bits.c\
      ft_dupcstr.c\
      ft_freentab.c\
      ft_freetab.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isblank.c\
      ft_iscntrl.c\
      ft_isdigit.c\
      ft_isdigit_base.c\
      ft_isgraph.c\
      ft_islower.c\
      ft_islowhexa.c\
      ft_isprint.c\
	  ft_issign.c\
      ft_isspace.c\
      ft_isupper.c\
      ft_isupphexa.c\
      ft_isxdigit.c\
      ft_itoa.c\
      ft_itoa_base.c\
      ft_lstadd.c\
      ft_lstdel.c\
      ft_lstdelone.c\
      ft_lstiter.c\
      ft_lstmap.c\
      ft_lstnew.c\
      ft_memalloc.c\
      ft_memccpy.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memdel.c\
      ft_memmove.c\
      ft_memset.c\
      ft_print_memory.c\
      ft_putchar.c\
      ft_putchar_fd.c\
      ft_putendl.c\
      ft_putendl_fd.c\
      ft_putnbr.c\
      ft_putnbr_fd.c\
      ft_putstr.c\
      ft_putstr_fd.c\
      ft_puttab.c\
      ft_puttab_fd.c\
	  ft_realloc.c\
      ft_str_is_alpha.c\
      ft_str_is_blank.c\
      ft_str_is_lowercase.c\
      ft_str_is_numeric.c\
      ft_str_is_printable.c\
      ft_str_is_uppercase.c\
      ft_strcapitalize.c\
      ft_strcasecmp.c\
      ft_strcasestr.c\
      ft_strcat.c\
      ft_strcdup.c\
      ft_strchr.c\
      ft_strcjoin.c\
      ft_strclen.c\
      ft_strclr.c\
      ft_strcmp.c\
      ft_strcnew.c\
      ft_strcpy.c\
      ft_strdel.c\
      ft_strdup.c\
      ft_strequ.c\
      ft_striter.c\
      ft_striteri.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strlowcase.c\
      ft_strmap.c\
      ft_strmapi.c\
      ft_strncasecmp.c\
      ft_strncat.c\
      ft_strncmp.c\
      ft_strncpy.c\
      ft_strndup.c\
      ft_strnequ.c\
      ft_strnew.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strsplit.c\
      ft_strstr.c\
      ft_strsub.c\
      ft_strtrim.c\
      ft_strupcase.c\
	  ft_swap_int16.c\
	  ft_swap_int32.c\
	  ft_swap_uint16.c\
	  ft_swap_uint32.c\
      ft_tolower.c\
      ft_toupper.c\
      get_next_line.c\
	  ft_printf.c\
	  ft_nbrlen.c\
	  pf_atoi.c\
	  pf_binarys.c\
	  pf_conversions.c\
	  pf_floats.c\
	  pf_get_base.c\
	  pf_nbrlen.c\
	  pf_numbers.c\
	  pf_putchar.c\
	  pf_putnbr.c\
	  pf_putnbr_base.c\
	  pf_putnchar.c\
	  pf_putnstr.c\
	  pf_strchr.c\
	  pf_strings.c\
	  pf_unbrlen.c

INC= $(addprefix -I, ./includes/)

OBJDIR= .obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: $(NAME)

$(OBJDIR)/%.o: %.c includes/libft.h | $(OBJDIR)
	@echo "\033[0;33m      Compiling\033[0m" $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME) : $(OBJ)
	@echo "\033[0;32m  Creating library...\033[0m"
	@ar rc $@ $^
	@echo "\033[0;36m    Indexing library...\033[0m"
	@ranlib $@
	@ls | grep libft.a

analyzer:
	gcc -fsyntax-only $(CFLAGS) $(SRC)
	gcc --analyze $(CFLAGS) $(SRC)

clean:
	@echo "\033[0;31mDeleting\033[0m"	libft/$(OBJDIR)
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@echo "\033[0;31mDeleting\033[0m"	libft/$(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re analyzer
