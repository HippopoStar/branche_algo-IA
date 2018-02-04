/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:58:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 03:57:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*nou_mai(void)
{
	ft_putstr("nou_mai\n");

	t_pf	*nouveau;

	if (!(nouveau = (t_pf *)malloc(sizeof(t_pf))))
		error_code("Erreur d'alloc'");
	nouveau->len = 0;
	if (!(nouveau->str = (char *)malloc(sizeof(char))))
		exit(0);
	*(nouveau->str) = '\0';
	nouveau->next = NULL;
	return (nouveau);
}

void	read_and_free_pf(int *ret_val, t_pf *cha)
{
	ft_putstr("read_and_free_pf\n");

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
	ft_putstr("aux_ft_printf\n");

	char	c;
	size_t	i;
	size_t	retour;
	t_pf	*DEBUG;

	DEBUG = cha;
	i = 0;
	while ((c = *(format + i)) != '\0')
	{
		cha->next = nou_mai();
		cha = cha->next;
		if (special_char(c))
		{
			if (!(retour = ft_putstr_sc((format + i), ap, cha)))
			{
				add_char_mai(c, cha);
				i++;
			}
			cha->next = nou_mai();
			cha = cha->next;
			i = i + retour;
		}
		i = i + ft_putstr_un_sc((format + i), cha);
		read_pf(DEBUG->next);
	}
}

int		ft_printf(const char *format, ...)
{
	ft_putstr("ft_printf\n");

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
