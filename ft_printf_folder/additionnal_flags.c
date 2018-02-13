/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:03:16 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/13 09:18:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	detect_mnoz(char *str)
{
	size_t	retour;

	if ((retour = find_flag('0', str)) > 0
		&& find_flag('.', str) == 0 && find_flag('-', str) == 0)
	{
		return ((ssize_t)retour);
	}
	else
	{
		return (0);
	}
}

void	insert_a_string_in_another(char *str, t_pf *mai, size_t posit)
{
	char	*tmp;
	size_t	size;

	tmp = mai->str;
	size = ft_strlen(str);
	if (!(mai->str = (char *)malloc(ft_strlen(tmp) + size + 1)))
		error_code("Erreur dans \"ft_printf\"");
	strncpy(mai->str, tmp, posit + 1);
	strcpy((mai->str + posit), str);
	strcpy((mai->str + posit + size), (tmp + posit));
	free(tmp);
	mai->len = mai->len + size;
}

size_t	go_to_conv_flags(char *str)
{
	size_t	i;

	i = 0;
	i = i + skip_padding(str + i);
	i = i + skip_length_modifiers_and_conversion_specifier(str + i);
	i = i - 1;
	return (i);
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
	while (i < 6 && *(flags + i) != c)
	{
		i++;
	}
	if (i < 5)
	{
		flags[i] = flags[5];
	}
	flags[5] = '\0';
	i = 0;
	while (occurs(*(str + i), flags) == 1)
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

void	additionnal_flags(char *str, size_t length, t_pf *mai)
{
	char	c_v;
	size_t	retour;

	(void)mai;
	(void)length;

	c_v = *(str + go_to_conv_flags(str));
	if (find_flag('#', str) > 0)
	{
		p_sharp_mark(c_v, mai);
	}
	if (find_flag('-', str) > 0)
	{

	}
	if ((retour = find_flag('+', str)) > 0)
	{

	}
	else if ((retour = find_flag(' ', str)) > 0)
	{

	}
}
