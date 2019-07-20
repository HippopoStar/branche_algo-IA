/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:20:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/07/08 05:44:46 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <float.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <sysexits.h>
# include <unistd.h>
# include "libft.h"

# define ABS(a) (a < 0) ? -a : a

typedef struct	s_conversions
{
	long long			nbr;
	unsigned long long	unbr;
	long double			dnbr;
	unsigned char		c;
	char				*s;
}				t_conv;

typedef struct	s_printf_environment
{
	va_list		ap;
	size_t		i;
	size_t		r;
	size_t		e[128];
	t_conv		conv;
}				t_env;
/*
**	e['hh']		e[91]
**	e['ll']		e[93]
**	width		e['W']
**	precision	e['P']
**	lenght		e['N']
**	'#' marker	e['H']
*/

typedef void	(*t_fptr)(t_env *var, unsigned char b);

/*
**	src/ft_printf.c
*/
int				ft_printf(const char *format, ...);
/*
** int		parse(size_t *e, size_t *i, const char *format)
** size_t	*check_sizeeg(const char *format, size_t *i, size_t *e)
** void		pf_bzero(size_t *e, size_t len, t_conv *conv)
*/

/*
**	src/conversions.c
*/
void			is_bdi(size_t *e, long long *nbr, va_list ap, char b);
void			is_ouxp(size_t *e, unsigned long long *unbr, va_list ap,\
		char b);
void			is_csf(size_t *e, t_conv *conv, va_list ap, char b);

/*
** 	src/numbers.c
*/
void			numbers(t_env *var, unsigned char i);
int				hash(size_t *e, unsigned long long unbr, unsigned char b,\
		size_t *r);
/*
** void		dash(size_t *e, t_conv conv, unsigned char b, size_t *r)
** void		other(size_t *e, t_conv conv, unsigned char b, size_t *r)
** void		sign(size_t *e, long long nbr, unsigned char b, size_t *r)
*/

/*
**	src/binarys.c
*/
void			binarys(t_env *var, unsigned char b);
/*
** void		dash_4bin(size_t *e, long long nbr, size_t *r)
** void		other_4bin(size_t *e, long long nbr, size_t *r)
** void		pf_putbin(size_t *e, long long nbr, size_t *r)
*/

/*
**	src/floats.c
*/
void			floats(t_env *var, unsigned char b);
/*
** void		sign_4dbl(size_t *e, long double dnbr, size_t *r)
** void		pf_putdbl(size_t *e, long double dnbr, size_t *r)
*/

/*
**	src/strings
*/
void			strings(t_env *var, unsigned char b);
/*
** void		dash_4str(size_t *e, t_conv conv,  unsigned char b, size_t *r)
** void		other_4str(size_t *e, t_conv conv, unsigned char b, size_t *r)
*/

/*
**	lib/   by apparition order
*/
size_t			pf_atoi(const char *format, size_t i);
size_t			ft_nbrlen(ssize_t nbr);
unsigned char	pf_strchr(const char *s, int c);
size_t			pf_nbrlen(long long nbr, char b);
unsigned char	pf_unbrlen(unsigned long long unbr, char b);
unsigned char	get_base(char c);
void			pf_putnbr(long long nbr, size_t *r);
void			pf_putnbr_base(unsigned long long unbr, char b, size_t *e,\
	size_t *r);
void			pf_putchar(char c, size_t *r);
void			pf_putnchar(char c, ssize_t n, size_t *r);
void			pf_putnstr(const char *s, size_t n, size_t *r);

#endif
