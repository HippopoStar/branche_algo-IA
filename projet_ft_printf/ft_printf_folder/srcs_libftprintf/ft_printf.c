/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/20 17:51:34 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*moove_cha(t_pf *cha)
{
	t_pf	*nouveau;
	char	c;

	if (!(nouveau = (t_pf *)malloc(sizeof(t_pf))))
		error_code("Erreur d'alloc'");
	nouveau->len = 0;
	c = '\0';
	nouveau->str = &c;
	nouveau->next = NULL;
	cha->next = nouveau;
	return (nouveau);
}

void	read_and_free_pf(int *ret_val, t_pf *cha)
{
	t_pf	*tmp;

	while (cha != NULL)
	{
		*ret_val = *ret_val + cha->len;
		ft_putstr(cha->str);
		tmp = cha->next;
		free(cha);
		cha = tmp;
	}
}

void	read_pf(t_pf *cha)
{
	while (cha != NULL)
	{
		ft_putstr("-> ");
		ft_putstr(cha->str);
		ft_putchar('\n');
		cha = cha->next;
	}
}

void	aux_ft_printf(char *format, va_list ap, t_pf *cha)
{
	char	c;
	size_t	i;
	size_t	retour;

	cha = moove_cha(cha);
	i = 0;
	while ((c = *(format + i)) != '\0')
	{
		if (special_char(format + i))
		{
			if (!(retour = ft_putstr_sc((format + i), ap, cha)))
			{
				add_char_mai(c, cha);
				i++;
			}
			cha = moove_cha(cha);
			i = i + retour;
		}
		if ((retour = ft_putstr_un_sc((format + i), cha)) != 0)
			cha = moove_cha(cha);
		i = i + retour;
	}
}

/*
** On peut ajouter "read_pf(cha.next);"
** avant l'appel de "read_and_free_pf(&ret_val, cha.next);"
** dans la fonction "ft_printf"
** afin d'avoir un apercu de l'emploi de la liste chainee
*/

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_val;
	t_pf	cha;

	cha.next = NULL;
	va_start(ap, format);
	aux_ft_printf((char *)format, ap, &cha);
	va_end(ap);
	ret_val = 0;
	read_and_free_pf(&ret_val, cha.next);
	return (ret_val);
}
