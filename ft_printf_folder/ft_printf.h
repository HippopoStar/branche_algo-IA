/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 00:21:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_pf
{
	size_t		len;
	char		*str;
	struct s_pf	*next;
}					t_pf;

typedef struct		s_pn
{
	char		c;
	struct s_pn	*next;
}					t_pn;

int				ft_printf(const char *format, ...);
int				aux_ft_printf(char *format, va_list ap);

int				special_char(char c);
size_t			ft_putstr_un_sc(char *format);
size_t			ft_putstr_sc(char *format, va_list ap);

size_t			colors(char *str);

size_t			flags(char *str, va_list ap);

size_t			escape(char *str);

void			ft_putnbr_base(int nbr, char *base, t_pf *mai, ssize_t mnod);
void			fill_nbr_base(long int l_n, t_pn *stock, t_pf *aux, ssize_t mnod);
size_t			is_base_valid(char *base, t_pf *aux);
t_pf			*from_stock_to_string(t_pn *stock);

void			error_code(char *error_message);

#endif
