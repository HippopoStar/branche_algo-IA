/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/09 09:41:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define ulli unsigned long long int

typedef struct	s_pf
{
	size_t		len;
	char		*str;
	struct s_pf	*next;
}				t_pf;

typedef struct	s_pn
{
	char		c;
	struct s_pn	*next;
}				t_pn;

int				ft_printf(const char *format, ...);
void			aux_ft_printf(char *format, va_list ap, t_pf *cha);
void			read_pf(t_pf *cha);
void			read_and_free_pf(int *ret_val, t_pf *cha);
t_pf			*moove_cha(t_pf *cha);

void			add_char_mai(char c, t_pf *mai);
void			add_str_mai(char *str, ssize_t p_length, t_pf *mai);

int				special_char(char *c);
size_t			ft_putstr_un_sc(char *format, t_pf *mai);
size_t			ft_putstr_sc(char *format, va_list ap, t_pf *mai);

int				is_color(char *str);
size_t			colors(char *str, t_pf *mai);

size_t			flags(char *str, va_list ap, t_pf *mai);
size_t			conversion_flags(char *str, va_list ap, t_pf *mai);

void			additionnal_flags(char *str, size_t length, t_pf *mai);

ssize_t			go_to_conv_flags(char *str);
int				occurs(char c, char *str);

size_t			escape(char *str, t_pf *mai);

size_t			length_modifier_anm(va_list ap, char *c_s, t_pf *mai, ulli *nb);
void			fix_signed(va_list ap, size_t i, t_pf *mai, ulli *nb);
void			fix_unsigned(va_list ap, size_t i, ulli *nb);
size_t			skip_length_modifiers_and_conversion_specifier(char *str);

void			add_nb_mai(ulli nb, char *base, t_pf *mai, ssize_t mnoz);
void			fill_nb_bas(ulli l_n, t_pn *stock, t_pf *aux, ssize_t mnoz);
size_t			is_base_valid(char *base, t_pf *aux);
void			from_stock_to_string(t_pn *stock, t_pf *mai);

void			error_code(char *error_message);

#endif
