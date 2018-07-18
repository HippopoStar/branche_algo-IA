/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/17 01:17:21 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*pf_moove_cha(t_pf *cha)
{
	t_pf	*nouveau;
	char	c;

	if (!(nouveau = (t_pf *)malloc(sizeof(t_pf))))
		pf_error_code("Erreur dans \"ft_printf.c\\moove_cha\"");
	nouveau->len = 0;
	c = '\0';
	nouveau->str = &c;
	nouveau->next = NULL;
	cha->next = nouveau;
	return (nouveau);
}

void	pf_read_and_free_pf(int *ret_val, t_pf *cha)
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

void	pf_read_pf(t_pf *cha)
{
	while (cha != NULL)
	{
		ft_putstr("-> ");
		ft_putstr(cha->str);
		ft_putchar('\n');
		cha = cha->next;
	}
}

void	pf_aux_ft_printf(char *format, va_list ap, t_pf *cha)
{
	char	c;
	size_t	i;
	size_t	retour;

	cha = pf_moove_cha(cha);
	i = 0;
	while ((c = *(format + i)) != '\0')
	{
		if (pf_special_char(format + i))
		{
			if (!(retour = pf_ft_putstr_sc((format + i), ap, cha)))
			{
				pf_add_char_mai(c, cha);
				i++;
			}
			cha = pf_moove_cha(cha);
			i = i + retour;
		}
		if ((retour = pf_ft_putstr_un_sc((format + i), cha)) != 0)
			cha = pf_moove_cha(cha);
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
	pf_aux_ft_printf((char *)format, ap, &cha);
	va_end(ap);
	ret_val = 0;
	pf_read_and_free_pf(&ret_val, cha.next);
	return (ret_val);
}
