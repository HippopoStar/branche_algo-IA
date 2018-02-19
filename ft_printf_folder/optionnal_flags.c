/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionnal_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:41:28 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/19 18:20:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	insert_a_string_in_another(char *str, t_pf *mai, size_t posit)
{
	char	*tmp;
	size_t	size;

	tmp = mai->str;
	size = ft_strlen(str);
	if (!(mai->str = (char *)malloc(ft_strlen(tmp) + size + 1)))
		error_code("Erreur dans \"ft_printf\"");
	strncpy(mai->str, tmp, posit);
	strcpy((mai->str + posit), str);
	strcpy((mai->str + posit + size), (tmp + posit));
	free(tmp);
	mai->len = mai->len + size;
}

/*
** On renvoie le retour de atoi seulement s'il est positif car :
** - s'il est nul, c'est que le flag n'est pas suivi par un nombre
** - s'il est negatif, c'est que le flag est suivi du flag '-'
*/


size_t	find_flag(char c, char *str)
{
	size_t	i;
	char	flags[6];
	int		size;

	flags[0] = '#';
	flags[1] = '0';
	flags[2] = '-';
	flags[3] = ' ';
	flags[4] = '+';
	flags[5] = '.';
	i = 0;
	while (i < 5 && *(flags + i) != c)
	{
		i++;
	}
	if (i < 5)
	{
		flags[i] = flags[5];
	}
	flags[5] = '\0';
	i = 0;
	while (occurs(*(str + i), flags) || occurs(*(str + i), "123456789")
			|| (c == '0'
			&& i > 0 && occurs(*(str + i - 1), ".0123456789")))
	{
		i++;
	}
	if (*(str + i) == c)
	{
		return (((size = ft_atoi(str + i + 1)) > 0) ? (size_t)size : 1);
	}
	else
	{
		return (0);
	}
}

/*
** Remarque : on ne doit pas avoir de conflit entre l'utilisation du flag '#'
**            et celle du flag '0' malgre le critere "la chaine de caractere
**            representant le nombre ne doit pas debuter par '0' "
*/

void	optionnal_flags(char *str, t_pf *mai)
{
	char	co_sp;
	char	minus_sign;
	size_t	retour;

	co_sp = *(str + go_to_conv_flags(str));
	if (occurs(co_sp, "diouxXDOU"))
	{
		if (((retour = find_flag('+', str)) > 0) && occurs(co_sp, "diD"))
		{
			p_plus_sign(mai);
		}
		else if (((retour = find_flag(' ', str)) > 0) && occurs(co_sp, "diD"))
		{
			p_space(mai);
		}
		if ((retour = aux_p_padding(str, &minus_sign)) > 0
				&& (!(detect_mnoz(str)) || find_flag('.', str) > 0))
		{
			p_padding(retour, mai, minus_sign);
		}
		if (find_flag('#', str) > 0)
		{
			p_sharp_mark(co_sp, mai);
		}
	}
	else
	{
		if ((retour = point_flag_value(str)) > 0  && retour < ft_strlen(str))
		{
			*(mai->str + retour) = '\0';
			mai->len = retour;
		}
		if ((retour = aux_p_padding(str, &minus_sign)) > 0
				|| (retour = zero_flag_value(str)) > 0)
		{
			p_padding(retour, mai, minus_sign);
		}
		if (find_flag('0', str) > 0)
		{
			replace_left_spaces_by_zeros(mai);
		}
	}
}
