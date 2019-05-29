/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_get_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:33:27 by lcabanes          #+#    #+#             */
/*   Updated: 2019/05/29 18:21:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	li_print_output(t_data *data)
{
	write(1, (data->output).buff, (data->output).index);
	(data->output).index = 0;
}

void	li_get_output(t_data *data, const char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while ((data->output).index + i < LI_BUFF && i < len)
	{
		*((data->output).buff + (data->output).index + i) = *(str + i);
		i++;
	}
//	if ((data->output).index + i < LI_BUFF)
//	{
//		*((data->output).buff + (data->output).index + i) = '\n';
//		i++;
//	}
	(data->output).index = (data->output).index + i;
	if ((data->output).index == LI_BUFF)
	{
		li_print_output(data);
		li_get_output(data, str + i);
	}
}
