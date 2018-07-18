/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:21:39 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 15:07:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include "common_functions.h"
# include <stdarg.h>

/*
** Correspondances concernant les conversions
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
** - de caracteres :
** C	-> wint_t
** S	-> wchar *
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

# define PF_CONVERSION_SPECIFIERS	"sSpdDioOuUxXcC"
# define PF_FORMAT_SPECIFIERS		"hljz"
# define PF_FLAGS					"#0-+"

# define PF_CHAR_CONV_SPEC			"sScC"
# define PF_SIGNED_CONV_SPEC		"dDi"
# define PF_UNSIGNED_CONV_SPEC		"poOuUxX"

int		ft_printf(const char *format, ...);
size_t	pf_check_convers(const char *format);
size_t	pf_check_color(const char *format);
int		pf_convers(const char *format, va_list ap, t_list *mai);
int		pf_color(const char *format, t_list *mai);
int		pf_get_pres_and_spac(const char *format, size_t *prec, size_t *spac);
int		pf_is_flag_present(const char *format, char flag_char);

#endif
