/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:45:20 by lcabanes          #+#    #+#             */
/*   Updated: 2019/02/09 19:56:02 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_get_options(int argc, char **argv, t_ps *data)
{
	char	c;

	data->verbose = 0;
	if (argc > 1 && *(*(argv + 1) + 0) == '-' && *(*(argv + 1) + 2) == '\0')
	{
		c = *(*(argv + 1) + 1);
		{
			if (c == 'h')
				ft_putstr("usage: ./checker [-hclv] $ARG\n");
			else if (c == 'c')
				data->verbose = 1;
			else if (c == 'l')
				data->verbose = 2;
			else if (c == 'v')
				data->verbose = 3;
		}
		if (ft_strchr("hclv", (int)c))
		{
			return (1);
		}
	}
	return (0);
}
