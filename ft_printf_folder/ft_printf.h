/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:41:32 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/01 14:18:13 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);
int			aux_ft_printf(char *format, va_list ap);

int			special_char(char c);
size_t		ft_putstr_un_sc(char *format);
size_t		ft_putstr_sc(char *format, va_list ap);

size_t		colors(char *str);

size_t		flags(char *str, va_list ap);

size_t		escape(char *str);

void		ft_putnbr_base(int nbr, char *base);
void		print_nbr_base(long int long_nbr, char *base, long int length_base);
long int	is_base_valid(char *base);

#endif
