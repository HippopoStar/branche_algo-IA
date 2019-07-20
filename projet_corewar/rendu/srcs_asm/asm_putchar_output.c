/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_putchar_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:30:52 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/08 17:30:54 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

int		asm_putchar_output(t_asm_data *data, char c)
{
	if (data->output_index < FT_MAX_CHAMP_LENGTH)
	{
		*(data->output + data->output_index) = c;
		(data->output_index)++;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putusint_output(t_asm_data *data, unsigned short int s)
{
	if (asm_putchar_output(data, (char)(s >> 8))
			&& asm_putchar_output(data, (char)s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		asm_putuint_output(t_asm_data *data, unsigned int u)
{
	if (asm_putchar_output(data, (char)(u >> 24))
			&& asm_putchar_output(data, (char)(u >> 16))
			&& asm_putchar_output(data, (char)(u >> 8))
			&& asm_putchar_output(data, (char)u))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
