/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:09:19 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 08:00:29 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_FUNCTIONS_H
# define COMMON_FUNCTIONS_H

# include "libft.h"
# include <limits.h>
# include <wchar.h>

void			ft_putnbr_base(int nbr, char *base);
char			**ft_split_whitespaces(char *str);
int				ft_sqrt(int n);
int				ft_hypotenuse(int base, int hauteur);
int				ft_melt_colors(int red, int green, int blue);
void			ft_break_color_down(int *red, int *green, int *blue, int color);
/*
** Debut de 'ft_itoa_base' et ses derivees
*/
char			*aux0_ft_itoa_base(t_list *l_n, size_t i, t_list *lst);
char			*ft_itoa_base\
							(int n, const char *base, size_t prec, size_t spac);
char			*ft_llitoa_base\
				(long long int n, const char *base, size_t prec, size_t spac);
char			*ft_ullitoa_base\
		(unsigned long long int n, const char *base, size_t prec, size_t spac);
/*
** Fin de 'ft_itoa_base' et ses derivees
*/
char			*ft_widestring_to_string(wchar_t *widestring, size_t spac);
char			*ft_strndup(const char *str, size_t n);

#endif
