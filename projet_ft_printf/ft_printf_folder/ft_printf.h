/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/15 18:01:26 by lcabanes         ###   ########.fr       */
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

typedef struct		s_pf
{
	size_t			len;
	char			*str;
	struct s_pf		*next;
}					t_pf;

typedef struct		s_pf_pn
{
	char			c;
	struct s_pf_pn	*next;
}					t_pf_pn;

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);
void				pf_aux_ft_printf(char *format, va_list ap, t_pf *cha);
void				pf_read_pf(t_pf *cha);
void				pf_read_and_free_pf(int *ret_val, t_pf *cha);
t_pf				*pf_moove_cha(t_pf *cha);
/*
** add_elem.c
*/
void				pf_add_char_mai(char c, t_pf *mai);
void				pf_add_str_mai(char *str, ssize_t p_length, t_pf *mai);
/*
** special_char.c
*/
int					pf_special_char(char *c);
size_t				pf_ft_putstr_un_sc(char *format, t_pf *mai);
size_t				pf_ft_putstr_sc(char *format, va_list ap, t_pf *mai);
/*
** colors.c
*/
int					pf_is_color(char *str);
size_t				pf_colors(char *str, t_pf *mai);
/*
** A REVISER : flags.c
*/
size_t				pf_flags(char *str, va_list ap, t_pf *mai);
size_t				pf_lm_cs_flags(char *str, va_list ap, t_pf *mai,\
																ssize_t mnoz);
/*
** global_char_format.c
*/
size_t				pf_global_char_format(va_list ap, char *str, t_pf *mai);
void				pf_char_star_format(va_list ap, char c, t_pf *mai);
void				pf_char_format(va_list ap, char c, t_pf *mai);
/*
** add_unicode_string_mai.c
** VARIABLE_LENGTH_ARRAY dans 'aux_ausm'
*/
void				pf_add_unicode_string_mai(va_list ap, t_pf *mai);
void				pf_aux_ausm(wchar_t *uni_string, size_t i, t_pf *mai);
/*
** add_unicode_char_mai.c
*/
void				pf_add_unicode_char_mai(va_list ap, t_pf *mai);
void				pf_take_up_unicode_char(wint_t c, char unicode[5]);
void				pf_print_uni_mask(char mask[4][9]);
void				pf_from_unicode_array_to_string(char mask[4][9]);
/*
** complete_uni_array.c
*/
void				pf_cua(unsigned int nb, size_t nb_b, size_t nb_c,\
															char mask[4][9]);
size_t				pf_count_bits(unsigned int nb);
void				pf_fill_uni_mask(size_t nb_of_b, char mask[4][9],\
															size_t *nb_of_c);
void				pf_aux_fill_mask(size_t nb_of_char, char mask[4][9]);
void				pf_fill_uni_line(size_t position, char uni_line[9]);
/*
** obsolete_convers.c
*/
size_t				pf_obsolete_convers(va_list ap, char c, t_pf *mai,\
																ssize_t mnoz);
void				pf_replace_left_spaces_by_zeros(t_pf *mai);
/*
** A REVISER : optionnal_flags.c
*/
void				pf_optionnal_flags(char *str, t_pf *mai);
ssize_t				pf_find_flag(char c, char *str);
void				pf_insert_a_string_in_another(char *str, t_pf *mai,\
																size_t posit);
/*
** A REVISER : detect_mnoz.c
*/
ssize_t				pf_detect_mnoz(char *str);
ssize_t				pf_zero_flag_value(char *str);
ssize_t				pf_point_flag_value(char *str);
/*
** A REVISER : go_to_conv_flags.c
*/
size_t				pf_go_to_conv_flags(char *str);
size_t				pf_skip_padding(char *str);
size_t				pf_skip_length_modifiers(char *str);
size_t				pf_skip_leng_modi_and_conv_spec_for_integers(char *str);
/*
** field_width_length.c
*/
size_t				pf_field_width_length(char *str);
size_t				pf_aux_fwl(char *str);
/*
** occurs.c
*/
int					pf_occurs(char c, char *str);
/*
** p_padding.c
** VARIABLE_LENGTH_ARRAY dans 'p_padding'
*/
void				pf_p_sharp_mark(char c, t_pf *mai);
void				pf_p_padding(size_t retour, t_pf *mai, char minus_sign);
ssize_t				pf_aux_p_padding(char *str, char *minus_sign);
void				pf_p_plus_sign(t_pf *mai);
void				pf_p_space(t_pf *mai);
/*
** escape.c
*/
size_t				pf_escape(char *str, t_pf *mai);
/*
** length_modifier_anm.c
*/
size_t				pf_length_modifier_anm(va_list ap, char *c_s, t_pf *mai,\
																	ULLI *nb);
void				pf_fix_signed(va_list ap, size_t i, t_pf *mai, ULLI *nb);
void				pf_fix_unsigned(va_list ap, size_t i, ULLI *nb);
/*
** aux_lm_anm.c
*/
size_t				pf_aux_lm_anm(va_list ap, char *c_s, t_pf *mai, ULLI *nb);
void				pf_lm_h_d(va_list ap, size_t i, t_pf *mai, ULLI *nb);
void				pf_lm_h_u(va_list ap, size_t i, ULLI *nb);
void				pf_lm_j(va_list ap, char c, t_pf *mai, ULLI *nb);
void				pf_lm_z(va_list ap, char c, t_pf *mai, ULLI *nb);
/*
** specify_base.c
*/
void				pf_specify_base(char c, ULLI nb, t_pf *mai, ssize_t mnoz);
/*
** add_nb_mai.c
*/
void				pf_add_nb_mai(ULLI nb, char *base, t_pf *mai, ssize_t mnoz);
void				pf_fill_nb_bas(ULLI l_n, t_pf_pn *stock, t_pf *aux,\
																ssize_t mnoz);
size_t				pf_is_base_valid(char *base, t_pf *aux);
void				pf_from_stock_to_string(t_pf_pn *stock, t_pf *mai);
/*
** error_code.c
*/
void				pf_error_code(char *error_message);

#endif
