/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:21:39 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 01:07:40 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include "common_functions.h"
# include <stdarg.h>
# include <stdint.h>

/*
** Correspondances concernant les conversions
**
** - de nombres :
** d	-> signed int
** hd	-> signed short int
** hhd	-> signed char
** ld	-> signed long int
** lld	-> signed long long int
** jd	-> intmax_t
** zd	-> ssize_t
** u	-> unsigned int
** hu	-> unsigned short int
** hhu	-> unsigned char
** lu	-> unsigned long int
** llu	-> unsigned long long int
** ju	-> uintmax_t
** zu	-> size_t
**
** - de caracteres :
** C	-> wint_t
** S	-> wchar *
**
** Domaines d'application des flags
** '+'	-> nombres signes
** ' '	-> nombres signes
** '#'	-> nombres non signes
** '0'	-> '-' est absent, la conversion concerne des caracteres
**                         absence de precision, conversion numerique
**
**
** Ordre d'application des flags
**
** - dans le cas d'une conversion concernant des caracteres
** 1. la precision '.'
** 2. la largeur minimum de champ
** 3. le flag '-'
** 4. le flag '0', le cas echeant
**
** - dans le cas d'une conversion concernant des nombres
** 1. anticiper le cas echeant de la place pour les flags '#', '+' ou ' '
** 2. la precision '.'
**    -> si la precision vaut 0 et le nombre vaut 0 egalement, ne pas l'afficher
** 3. la largeur minumum de champ
** 4. le flag '0', le cas echeant
**    -> les zeros vont se placer entre les champs supplementaires et le nombre
**    -> a ce stade-la, seul un signe '-' peut etre present devant le nombre
** 5. les flags '#', '+' ou ' '
** 6. le flag '-' (en tenant compte de la presence eventuelle du flag ' ')
*/

# define END_OF_COLOR				"\033[00m"
# define BLACK						"\033[30m"
# define RED						"\033[31m"
# define GREEN						"\033[32m"
# define YELLOW						"\033[33m"
# define BLUE						"\033[34m"
# define MAGENTA					"\033[35m"
# define CYAN						"\033[36m"
# define WHITE						"\033[37m"

# define PF_CONVERSION_SPECIFIERS	"sSpdDioOuUxXcCbB"
# define PF_FORMAT_SPECIFIERS		"hljz"
# define PF_FLAGS					"#0-+ "

# define PF_CHARACTERS_CONV_SPEC		"sScC"
# define PF_SIGNED_CONV_SPEC		"dDi"
# define PF_UNSIGNED_CONV_SPEC		"poOuUxXbB"

int		ft_printf(const char *format, ...);
size_t	pf_check_convers(const char *format);
size_t	pf_check_color(const char *format);
int		pf_convers(const char *format, va_list ap, t_list *mai);
int		pf_color(const char *format, t_list *mai);
int		pf_get_prec_and_spac(const char *format, size_t *prec, size_t *spac);
int		pf_is_flag_present(const char *format, char flag_char);
int		pf_characters_convers(const char *format, va_list ap, t_list *mai, const char *type);
int		pf_signed_convers(const char *format, va_list ap, t_list *mai, const char *type);
int		pf_unsigned_convers(const char *format, va_list ap, t_list *mai, const char *type);
int		pf_add_const_string_mai(const char *str, t_list *mai);

char	*pf_malloc_and_left_spaces(size_t spac, size_t length);
void	pf_deal_minus_sign_and_zero(const char *format, char *str, size_t keep);

void	pf_deal_zero(const char *format, char *str, size_t keep);
void	pf_deal_minus_sign(const char *format, char *str, size_t keep);

char	pf_jump_to_conv_spec(const char *format);
void	pf_apply_plus_sign(char *str);
void	pf_anticipate_plus_space(long long int n, size_t prec, size_t *spac);
void	pf_apply_sharp_mark(char *nbr_base, char conv_spec);
void	pf_anticipate_sharp_mark(unsigned long long int n, char conv_spec, size_t *prec);

#endif
