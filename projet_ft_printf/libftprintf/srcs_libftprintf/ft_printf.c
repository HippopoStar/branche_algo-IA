/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 06:37:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/25 07:30:38 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	ft_putstr("Appel de \"pf_print\"\n");
*/

static void	pf_print(t_list *lst, int *ret_val)
{
	int	length;

	if (lst != NULL)
	{
		length = (lst->content_size == 0) ? ft_strlen((char *)(lst->content))
			: lst->content_size;
		*ret_val = *ret_val + (int)length;
		pf_print(lst->next, ret_val);
		write(1, (char *)(lst->content), length);
		free((char *)(lst->content));
	}
}

/*
**	ft_putstr("Appel de \"pf_step_forward\"\n");
*/

static int	pf_step_forward(const char *format, va_list ap, t_list *mai)
{
	size_t	step;

	mai->content_size = 0;
	if ((step = pf_check_convers(format)) != 0)
	{
		return (!(pf_convers(format + 1, ap, mai) == -1) ? (int)step : -1);
	}
	else if ((step = pf_check_color(format)) != 0)
	{
		return (!(pf_color(format, mai) == -1) ? (int)step : -1);
	}
	else
	{
		step = 0;
		while (*(format + step) != '\0'
				&& !(*(format + step) == '%'
					|| pf_check_color(format + step)))
		{
			step++;
		}
		return ((mai->content = (void *)ft_strndup(format, step)) != NULL ?
				(int)step : -1);
	}
}

/*
**	ft_putstr("Appel de \"aux0_ft_printf\"\n");
*/

static void	aux0_ft_printf(const char *format, va_list ap,\
													t_list *lst, int *ret_val)
{
	t_list	mai;
	int		step;

	if (*(format + 0) == '\0')
	{
		pf_print(lst, ret_val);
	}
	else
	{
		if (!((step = pf_step_forward(format, ap, &mai)) == -1))
		{
			format = format + (size_t)step;
			mai.next = lst;
			aux0_ft_printf(format, ap, &mai, ret_val);
		}
		else
		{
			*ret_val = -1;
			while (lst != NULL)
			{
				free((char *)(lst->content));
				lst = lst->next;
			}
		}
	}
}

/*
**	ft_putstr("Appel de \"ft_printf\"\n");
*/

int			ft_printf(const char *format, ...)
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
