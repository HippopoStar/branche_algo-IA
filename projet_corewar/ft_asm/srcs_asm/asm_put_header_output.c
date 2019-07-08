/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_put_header_output.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:30:01 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:30:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

static int	asm_put_magic_output(t_asm_data *data, t_header *h)
{
	if (data->output_index == 0
			&& asm_putuint_output(data, h->magic))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	asm_put_name_output(t_asm_data *data, t_header *h)
{
	size_t	i;

	i = 0;
	while (!(*(h->prog_name + i) == '\0'))
	{
		if (!asm_putchar_output(data, *(h->prog_name + i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	asm_put_prog_size_output(t_asm_data *data, t_header *h)
{
	if (asm_putuint_output(data, h->prog_size))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	asm_put_comment_output(t_asm_data *data, t_header *h)
{
	size_t	i;

	i = 0;
	while (!(*(h->comment + i) == '\0'))
	{
		if (!asm_putchar_output(data, *(h->comment + i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		asm_put_header_output(t_asm_data *data, t_header *h)
{
	if (asm_put_magic_output(data, h) && asm_put_name_output(data, h))
	{
		data->output_index = 4 + PROG_NAME_LENGTH + 4;
		if (asm_put_prog_size_output(data, h) && asm_put_comment_output(data, h))
		{
			return (1);
		}
	}
	return (0);
}
