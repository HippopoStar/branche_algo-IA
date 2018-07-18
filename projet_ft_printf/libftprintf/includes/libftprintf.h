/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:21:39 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 09:50:42 by lcabanes         ###   ########.fr       */
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

# define PF_CONVERSION_SPECIFIERS	"sSpdDioOuUxXcC"
# define PF_FORMAT_SPECIFIERS		"hljz"
# define PF_FLAGS					"#0-+"

int		ft_printf(const char *format, ...);
size_t	pf_check_convers(const char *format);
size_t	pf_check_color(const char *format);
int		pf_convers(const char *format, va_list ap, t_list *mai);
int		pf_color(const char *format, t_list *mai);

#endif
