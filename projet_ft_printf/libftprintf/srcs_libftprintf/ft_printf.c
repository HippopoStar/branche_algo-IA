/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:37:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 08:05:39 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		pf_print(t_list *lst, int *ret_val)
{
	int	length;

	if (lst != NULL)
	{
		length = ft_strlen((char *)(lst->content));
		*ret_val = *ret_val + (int)length;
		pf_print(lst->next, ret_val);
		write(1, (char *)(lst->content), length);
		free((char *)(lst->content));
	}
}

static size_t	aux1_ft_printf(const char *format, va_list ap, t_list *mai)
{
	size_t	step;

	if ((step = pf_check_convers(format)) != 0)
	{
		pf_convers(format, ap, mai);
		return (step);
	}
	else if ((step = pf_check_color(format)) != 0)
	{
		pf_color(format, mai);
		return (step);
	}
	else
	{
		step = 0;
		while (*(format + step) != '\0'
				&& !(pf_check_convers(format + step)
					|| pf_check_color(format + step)))
		{
			step++;
		}
		mai->content = (void *)ft_strndup(format, step);
		return (step);
	}
}

static void		aux0_ft_printf(const char *format, va_list ap,\
													t_list *lst, int *ret_val)
{
	t_list	mai;

	if (*(format + 0) != '\0')
	{
		pf_print(lst, ret_val);
	}
	else
	{
		format = format + aux1_ft_printf(format, ap, &mai);
		mai.next = lst;
		aux0_ft_printf(format, ap, &mai, ret_val);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_val;

	if (format == NULL)
	{
		return (-1);
	}
	else
	{
		va_start(ap, format);
		ret_val = 0;
		aux0_ft_printf(format, ap, NULL, &ret_val);
		va_end(ap);
		return (ret_val);
	}
}
