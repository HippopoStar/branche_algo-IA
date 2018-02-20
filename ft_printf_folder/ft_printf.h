/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/20 17:03:57 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <string.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

# define ULLI unsigned long long int
# define OPTIONNAL_FLAGS "#0-+ ."
# define LENGTH_MODIFIERS "hljz"
# define CONVERSION_SPECIFIERS "sSpdDioOuUxXcC"
# define INTEGER_CS "dDioOuUxX"
# define CHARACTER_CS "sScC"

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

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
void			aux_ft_printf(char *format, va_list ap, t_pf *cha);
void			read_pf(t_pf *cha);
void			read_and_free_pf(int *ret_val, t_pf *cha);
t_pf			*moove_cha(t_pf *cha);
/*
** add_elem.c
*/
void			add_char_mai(char c, t_pf *mai);
void			add_str_mai(char *str, ssize_t p_length, t_pf *mai);
/*
** special_char.c
*/
int				special_char(char *c);
size_t			ft_putstr_un_sc(char *format, t_pf *mai);
size_t			ft_putstr_sc(char *format, va_list ap, t_pf *mai);
/*
** colors.c
*/
int				is_color(char *str);
size_t			colors(char *str, t_pf *mai);
/*
** A REVISER : flags.c
*/
size_t			flags(char *str, va_list ap, t_pf *mai);
size_t			lm_cs_flags(char *str, va_list ap, t_pf *mai, ssize_t mnoz);
/*
** global_char_format.c
*/
size_t			global_char_format(va_list ap, char *str, t_pf *mai);
void			char_star_format(va_list ap, char c, t_pf *mai);
void			char_format(va_list ap, char c, t_pf *mai);
/*
** add_unicode_string_mai.c
*/
void			add_unicode_string_mai(va_list ap, t_pf *mai);
void			aux_ausm(wchar_t *uni_string, size_t i, t_pf *mai);
/*
** add_unicode_char_mai.c
*/
void			add_unicode_char_mai(va_list ap, t_pf *mai);
void			take_up_unicode_char(wint_t c, char unicode[5]);
void			print_uni_mask(char mask[4][9]);
void			from_unicode_array_to_string(char mask[4][9]);
/*
** complete_uni_array.c
*/
void			cua(unsigned int nb, size_t nb_b, size_t nb_c, char mask[4][9]);
size_t			count_bits(unsigned int nb);
void			fill_uni_mask(size_t nb_of_b, char mask[4][9], size_t *nb_of_c);
void			aux_fill_mask(size_t nb_of_char, char mask[4][9]);
void			fill_uni_line(size_t position, char uni_line[9]);
/*
** obsolete_convers.c
*/
size_t			obsolete_convers(va_list ap, char c, t_pf *mai, ssize_t mnoz);
void			replace_left_spaces_by_zeros(t_pf *mai);
/*
** A REVISER : optionnal_flags.c
*/
void			optionnal_flags(char *str, t_pf *mai);
ssize_t			find_flag(char c, char *str);
void			insert_a_string_in_another(char *str, t_pf *mai, size_t posit);
/*
** A REVISER : detect_mnoz.c
*/
ssize_t			detect_mnoz(char *str);
ssize_t			zero_flag_value(char *str);
ssize_t			point_flag_value(char *str);
/*
** A REVISER : go_to_conv_flags.c
*/
size_t			go_to_conv_flags(char *str);
size_t			skip_padding(char *str);
size_t			skip_length_modifiers(char *str);
size_t			skip_leng_modi_and_conv_spec_for_integers(char *str);
/*
** field_width_length.c
*/
size_t			field_width_length(char *str);
size_t			aux_fwl(char *str);
/*
** occurs.c
*/
int				occurs(char c, char *str);
/*
** p_padding.c
*/
void			p_sharp_mark(char c, t_pf *mai);
void			p_padding(size_t retour, t_pf *mai, char minus_sign);
ssize_t			aux_p_padding(char *str, char *minus_sign);
void			p_plus_sign(t_pf *mai);
void			p_space(t_pf *mai);
/*
** escape.c
*/
size_t			escape(char *str, t_pf *mai);
/*
** length_modifier_anm.c
*/
size_t			length_modifier_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb);
void			fix_signed(va_list ap, size_t i, t_pf *mai, ULLI *nb);
void			fix_unsigned(va_list ap, size_t i, ULLI *nb);
/*
** aux_lm_anm.c
*/
size_t			aux_lm_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb);
void			lm_h_d(va_list ap, size_t i, t_pf *mai, ULLI *nb);
void			lm_h_u(va_list ap, size_t i, ULLI *nb);
void			lm_j(va_list ap, char c, t_pf *mai, ULLI *nb);
void			lm_z(va_list ap, char c, t_pf *mai, ULLI *nb);
/*
** specify_base.c
*/
void			specify_base(char c, ULLI nb, t_pf *mai, ssize_t mnoz);
/*
** add_nb_mai.c
*/
void			add_nb_mai(ULLI nb, char *base, t_pf *mai, ssize_t mnoz);
void			fill_nb_bas(ULLI l_n, t_pn *stock, t_pf *aux, ssize_t mnoz);
size_t			is_base_valid(char *base, t_pf *aux);
void			from_stock_to_string(t_pn *stock, t_pf *mai);
/*
** error_code.c
*/
void			error_code(char *error_message);

#endif
